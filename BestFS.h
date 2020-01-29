//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_BESTFS_H
#define UNTITLED_BESTFS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include "Searchable.h"
#include "Searcher.h"
#include "State.h"
#include "CostComparator.h"

using namespace std;

template <class T, class S>
class BestFS: public Searcher<T, S>{
private:
    priority_queue<State<T>> open;

public:

    vector<State<T>*> openList;

    set<State<T>*> closed ;

    virtual State<T>* popFromOpen() {
        State<T>* temp = openList.front();
        openList.pop();
        return temp;
    }
/*
    bool find(State<T> *state,priority_queue<State<T>> queue )  {
       std::  queue<State<T>> temp;
        for (State<T>* state : queue) {
            if (queue.top() ==
                return true;
        }
        return false;
    }*/

    vector<State<T>*> backTrace(State<T> *s) {
        vector<State<T> *> backTracevector;
        State<T>* state = s;
        ///enter all the back Trace to the vector
        while (state->getCameFrom() != nullptr) {
            backTracevector.insert(backTracevector.begin(), s);
            state = state->getCameFrom();
        }
        ///
        if (backTracevector.empty()) {
            return backTracevector;
        }
        //return all back trace
        backTracevector.insert(backTracevector.begin(), s);
        return backTracevector;
    }


    virtual bool isExistQueue(State<T>* state, priority_queue<State<T>> queue ) {
        vector<State<T>*> states;
        State<T> *tempState;
        bool exist = false;

        // pop all states to a vector and checking if the state exists in pq
        while (!openList.empty()) {
            tempState = popFromOpen();
            states.push_back(tempState);
        }
        // check if the state exists in the vector
        for (int i = 0; i < states.size(); ++i) {
            pushToOpen(states[i]);
            if (states[i] == state) {
                exist = true;
            }
        }
        return exist;
    }


    virtual vector<State<T>> search (const Searchable<T>& searchable) {
        /*     this->evaluatedNodes = 0;
     /***

             State<T> *goal = searchable->getGoalState();

             open.push(searchable.getInitialState());
             set<State<T>*> closed;

             while(!open.empty())
             {
                 this->getNumberOfNodesEvaluated()++;

                 State<T> best = open.pop();
             //*    closed.insert(&best);

                 if(best == searchable.getGoalState())
                 {
                     vector<State<T> *> output = this->backTrace(searchable->getInitialState(), best);
                     this->clearAll(output,&open);
                     return output;
                 }

                     vector<State<T>> successorts = searchable.getAllPossibleStates(best);

                     for(int i = 0; i < successorts.size(); i++)
                     {
                        if(closed.count(&successorts[i]) == 0 && !isExistVector(&successorts[i], open)){
                            open.push(successorts[i]);

                        }else if(!isExistQueue(&successorts[i], open)){
                           State<T> *item = find(&successors[i],open)
                        }
                     }



                     }


             }*/
            State<T> *curr = searchable.getInitialState();
            open.insert(curr);
            curr->setCameFrom(nullptr);

            while (!open.empty()) {
                curr = this->popFromOpen(open);
                closed.insert(curr);
                if (curr == searchable->getGoalState()) {
                    break;
                }

                vector<State<T> *> successors = searchable->getAllPossibleStates(curr);
                for (State<T> *succ : successors) {
                    // Ignoring walls
                    if (succ->getCost() < 0) {
                        continue;
                    }
                    if (closed.find(succ) != closed.end()) {
                        continue;
                    }
                    // If 'succ' isn't in any of the lists - update it and add to 'open'
                    if (open.find(succ) == open.end()) {
                        succ->setCameFrom(curr);
                        succ->setCost(succ->getCost() + curr->getCost());
                        open.insert(succ);
                        continue;
                    }
                    // If there is a better path - update cost
                    double cost = this->costBetweenNodes(curr, succ);
                    if (cost < succ->getCost()) {
                        succ->setCost(cost);

                        // If it's a new path
                        if (succ->getCameFrom() != curr) {
                            succ->setCameFrom(curr);
                            // It's the same path as before - remove the node and insert back to update priority
                        } else {
                            open.erase(succ);
                            open.insert(succ);
                        }
                    }
                }
            }
            return backtrace(searchable->getGoalState());
    }
    /*virtual void clearAll(vector<State<T> *> output, ) {
        State<T> *temp;
        while (!DB->emptyOpen()) {
            State<T> * temp =DB->popFromOpen();
            if(!DB->isExistVector(temp)){
                delete (temp);
            }
        }
        while (!DB->emptyClosed()) {

            temp = DB->popFromClosed();

            for (int i = 0; i < output.size(); i++) {
                if (output[i] == temp) {
                    break;
                }
                if (i == output.size() - 1) {
                    delete (temp);
                }
            }

        }*/




    };




#endif //UNTITLED_BESTFS_H

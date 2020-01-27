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
#

using namespace std;

template <class T, class S>
class BestFS: public Searcher<T, S>{
private:
    priority_queue<State<T>> open;

public:

    vector<State<T>*> openList;

    set<State<T>*> closed ;


    virtual vector<State<T>> search (const Searchable<T>& searchable) {
        this->evaluatedNodes = 0;


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
            else{
                vector<State<T>> successorts = searchable.getAllPossibleStates(best);

                for(int i = 0; i < successorts.size(); i++)
                {
//                    if(closed.count(&successorts[i]) == 0 && open.){

                    }
                }
            }
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

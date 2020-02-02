//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#include "Searchable.h"
#include "Searcher.h"
#include "State.h"
#include <map>

using namespace std;

template <class T>
class BFS: public Searcher<T> {

    vector<State<T>> search (const Searchable<T>& searchable){
        map<State<T>, bool> visited;
        map<State<T>, State<T>> parents;
        queue<State<T>> stateQueue;
        vector<State<T>> solutionStateList;

        stateQueue.push(searchable.getInitialState());
        visited[searchable.getInitialState()] = true;

        while(!stateQueue.empty()) {
            State<T> curState = stateQueue.front();
            stateQueue.pop();
         //orig here visiteed

            if ( curState != searchable.getGoalState()) {
                vector<State<T>> possibleStates = searchable.getAllPossibleStates(curState);

                for (int i = 0; i < possibleStates.size(); i++) {
                    State<T> stateFromList = possibleStates[i];
                    if (visited.count(stateFromList) == 0) {
                        visited[stateFromList] = true;
                        stateQueue.push(stateFromList);
                        parents[stateFromList] = curState;
                    }
                }
            } else {
                State<T>& stateToAdd = curState;

                while (parents.count(stateToAdd) != 0) {
                    solutionStateList.insert(solutionStateList.begin(), stateToAdd);
                    stateToAdd = parents[stateToAdd];

                }

                solutionStateList.insert(solutionStateList.begin(), stateToAdd);


                break;
            }
        }

        return solutionStateList;
    }




};


#endif //UNTITLED_BFS_H
//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_DFS_H
#define UNTITLED_DFS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>


#include "Searchable.h"
#include "Searcher.h"
#include "State.h"

using namespace std;


template <class T>
class DFSSearcher: public Searcher<T>{
    public:
        vector<State<T>> search (const Searchable<T>& searchable)
        {
            vector<State<T>> resultStateList;
            resultStateList.push_back(searchable.getInitialState());
            vector<State<T>> visited;

            searchRec(resultStateList, searchable.getInitialState(), visited, searchable);

            return resultStateList;
        }

        bool searchRec(vector<State<T>>& states, const State<T>& state, vector<State<T>>& visited, const Searchable<T>& searchable) {
            if(state == searchable.getGoalState())
            {
                states.push_back(state);
                return true;
            } else if(find(visited.begin(), visited.end(), state) != visited.end()) // state already visited
            {
                return false;
            }
            else // state not yet visited
            {
                visited.push_back(state);
                states.push_back(state);
                vector<State<T>> possibleStates = searchable.getAllPossibleStates(state);

                for(int i = 0; i < possibleStates.size(); ++i)
                {
                    int statesCostFromPath = searchRec(states, possibleStates[i], visited, searchable);

                    if(statesCostFromPath)
                    {
                        return statesCostFromPath;
                    }
                }

                states.pop_back();
                return false;
            }
        }

};

#endif //UNTITLED_DFS_H

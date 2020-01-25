//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_DFS_H
#define UNTITLED_DFS_H

#include <iostream>
#include <unordered_map>
#include <hash_map>
#include <vector>
#include <list>


#include "Searchable.h"
#include "Searcher.h"
#include "State.h"

using namespace std;

template <class T>
class DFSSearcher: public Searcher<T>{
    public:
        vector<State<T>*> search (Searchable<T> searchable)
        {
            vector<State<T>*> listOfStates;
            vector<State<T>*> visited;
        }

        void searchRec(vector<StateeState<T>* state, vector<State<T>*>& visited)
        {
            if(find(visited.begin(), visited.end(), state) == visited.end()) // state not yet visited
            {
                visited.push_back(state);

            }
        }
};

#endif //UNTITLED_DFS_H

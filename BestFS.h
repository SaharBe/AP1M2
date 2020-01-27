//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_BESTFS_H
#define UNTITLED_BESTFS_H

#include <iostream>
#include <unordered_map>
#include <hash_map>
#include <vector>
#include <queue>
#include <set>
#include "Searchable.h"
#include "Searcher.h"
#include "State.h"
#

using namespace std;

template <class T>
class BestFS: public Searcher<T>{
public:

    vector<State<T>*> openList;

    set<State<T>*> closed ;


    virtual vector<State<T>> search (const Searchable<T>& searchable)
    {
        priority_queue<State<T>> open;
        open.push(searchable.getInitialState());
        set<State<T>*> closed;

        while(!open.empty())
        {
            State<T> best = open.top();
            closed.insert(&best);

            if(best == searchable.getGoalState())
            {
                //
            }
            else{
                vector<State<T>> successorts = searchable.getAllPossibleStates(best);

                for(int i = 0; i < successorts.size(); i++)
                {
                    if(closed.count(&successorts[i]) == 0 && open.){

                    }
                }
            }
        }
    }

};

#endif //UNTITLED_BESTFS_H

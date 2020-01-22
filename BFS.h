//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H

#include <iostream>
#include <unordered_map>
#include <hash_map>
#include <vector>

#include "Searchable.h"
#include "Searcher.h"
#include "State.h"

using namespace std;

template <class T>
class BFS: public Searcher<T>{
public:

    vector<State<T>*> openList;

    hash<State<T>*> closed ;


    template <T>
  /*  void addToOpenList(State<T> ) {
        ;
    }*/
     State<T> backTrace(){
         return openList.back();
     };

     Solver search (Searchable<T> searchable){
        openList.clear();
        //addToOpenList(searchable.getInitialState());
        openList.push_back(searchable.getInitialState());

        while(openList.size() > 0){
            State<T> n = Searcher<T>::popOpenList();//removes the best state
            closed.Add(n);

            if(n.Equals(searchable.getGoalState())){
                return backTrace;//privet method, back traces through the parents
                //calling the delegated method , returns a list of states with n as a parent

            }
            vector<State<T>> succerssors = searchable.getAllPossibleStates(n);
            for(State<T> state: succerssors){
                if(!closed.find(state) && !openList.find(state)){

                }
            }

        }

    };


};

#endif //UNTITLED_BFS_H

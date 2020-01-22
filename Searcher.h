//
// Created by sahar on 21/01/2020.
//
#ifndef UNTITLED_SEARCHER_H
#define UNTITLED_SEARCHER_H

#include <list>
#include <deque>
#include <queue>
#include <iostream>
#include <vector>

#include "server_side.h"
#include "Searchable.h"
#include "State.h"


template <class T>
class Searcher{

private:
    std:: deque<State<T>*> MyPriorityQueue ;
    int evaluatedNodes;

public:
    Searcher(){
        MyPriorityQueue = new queue<State<T>*>;
        evaluatedNodes = 0;
    }
    //the search method
    virtual Solver search (Searchable<T> searchable);
    //get how many nodes were evaluated by the algorithm
     int getNumberOfNodesEvaluated();

protected:
    State<T> popOpenList(){
        evaluatedNodes++;
        return MyPriorityQueue.pop_back();

    }




};

#endif //UNTITLED_SEARCHER_H
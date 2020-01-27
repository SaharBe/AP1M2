
#ifndef UNTITLED_SEARCHER_H
#define UNTITLED_SEARCHER_H

#include <list>
#include <deque>
#include <queue>
#include <iostream>
#include <vector>

#include "Searchable.h"
#include "State.h"
#include "Solver.h"
#include "PathNode.h"


using namespace std;

template <class T, class S>
class Searcher{

protected:

    virtual vector<State<T>*> MyPriorityQueue(State<T> *node) ;
    virtual vector<State<T>*> backTrace(State<T> *node);
    int evaluatedNodes;


public:
    //ctor
    Searcher(){
        evaluatedNodes = 0;
    }
    //
    virtual ~Searcher() {}

    //the search method

    virtual vector<State<T>> search (const Searchable<T>& searchable) = 0;


    //get how many nodes were evaluated by the algorithm
     virtual int getNumberOfNodesEvaluated(){
        return evaluatedNodes;
     }


  //  template<T>
  /*  vector<State<T>*> backTrace(State<T> *s) {
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
    }*/



};

#endif //UNTITLED_SEARCHER_H
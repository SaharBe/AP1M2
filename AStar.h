//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_ASTAR_H
#define UNTITLED_ASTAR_H



#include "State.h"

template<class T>
class Heuristic {

public:
    virtual ~Heuristic() {}
    virtual void setGoal(State<T> *goal) = 0;
    virtual double evaluateFromNode(State<T> *current) = 0;
};

template <class T>
class AStar{
    Heuristic<T> *m_heuristic;

protected:
    virtual double costBetweenNodes(State<T> *start, State<T> *end) const {

    }
};

#endif //UNTITLED_ASTAR_H

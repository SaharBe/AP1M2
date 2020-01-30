//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_ASTAR_H
#define UNTITLED_ASTAR_H


#include "BestFS.h"
#include "State.h"

template<class T>
class Heuristic {

public:
    virtual ~Heuristic() {}
    virtual void setGoal(State<T> *goal) = 0;
    virtual double evaluateFromNode(State<T> *current) = 0;
};

template <class T>
class AStar : public BestFS<T> {
    Heuristic<T> *m_heuristic;

protected:
    virtual double costBetweenNodes(State<T> *start, State<T> *end) const {
        if (start == end) {
            return m_heuristic->evaluateFromNode(end);
        }
        return start->getCost() + end->getOriginalCost();
    }

public:
    explicit AStar(Heuristic<T> *h) : m_heuristic(h) {}

    virtual ~AStar() {}

    virtual vector<State<T> *> search(Searchable<T> *searchable) {
        m_heuristic->setGoal(searchable->getGoalState());
        return BestFS<T>::search(searchable);
    }
};

#endif //UNTITLED_ASTAR_H

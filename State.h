//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_STATE_H
#define UNTITLED_STATE_H

#include "Node.h"
#include <iostream>
template <class T>
class State{
private:
    T state;
    double originalCost;
    double cost;
    State<T>* cameFrom;




public:

    State<T>(T state, double cost, State<T>* cameFrom = NULL){
        this->state = state;
        this->cost = cost;
        this->originalCost = cost;
        this->cameFrom = cameFrom;

    }

    State<T>(T state){
        this->state = state;
    }

    State() {

    }

    void setCameFrom(State<T>& s) {
        cameFrom = &s;
    }

   State<T>* getCameFrom() {
       return cameFrom;
    }
    void setCost(double doub) {
        cost = doub;
    }

    void operator=(const State& other)
    {
        this->state = other.state;
        this->cost = other.cost;
    }


    bool operator==(State other) const
    {
        return state == other.state;
    }

    bool operator!=(State other) const
    {
        return state != other.state;
    }

    bool operator<(const State<T>& other) const{
        return state < other.state;
    }

    double getCost() const
    {
        return cost;
    }
    void setVisitState(bool visit) {
        this->is_visitedNode = visit;
    }
    T getState() const{
        return state;
    }
    double getOriginalCost() const {
        return originalCost;
    }



};


#endif //UNTITLED_STATE_H

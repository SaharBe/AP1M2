//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_STATE_H
#define UNTITLED_STATE_H

#include "Node.h"

template <typename T>
class State{
private:
    T state;
    double cost;
    State<T>* cameFrom;

public:

    State<T>(T state, double cost){
        this->state = state;
        this->cost = cost;
        this->cameFrom = cameFrom;
    }


    bool operator==(State other)
    {
        return state == other.state;
    }

    bool operator<(const State<T>& other){
        return other.cost < this->cost;
    }

    double getCost()
    {
        return cost;
    }
    T getState(){
        return state;
    }
};


#endif //UNTITLED_STATE_H

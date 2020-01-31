//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_STATE_H
#define UNTITLED_STATE_H

#include "Node.h"

template <class T>
class State{
private:
    T state;
    double cost;
    State<T>* cameFrom;


    State *top;
    State *bottom;
    State *left;
    State *right;



public:

    State<T>(T state, double cost){
        this->state = state;
        this->cost = cost;
        this->cameFrom = cameFrom;

    }

    State<T>(T state){
        this->state = state;
    }

    State() {

    }


    bool operator==(State other)
    {
        return state == other.state;
    }

    bool operator<(const State<T>& other){
        return other.cost < this->cost;
    }

    double getCost() const
    {
        return cost;
    }
    T getState() const{
        return state;
    }



    /* std::vector<State *> ret;

        if (bottom != NULL)
            ret.push_back(bottom);
        if (top != NULL)
            ret.push_back(top);
        if (left != NULL)
            ret.push_back(left);
        if (right != NULL)
            ret.push_back(right);
        return ret;*/

};


#endif //UNTITLED_STATE_H

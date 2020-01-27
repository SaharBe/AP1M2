//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_STATE_H
#define UNTITLED_STATE_H

template <typename T>
class State{
private:
    T id;
    double cost;
    State<T>* cameFrom;

public:

    State(T state){
        this->state = state;
        this->cost = cost;
    }

    bool operator==(const State<T>& other)
    {
        return id == other.id;
    }
};


#endif //UNTITLED_STATE_H

//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_STATE_H
#define UNTITLED_STATE_H

template <typename T>
class State{
private:
    T state;
    double cost;
    State<T> cameFrom;

public:

    template <T>
    State(T state){
        this->state = state;
        this->cost = cost;
    }
    template <T>
    bool Equals(State<T> s){
        return State(state).Equals(s.state);
    }


};


#endif //UNTITLED_STATE_H

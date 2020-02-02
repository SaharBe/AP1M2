

#ifndef UNTITLED_PATHNODE_H
#define UNTITLED_PATHNODE_H

#include "State.h"

template <class T, class S>
class PathNode {
private:
    State<T>* state;
    S direction;

public:
    PathNode(State<T>* state, S direction) : state(state), direction(direction)
    {

    }

    State<T>* getState()
    {
        return state;
    }

    S getDirection()
    {
        return direction;
    }

};


#endif //UNTITLED_PATHNODE_H

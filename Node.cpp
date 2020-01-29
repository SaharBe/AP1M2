//
// Created by sahar on 25/01/2020.
//

#include "Node.h"
#include "State.h"

Node Node::upNode() {
    return Node(this->x -1, this->y);
}

Node Node::downNode() {

    return Node(this->x, this->y -1);
}

Node Node::rightNode() {
    return Node(this->x+1, this->y);
}
Node Node::leftNode() {
    return Node(this->x -1, this->y );
}

int Node ::getRow(){
    return this->y;
}
int Node:: getCol(){
    return this->x;
}
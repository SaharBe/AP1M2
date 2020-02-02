
#include "Node.h"
#include "State.h"

Node Node::upNode() {
    return Node(this->x , this->y -1, cols);
}

Node Node::downNode() {

    return Node(this->x, this->y +1, cols);
}

Node Node::rightNode() {
    return Node(this->x+1, this->y, cols);
}
Node Node::leftNode() {
    return Node(this->x -1, this->y, cols );
}

int Node ::getRow(){
    return this->y;
}
int Node:: getCol(){
    return this->x;
}

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include <string>
#include <iostream>
#include "State.h"

using namespace std;

class Node{
    int x;
    int y;
    int cols;



public:
    Node(int x, int y, int cols){
        this->x = x;
        this->y = y;
        this->cols = cols;

    }
    Node(){

    }


    Node upNode();
    Node downNode();
    Node rightNode();
    Node leftNode();
    bool operator==(const Node& other) const
    {
        return this->x == other.x && this->y == other.y;
    }

    bool operator!=(const Node& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Node& other) const
    {
        int indexThis = this->y * this->cols + this->x;
        int indexOther = other.y * other.cols + other.x;

        return indexThis < indexOther;
    }


    int getRow();
    int getCol();


};


#endif //UNTITLED_NODE_H

//
// Created by sahar on 25/01/2020.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include <string>
#include <iostream>
#include "State.h"

using namespace std;

class Node{
    int x;
    int y;



public:
    Node(int x, int y){
        this->x = x;
        this->y = y;

    }
    Node(){

    }
    string get(int x,int y);

    Node upNode();
    Node downNode();
    Node rightNode();
    Node leftNode();
    bool operator==(Node other)
    {
        if(this->x == other.x && this->y == other.y){
            return true;
        }
        return false;
    }

    int getRow();
    int getCol();


};


#endif //UNTITLED_NODE_H

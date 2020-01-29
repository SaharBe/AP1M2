//
// Created by sahar on 25/01/2020.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include <string>
#include <iostream>

using namespace std;

class Node{
    int x;
    int y;



public:
    Node(int x, int y){
        this->x = x;
        this->y = y;

    }
    string get(int x,int y);

    Node upNode();
    Node downNode();
    Node rightNode();
    Node leftNode();

    int getRow();
    int getCol();


};


#endif //UNTITLED_NODE_H

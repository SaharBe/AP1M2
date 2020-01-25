//
// Created by sahar on 24/01/2020.
//

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include "Searchable.h"
#include <string>

using namespace std;

class Node{
    int x;
    int y;

    string get(int x,int y){
        string x1 = to_string(x);
        string y1 = to_string(y);
        return '('+ x1 + ','+ y1 + ')';
    }

public:
    Node(int x, int y){
        this->x = x;
        this->y = y;

    }
};


template <class T>
class Matrix: public Searchable<T> {
private:
    int cols{0};
    int rows{0};
    int numOfCells = cols*rows;
    Node start;
    Node end;

public:
    Matrix(int cols, int rows,Node start, Node end ){
        this->cols = cols;
        this->rows = rows;
        this->numOfCells =  cols* rows;

    }
    ~Matrix(){
        delete start;
        delete end;
    }


};





#endif //UNTITLED_MATRIX_H

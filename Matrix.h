//
// Created by sahar on 24/01/2020.
//

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include "Searchable.h"
#include <string>

#include "Node.h"
using namespace std;




template <class T>
class Matrix: public Searchable<T> {
private:
    int cols{0};
    int rows{0};
    int numOfCells = cols*rows;
    State<T> start;
    State<T> end;

public:
    Matrix(int cols, int rows,State<T> start, State<T> end ){
        this->cols = cols;
        this->rows = rows;
        this->numOfCells =  cols* rows;


    }
    ~Matrix(){
        delete start;
        delete end;
    }
    State<T> getInitialState() {
        return start;
    }
    State<T> getGoalState() {
        return end;
    }
    vector<vector<Node>*> getAllPossibleStates(State<Node> *state) {
        std:: vector<State<Node>*> result;



    }



};





#endif //UNTITLED_MATRIX_H

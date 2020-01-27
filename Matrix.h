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
    int cols;
    int rows;

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
    vector<State<T>> getAllPossibleStates(State<Node> *state) {
        std:: vector<State<Node>*> result;

        Node curr = state->getState();
        std::vector<Node> steps = {curr.downNode(), curr.upNode(), curr.rightNode(), curr.leftNode()};
        for (Node step : steps) {
            if (validStep(step)) {
                result.push_back(new State<Node>((*this)[step] + state->getCost()));
            }
        }
        return result;

    }

    bool validStep(Node node) {
        if ((node.getRow() >= this->rows) ||
        (node.getRow() < 0) || (node.getCol() >= this->cols) || (node.getCol() < 0))
        {
            return false;
        }
        return ((*this)[node] != -1);
    }

    void initialize(const vector<string>& info){
        // Creating one big continuous block of memory
        State<Node>** matrix = new State<Node> *[this->rows * this->rows];

        // Each cell in the matrix is a pointer to a State object
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i * cols + j] = new State<Node*>(new Node(i, j));
            }
        }

    }


};




#endif //UNTITLED_MATRIX_H

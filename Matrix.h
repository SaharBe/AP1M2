//
// Created by sahar on 24/01/2020.
//

#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H

#include "Searchable.h"
#include <string>
#include "search.h"
#include "Node.h"
#include <vector>


using namespace std;



class Matrix: public Searchable<Node> {
private:

    int cols;
    int rows;



    State<Node> start;
    State<Node> end;
    vector<vector<State<Node>>> mat;




public:
    Matrix(int cols, int rows,const State<Node>& start, const State<Node>& end ,const vector<vector<State<Node>>>& mat)
        : start(start), end(end), cols(cols), rows(rows), mat(mat){
    }


    ~Matrix(){

    }
    State<Node> getInitialState()const {
        return start;
    }
    State<Node> getGoalState()const {
        return end;
    }


    vector<State<Node>> getAllPossibleStates(const State<Node>& state) const{
   /*   std:: vector<State<Node>> result;


        Node curr = state.getState();
        std::vector<Node> steps = {curr.downNode(), curr.upNode(), curr.rightNode(), curr.leftNode()};
        for (Node& step : steps) {
            //up
           if (step.getRow() < rows && step.getRow() >= 0 && step.getCol() < cols && step.getCol() >= 0) {
               double cost = mat[curr.getRow()][curr.getCol()].getCost();

               if(cost != -1)
               {
                   result.push_back(State<Node>(step, cost));
               }

            }
        }
        return result;*/

        vector<State<Node>> vec;

        int currRow = state.getState().getRow();
        int currCol = state.getState().getCol();

        // Up neighbor
        if (currRow > 0  && mat[currRow -1][currCol].getCost() != -1) {
            vec.emplace_back(mat[currRow -1][currCol]);
        }
        // Down neighbor
        if (currRow < rows-1 && mat[currRow +1][currCol].getCost() != -1) {
            vec.emplace_back(mat[currRow +1][currCol]);
        }
        // Left neighbor
        if (currCol > 0 && mat[currRow ][currCol -1].getCost() != -1)   {
            vec.emplace_back(mat[currRow ][currCol -1]);
        }
        // Right neighbor
        if (currCol < cols-1 && mat[currRow ][currCol +1].getCost() != -1) {
            vec.emplace_back(mat[currRow][currCol +1]);
        }
        return vec;
    }

};




#endif //UNTITLED_MATRIX_H

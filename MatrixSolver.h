//
// Created by sahar on 26/01/2020.
//

#ifndef UNTITLED_MATRIXSOLVER_H
#define UNTITLED_MATRIXSOLVER_H


#include <iostream>
#include <list>
#include <string>

#include "Matrix.h"
#include "Node.h"
#include "Solver.h"
#include "Searcher.h"
#include "vector"


template <class T>
class MatrixSolver: public Solver< string, string>{

    ///

  //  make the matrix from the string
    ///
    Searcher<Matrix<T>>* searcher;

public:

    vector<string> split(string str, string sep) {
        vector<string> answer;
        string token;
        string letter;
        for (int i = 0; i < str.size(); ++i) {
            letter = str[i];
            if (letter == sep) {
                if (!token.empty()) {
                    answer.push_back(token);
                }
                token = "";
                continue;
            }
            token += str[i];
        }
        if (!token.empty()) {
            answer.push_back(token);
        }
        return answer;
    }

    ///ctor
    MatrixSolver( const string& prob){


    }

    int numofMatrixCols(string str){
        int colsCounter = 0;
        int i;

        for(i=0 ; i < str.size(); i++){
            if (str[i] == ',') {
                colsCounter++;
            }
        }
        //the last without ","
        colsCounter++;
        return colsCounter;
    }

    Node createNode(string str){
        if(str[0] == '(')
            str.erase(str.begin());
        if(str[str.size() - 1] ==  ')'){
            str.erase(str.back());
        }
        int i = 0;
        string x = "";
        string y = "";
        while(str[i] != ','){
            x = x + str[i];
            i++;
        }
        i++;
        int X = stoi(x);
        for(i= i; i < str.size(); i++){
            y = y + str[i];
        }
        int Y = stoi(y);

        Node* node = new Node(X, Y);

        return *node;

    }

    Matrix<T> createMatrix(const string& prob){


        vector<string> lines;
        vector<Node> nodeVec;
        string tempLine = "";
        char x ;
        //split the string to lines
        for(char i : prob){
            if(i != '\n'){
                x = i;
                tempLine+= x;

            }else{
                lines.push_back(tempLine);
                tempLine = "";

            }
        }


        char tempX = ' ';

        //check if back == "end" !!
       // if(lines.back() == "end"){
                lines.pop_back();
                /////
                int i =0;
                string endd = lines.back();
                Node end = createNode(endd);
                lines.pop_back();
                string startt = lines.back();
                Node start = createNode(startt);
               lines.pop_back();
               State<Node> start0 = start;
               State<Node> end0 = end;

        ////


        int rows = lines.size() ; // num of vectors -3
        string random = lines.front();
        int cols = numofMatrixCols(random);
        Matrix<T> matrix = new Matrix<T>(cols,  rows,start0,  end0);

        return matrix;

        }

    vector<string> createVectorOfstrings(const string& prob){



    }




    virtual string solve(string problem){
        Matrix<Node>* matrix =  createMatrix(problem);

        vector<State<Node>> state =  searcher->search(matrix);
        static double costAll = 0;

        string solution = "";
        string temp = "";



        for(State<Node> s : state){
            costAll+= s.getCost();
        }


        State<Node> first = state.back();
        State<Node> second = state.back();

        int i;

        for(i =0; i < state.size() ; i++){

            if(first.operator==(second.getState().upNode()) ){
               temp = solution;
               solution =  ",Down (" + to_string(costAll) + ")" +temp;

               costAll = costAll - first.getCost();
            }
            else if(first.operator==(second.getState().downNode()) ){
                temp = solution;
                solution =  ",Up (" + to_string(costAll) + ")" +temp;

                costAll = costAll - first.getCost();
            }else if(first.operator==(second.getState().rightNode())){
                temp = solution;
                solution =  ",Left (" + to_string(costAll) + ")" +temp;

                costAll = costAll - first.getCost();
            }else if(first.operator==(second.getState().leftNode())){
                temp = solution;
                solution =  ",Right (" + to_string(costAll) + ")" +temp;

                costAll = costAll - first.getCost();
            } else{
                cerr << "error" << endl;
            }
        }


        solution.erase(solution.begin());

        return solution;

    }

};


#endif //UNTITLED_MATRIXSOLVER_H

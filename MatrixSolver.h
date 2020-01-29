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
#include "DFS.h"
#include "BFS.h"
#include "BestFS.h"
#include "AStar.h"


template <class T>
class MatrixSolver: public Solver< string, string>{

    static int rows;
    static int cols;
    static string endd;
    static string startt;
    ///

  //  make the matrix from the string
    ///
  // Searcher<Matrix<Node>>* searcher = new BestFS ;

  Searcher<Matrix<Node>,  vector<State<T>>> searcher ;

public:

    ///ctor
    MatrixSolver( const string& prob){

    }
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

    void createMatrix(const string& prob){


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
         endd = lines.back();
        State<Node> end = createNode(endd);
        lines.pop_back();
         startt = lines.back();
        State<Node> start = createNode(startt);
        lines.pop_back();
        State<Node> start0 = start;
        State<Node> end0 = end;

        ////


        rows = lines.size() ; // num of vectors -3
        string random = lines.front();
        cols = numofMatrixCols(random);
        Matrix<T> matrix = new Matrix<T>(cols,  rows,start0,  end0);

        //return matrix;

    }

    vector<string> createVectorOfstrings(const string& prob, int rows){
        vector<string> stringsVector;
        string temp = "";
        string temptemp = temp;
        int i = 0;

        for(int j=0; j< rows ; j++){
            while(prob[i]!= '\n'){
                temptemp = temp;
                temp = temptemp +prob[i];
                i++;
            }
            stringsVector.push_back(temp);
            temp = "";
            temptemp = "";
        }
        return stringsVector;
    }
    //only for square matrix!!
    vector<vector<State<T>>> makeStringsTONodes (vector<string> stringVector){
        vector<vector<State<T>>> matrix ;
        vector<State<T>> line;
        int numOfLines = stringVector.size();
        int numOfNodesInLine = numOfLines;
        int i, j;
        int n =0;
        double cost;
        string value;
        int temp = 0;
        for(i = 0; i < numOfLines; i++){
            for(j= 0; j < numOfNodesInLine; j++){
                while (stringVector.front()[n] != ','){
                    value = value + stringVector.front()[n];
                    n++;
                }
                cost = stod(value);
                Node* node = new Node(i,j);
                State<Node*> state(node,cost);
                value = "";
                line.push_back(state);
            }
            matrix.push_back(line);
            line.empty();
        }
        return matrix;

    }



    virtual string solve(string problem){

        createMatrix(problem);
        Matrix<T> matrix(cols, rows,startt, endd);
        vector<string> vec = matrix.createVectorOfstrings(problem,rows);
        vector<vector<State<Node>>> mat = matrix.makeStringsTONodes(vec);


        vector<State<T>> ans = searcher->search(mat);
        static double costAll = 0;

        string solution = "";
        string temp = "";



        for(State<Node> s : ans){
            costAll+= s.getCost();
        }


        State<Node> first = ans.back();
        mat.pop_back();
        State<Node> second = ans.back();

        int i;



        for(i =0; i < ans.size() ; i++){

            Node a  = first.getState();
            Node b  = second.getState().upNode();
            Node c = second.getState().downNode();
            Node d  = second.getState().rightNode();
            Node e  = second.getState().leftNode();


            if(a.operator==(b)){
               temp = solution;
               solution =  ",Down (" + to_string(costAll) + ")" +temp;

               costAll = costAll - first.getCost();
            }
            else if(a.operator==(c)){
                temp = solution;
                solution =  ",Up (" + to_string(costAll) + ")" +temp;

                costAll = costAll - first.getCost();
            }else if(a.operator==(d)){
                temp = solution;
                solution =  ",Left (" + to_string(costAll) + ")" +temp;

                costAll = costAll - first.getCost();
            }else if(a.operator==(e)){
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

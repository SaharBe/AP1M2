

#ifndef UNTITLED_OBJECTADAPTER_H
#define UNTITLED_OBJECTADAPTER_H


#include "Solver.h"
#include "Searcher.h"
#include <iostream>
#include <string.h>

using namespace std;
class StringRevers: public Solver<string, string>{
public:

   string solve(string problem){
       string p = problem;

       int n = p.length();

       // Swap character starting from two
       // corners
       for (int i = 0; i < n / 2; i++)
           swap(p[i], p[n - i - 1]);

       return problem;
    }


};


/*
class ObjectAdapter: public Solver<class Problem, class Solution>{
    Searcher<Problem>* searcher;

    Searchable<Problem>* searchable;

public:

    virtual Solution* solve(Problem* problem){
        searcher->search();

    }



};*/





#endif //UNTITLED_OBJECTADAPTER_H

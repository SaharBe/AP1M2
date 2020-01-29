

#ifndef UNTITLED_STRINGREVERS_H
#define UNTITLED_STRINGREVERS_H


#include "Solver.h"
#include "Searcher.h"
#include <iostream>
#include <string.h>

using namespace std;
class StringRevers: public Solver<string, string>{
public:

   string solve(string problem);


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





#endif //UNTITLED_STRINGREVERS_H

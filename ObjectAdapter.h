

#ifndef UNTITLED_OBJECTADAPTER_H
#define UNTITLED_OBJECTADAPTER_H


#include "Solver.h"
#include <iostream>
#include <string.h>

using namespace std;
class StringRevers{
public:

    string getstring(string str);

};



class ObjectAdapter: public Solver<class Problem, class Solution>{
public:

    virtual Solution* solve(Problem* problem){}



};





#endif //UNTITLED_OBJECTADAPTER_H

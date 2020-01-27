
#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H


using namespace std;


template <class Problem, class Solution>
class Solver {
public:


virtual Solution solve(Problem problem) = 0;


Solver(){}

virtual ~Solver() {}

};


#endif //UNTITLED_SOLVER_H

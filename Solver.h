

#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H

using namespace std;

template <class Problem, class Solution>
class Solver {
public:
    virtual ~Solver() {}
    virtual Solution* solve(Problem problem) =0;


};


#endif //UNTITLED_SOLVER_H

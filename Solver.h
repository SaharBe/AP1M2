//
// Created by sahar on 23/01/2020.
//


#ifndef UNTITLED_SOLVER_H
#define UNTITLED_SOLVER_H


template <class Problem, class Solution>
class Solver {
public:

virtual Solution* solve(Problem problem) =0;

virtual ~Solver() {}



};


#endif //UNTITLED_SOLVER_H

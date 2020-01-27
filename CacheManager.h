

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
#ifndef UNTITLED__CACHEMANAGER_H_
#define UNTITLED__CACHEMANAGER_H_



//interface for a cacheManager. it gets a problem from a clientHandler and returns solution if its in cache
template <class Problem,class Solution>
class CacheManager {
 public:
    virtual bool DoesSolutionExist(Problem problem) = 0;
    virtual Solution returnSolution(Problem problem) = 0; //return a solution to client handler
    virtual void SaveSolution(Problem problem, Solution solution) = 0;
  };


  class FileCacheManager: public CacheManager<class Problem,class Solution>{
   public:
    std:: unordered_map<Problem*,Solution*> solutionMap;

    //returns T/F based on if the solution exists in the map
    template <class Problem>  bool DoesSolutionExist(Problem& problem) {
        if(solutionMap.find(problem) == solutionMap.end()) {
            return false;
         }
        else{return true;}
    }

    //return the solution from the cache
    template <class Solution,class Problem> Solution returnSolution(Problem& problem) {
        {
            Solution solution;
            //if a solution is already in the cache it returns it
            solution = solutionMap.find(problem)->second;
            return solution;


        }

    }

    //saves the problem and solution in the cache
    template <class Solution,class Problem> void SaveSolution(Problem& problem,Solution& solution){

            solutionMap.insert(problem,solution);

    }
};





#endif //UNTITLED__CACHEMANAGER_H_

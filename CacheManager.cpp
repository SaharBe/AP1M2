

#include "CacheManager.h"



string FileCacheManager::returnSolution(string problem) {
  string solution;
  //if a solution is already in the cache
  if(DoesSolutionExist(problem)){
    solution = solutionMap.find(problem)->second;
    return solution;
  }
  else {
    //active the solution from the clientHandler,save it,and return it.
    solution = //clientHandler.solver.solve...maybe need to give clienthandler a solver variable.
    SaveSolution(problem,solution); //save the solution
    return solution;
  }
}



//returns T\F based on if the problem-string is in the solutionMap
bool FileCacheManager::DoesSolutionExist(string problem) {
  if(solutionMap.find(problem) == solutionMap.end()) {
    return false;
  }
  else{return true;}
}

void FileCacheManager::SaveSolution(string problem, string solution) {
  solutionMap.insert(problem,solution);
}

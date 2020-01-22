

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;
#ifndef UNTITLED__CACHEMANAGER_H_
#define UNTITLED__CACHEMANAGER_H_


//interface for a cacheManager. it gets a problem from a clientHandler and returns solution
class CacheManager {
 public:
    bool DoesSolutionExist();
    string returnSolution(string problem); //return a solution to client handler
    void SaveSolution(string problem,string solution);

  };


  class FileCacheManager: public CacheManager{
   public:
    unordered_map<string,string> solutionMap;
    bool DoesSolutionExist(string problem);
    string returnSolution(string problem);
    void SaveSolution(string problem,string solution);
  };


#endif //UNTITLED__CACHEMANAGER_H_

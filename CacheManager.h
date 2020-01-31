
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdio.h>


using namespace std;
#ifndef UNTITLED__CACHEMANAGER_H_
#define UNTITLED__CACHEMANAGER_H_



//interface for a cacheManager. it gets a problem from a clientHandler and returns solution if its in cache
template <class Problem,class Solution>
class CacheManager {
public:
    virtual bool DoesSolutionExist(Problem problem) = 0;

    virtual Solution returnSolution(Problem problem) = 0;
    virtual void SaveSolution(Problem problem, Solution solution) = 0;
};


class FileCacheManager: public CacheManager<string,string> {
public:
    std::unordered_map<string, string> solutionHashMap;
    vector<string> hashMapVector;
    int hashMapMaxSize = 10;


    virtual bool DoesSolutionExist(string problem);


    virtual void SaveSolution(string problem,string solution);

    virtual string returnSolution(string problem);
    //returns T/F based on if the solution exists in the map
    bool DoesSolutionExistsInHashMap(string problem);

    //return the solution from the cache
    string ReturnSolutionFromHashMap(string problem);

    //saves the problem and solution in the cache
    void UpdateCacheMap(string problem, string solution);


    string ReturnSolutionFromFiles(string problem);


    bool DoesSolutionExistsInFiles(string problem);

    void SaveSolutionInFiles(string problem, string solution);

    void SaveSolutionInHashMap(string problem, string solution);


};






#endif //UNTITLED__CACHEMANAGER_H_
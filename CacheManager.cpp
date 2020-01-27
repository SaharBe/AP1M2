

#include "CacheManager.h"



string FileCacheManager::returnSolution(string problem) {
  string solution;
  //if a solution is already in the cache
  if(DoesSolutionExistsInHashMap(problem)){
    solution = ReturnSolutionFromHashMap(problem);
    UpdateCacheMap(problem,solution);
    return solution;
  }
  //if solution is in file
  else if (DoesSolutionExistsInFiles(problem)){
      solution=ReturnSolutionFromFiles(problem);
      UpdateCacheMap(problem,solution);
      return solution;
  }

  else {
      throw invalid_argument("entered to returnSolution even though solution in not in files and not in hashMap");
  }

}



//returns T\F based on if the problem-string is in the solutionMap
bool FileCacheManager::DoesSolutionExistsInHashMap(string problem)  {
  if(solutionHashMap.find(problem) == solutionHashMap.end()) {
    return false;
  }
  else{return true;}
}

string FileCacheManager::ReturnSolutionFromHashMap(string problem) {
    unordered_map<string,string>::iterator iterator = solutionHashMap.find(problem);
    if(iterator !=solutionHashMap.end()) {
        return iterator->second;
    }
    else{
        throw std::invalid_argument("error.couldnt find solution in map(returnSolutionFromHashMap)");
    }

}

void FileCacheManager::SaveSolutionInHashMap(string problem, string solution) {
  solutionHashMap[problem] = solution;
}

void FileCacheManager::UpdateCacheMap(string problem, string solution) {
    //if the hash map is full,delete the last used problem/solver from it and update hashMap and vector
    if(hashMapVector.size() == hashMapMaxSize) {
        //get the problem from the vector
        string problemToDelete = hashMapVector.at(hashMapMaxSize-1);
        //delete it from the vector and from hashMap
        hashMapVector.erase(hashMapVector.end() - 1);
        solutionHashMap.erase(problemToDelete);
        //insert the problem to the hashMap and the hashMapVector
        hashMapVector.insert(hashMapVector.begin(), problem);
        solutionHashMap[problem] = solution;
    }
    //if hashMap is not full,update just the hashMap and its vector
    else {
        //if the problem is not in the map,update map and vector
        if(find(hashMapVector.begin(),hashMapVector.end(),problem) == hashMapVector.end() ) {
            hashMapVector.insert(hashMapVector.begin(), problem);
            solutionHashMap[problem] = solution;
        }
        //if the problem is already in the map,update only the vector.
        else{
            hashMapVector.insert(hashMapVector.begin(), problem);
        }
    }

}

string FileCacheManager::ReturnSolutionFromFiles(string problem) {
    ifstream readFileStream;
    readFileStream.open(problem);
    if(!readFileStream.is_open()){
        readFileStream.close();
        throw invalid_argument("error in opening file");
    }
    else{
        string solution{istreambuf_iterator<char>(readFileStream),istreambuf_iterator<char>()};
        readFileStream.close();
        return solution;
    }
}
bool FileCacheManager::DoesSolutionExistsInFiles(string problem) {
    ifstream readFileStream;
    readFileStream.open(problem);
    if(!readFileStream.is_open()){
        readFileStream.close();
        throw invalid_argument("error in opening file");
    }
    //if file is empty,return false
    if(readFileStream.peek() == ifstream::traits_type::eof()){
        readFileStream.close();
        return false;
    }
    else{
        return true;
    }

}

void FileCacheManager::SaveSolutionInFiles(string problem, string solution) {
    ofstream writeToFileStream;
    writeToFileStream.open(problem);
    if(!writeToFileStream.is_open()){
        writeToFileStream.close();
        throw invalid_argument("error in opening file");
    }
    writeToFileStream << &solution;
    writeToFileStream.close();
}

bool FileCacheManager::DoesSolutionExist(string problem){
    if(DoesSolutionExistsInHashMap(problem)){
        return true;
    }
    if(DoesSolutionExistsInFiles(problem)){
        return true;
    }
    else {
        return false;
    }

}

void FileCacheManager::SaveSolution(string problem, string solution) {
    SaveSolutionInFiles(problem,solution);
    SaveSolutionInHashMap(problem,solution);
}





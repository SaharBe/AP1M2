#include "server_side.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Solver.h"
#include "CacheManager.h"
#include "ObjectAdapter.h"
#include "MatrixSolver.h"

#ifndef UNTITLED_MYPARALLELSERVER_H
#define UNTITLED_MYPARALLELSERVER_H


class MyParallelServer:public Server {
public:
    bool continueFlag = true;
    virtual void open(int port,ClientHandler& c);
    virtual  bool stop(int socet);
    MyParallelServer();

};


#endif //UNTITLED_MYPARALLELSERVER_H

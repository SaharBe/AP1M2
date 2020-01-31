#include "server_side.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <unordered_map>
#include "Solver.h"
#include "CacheManager.h"
#include "StringRevers.h"
#include "MatrixSolver.h"


#ifndef UNTITLED_MYPARALLELSERVER_H
#define UNTITLED_MYPARALLELSERVER_H


class MyParallelServer:public Server {
    static void* activeClientHandler(void* arg);
public:
    vector<thread> threadVector;
    bool continueFlag = true;
    virtual void open(int port,ClientHandler* c);
    virtual  bool stop(int socet);



};

typedef struct {
    int socket;
    ClientHandler *client;
} clientData;


#endif //UNTITLED_MYPARALLELSERVER_H
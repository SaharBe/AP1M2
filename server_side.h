
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Solver.h"
#include "CacheManager.h"
#include "StringRevers.h"
#include "MatrixSolver.h"
#include <vector>




using namespace std;

#ifndef UNTITLED_SERVER_SIDE_H
#define UNTITLED_SERVER_SIDE_H



class ClientHandler{
public:
    virtual void handlerClient(int outputStream,int inputStream ) = 0;


};


class Server {


public:
    virtual void open(int port,ClientHandler* c) = 0;
    virtual bool stop(int socet) =0;


};



class MySerialServer: public Server{
public:
    bool continueFlag = true;
    virtual void open(int port,ClientHandler* c);
    virtual  bool stop(int socet);


    //virtual void start(int port);


    MySerialServer() ;
    ~MySerialServer();


};





class MyTestClientHandler: public ClientHandler{

public:

    Solver<string,string>*solver;
    CacheManager<string,string> *cacheManager;

    virtual void WriteAnswerToClient(int outPutStream,string question);
    virtual void handlerClient(int outputStream,int inputStream );
    string  fromCharToString(char *question);



    MyTestClientHandler(Solver<string,string> *stringRevers, CacheManager<string,string> *file_cache_manager ){
        this->solver = stringRevers;
        this->cacheManager= file_cache_manager;
    }

};

class  MyClientHandler : public ClientHandler{

public:
    Solver<string,string> *solver;
    CacheManager<string,string> *cacheManager;

    virtual void WriteAnswerToClient(int outPutStream,string question);
    virtual void handlerClient(int outputStream,int inputStream );








};
/*
namespace boot {
    class Main {
    public:
        int main(int argc, char *args[]);
    };
}*/









#endif //UNTITLED_SERVER_SIDE_H
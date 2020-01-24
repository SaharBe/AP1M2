
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "CacheManager.h"
#include "Solver.h"
#include "ObjectAdapter.h"


using namespace std;

#ifndef UNTITLED_SERVER_SIDE_H
#define UNTITLED_SERVER_SIDE_H



class ClientHandler{
    public:
        void handlerClient(int outputStream,int inputStream );
    };


class Server {
public:
    Server() = default;
    virtual ~Server()= default;

    virtual void open(int port,ClientHandler c) = 0;
    virtual bool stop() = 0;
};




class MySerialServer: public Server{
    public:
       virtual void open(int port,ClientHandler c);
       virtual  bool stop();
       virtual void start(int port);
        void threadLoop(int port,ClientHandler c);
       MySerialServer();
       ~MySerialServer();

        void start();
    };

class MyParallelServer: public Server{

};



class MyTestClientHandler: public ClientHandler{
    public:
    CacheManager<string,string> file_cache_manager;
    StringRevers stringRevers;


    void WriteAnswerToClient(int outPutStream,string question);
    void handlerClient(int outputStream,int inputStream );

};










#endif //UNTITLED_SERVER_SIDE_H


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
        virtual void handlerClient(int outputStream,int inputStream ) = 0;


};


class Server {
public:
    virtual void open(int port,ClientHandler& c) = 0;
    virtual bool stop() =0;
};



class MySerialServer: public Server{
    public:
       virtual void open(int port,ClientHandler& c);
       virtual  bool stop();
       virtual void start(int port);
        void threadLoop(int port,ClientHandler& c);

       MySerialServer();
       ~MySerialServer();

        
    };


class MyParallelServer: public Server{

};



class MyTestClientHandler: public ClientHandler{

    public:
    FileCacheManager& file_cache_manager ;
    StringRevers stringRevers;


    virtual void WriteAnswerToClient(int outPutStream,Problem question);
    virtual void handlerClient(int outputStream,int inputStream );

};
namespace boot {
    class Main {
        int main(int argc, char *args[]);
    };
}









#endif //UNTITLED_SERVER_SIDE_H

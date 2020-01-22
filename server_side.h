
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "CacheManager.h"
#include "Server.h"


using namespace std;

#ifndef UNTITLED_SERVER_SIDE_H
#define UNTITLED_SERVER_SIDE_H





    class ClientHandler{
    public:
        void handlerClien(ofstream outputStream,ifstream inputStream );
    };



class MySerialServer: public server_side::Server{
    public:
       virtual void open(int port);
       virtual  bool stop();
       virtual void start(int port);
        void threadLoop(int port);
       MySerialServer();
       ~MySerialServer();

        void start();
    };

class MyParallelServer: public server_side::Server{

     };



    class ClientHandler{
        void handlerClient(ofstream outputStream,ifstream inputStream );
    };




    class Solver{

        public:
        void solve();

    };



 






    class MyTestClientHandler: public ClientHandler{
        FileCacheManager file_cache_manager;
        Solver solver(){

        }
        void handlerClient(ofstream outputStream,ifstream inputStream );

    };










#endif //UNTITLED_SERVER_SIDE_H

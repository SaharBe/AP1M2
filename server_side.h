//
// Created by sahar on 13/01/2020.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "CacheManager.h"

using namespace std;

#ifndef UNTITLED_SERVER_SIDE_H
#define UNTITLED_SERVER_SIDE_H

namespace server_side{

    class ClientHandler{
        void handlerClient(ofstream outputStream,ifstream inputStream );
    };

    class Server: public ClientHandler{
        void open(int port){

        }void stop(int port){}

    };

    class MySerialServer: public Server{

    };
    class MyParallelServer: public Server{};

    class Solver{
        void solve();

    };








    class MyTestClientHandler: public ClientHandler{
        FileCacheManager file_cache_manager;
        Solver solver(){

        }
        void handlerClient(ofstream outputStream,ifstream inputStream );
    };




}



#endif //UNTITLED_SERVER_SIDE_H

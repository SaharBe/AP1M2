//
// Created by sahar on 13/01/2020.
//

#include <iostream>
#include <fstream>
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

    class Solver{
    public:
        void solve();

    };

   /* class MyTestClientHandler: public ClientHandler{
        Solver solver();

       // virtual  void handlerClien(&ofstream outputStream,&ifstream inputStream );
    };*/

    class CacheManager{
    public:
        bool DoesSolutionExist();
        void returnSolution();
        void SaveSolution();

    };

    class FileCasheManager: public CacheManager{
    public:
        bool DoesSolutionExist(string problem);
        void returnSolution();
        void SaveSolution();
    };






#endif //UNTITLED_SERVER_SIDE_H

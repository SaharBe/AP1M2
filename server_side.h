//
// Created by sahar on 13/01/2020.
//

#include <iostream>
#include <fstream>

using namespace std

#ifndef UNTITLED_SERVER_SIDE_H
#define UNTITLED_SERVER_SIDE_H

namespace server_side{

    class ClientHandler{
        void handlerClien(&ofstream outputStream,&ifstream inputStream );
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
        Solver solver(){

        }
        void handlerClien(&ofstream outputStream,&ifstream inputStream );
    };

    class CacheManager{
        bool DoesSolutionExist();
        void returnSolution();
        void SaveSolution();

    }

    class FileCasheManager: public CacheManager{
        bool DoesSolutionExist(string problem);
        void returnSolution();
        void SaveSolution();
    }


}



#endif //UNTITLED_SERVER_SIDE_H

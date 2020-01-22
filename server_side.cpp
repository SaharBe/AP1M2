//
// Created by sahar on 13/01/2020.
//

#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "server_side.h"





using namespace std;





void MySerialServer:: threadLoop(int streamSocket){

   clientHandler.handleClient(streamSocket,streamSocket);


    }

}

void  MySerialServer :: open(int port){
    int socketfd = socket(AF_INET,SOCK_STREAM,0);
    if(socketfd == -1){
        //error
        cerr<<"Could not create a socket"<<endl;
        return;
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    int bind1 = bind(socketfd, (struct sockaddr *) &address, sizeof(address));
    if (bind1 == -1) {
        //error
        std:: cerr << "Could not bind the socket to an IP\n" << std:: endl;
        return;
    }
    if(listen(socketfd, 1) == -1){
        cerr << "Error during listening command\n" << std:: endl;
    }
    struct timeval tv;
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);


    while(&setsockopt) {
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);

        if (client_socket == -1) {
            //error
             std::cerr << "Error accepting client\n" << std::endl;
            continue;

        }else {
            std::thread t(&MySerialServer::threadLoop, this, client_socket);
            t.join();
        }



    }


}



bool MySerialServer::stop() {
    bool flag = false;
    return flag;
}

 MySerialServer:: MySerialServer() {

}
 MySerialServer::~MySerialServer() {

}


void MySerialServer::start(int port) {

}


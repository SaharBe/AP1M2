
#include "MyParallelServer.h"

#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>



void  MyParallelServer :: open(int port,ClientHandler& c){

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



    std:: vector<std::thread> threadVector;
    while(continueFlag) {
        timeval tv;
        tv.tv_sec = 30;
        tv.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);


        if (client_socket = -1){
            if(!continueFlag){
                break;
            }
            if(errno == EWOULDBLOCK){
                continue;
            }
            else{
                throw invalid_argument("error reading from client");
            }



        }
        else {
            std::thread t(&ClientHandler::handlerClient, &c, client_socket, client_socket);
            threadVector.emplace_back(move(t));
            t.detach();
        }



    }
    for(auto&thread : threadVector){
        thread.join();
    }


}



bool MyParallelServer::stop(int socket) {
    continueFlag = false;
    return continueFlag;
}
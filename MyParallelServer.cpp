
#include "MyParallelServer.h"

#include <iostream>
#include <thread>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>


void *MyParallelServer::activeClientHandler( void *arg) {
    clientData* data = (clientData*)arg;
    data->client->handlerClient(data->socket,data->socket);
    delete(data);
    return nullptr;

}

void  MyParallelServer :: open(int port,ClientHandler* c){


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
    int optval = 1;
    int bind1 = bind(socketfd, (struct sockaddr *) &address, sizeof(address));
    if (bind1 == -1) {
        //error
        std:: cerr << "Could not bind the socket to an IP\n" << std:: endl;
        return;
    }


    if(listen(socketfd, SOMAXCONN) == -1){
        cerr << "Error during listening command\n" << std:: endl;
    }




    vector<pthread_t> threadVector;
    while(continueFlag) {

        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);


        if (client_socket == -1){
            if(!continueFlag){
                break;
            }
            if(errno == EWOULDBLOCK){
                continue;
            }
            else{
                close(socketfd);
                throw invalid_argument("error reading from client");
            }



        }
        else {




           clientData* clientData1;
           clientData1 = new clientData();
           clientData1->client = c;
           clientData1->socket = client_socket;

            pthread_t singleThread;
           pthread_create(&singleThread,nullptr,activeClientHandler,clientData1);
           threadVector.push_back(singleThread);
            timeval timeout;
            timeout.tv_sec = 1;
            timeout.tv_usec = 0;
            setsockopt(port, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));



        }



    }

    for (int i = 0; i < threadVector.size(); i++) {
        pthread_join(threadVector[i], nullptr);
    }


}


bool MyParallelServer::stop(int socket) {

    continueFlag = false;
    close(socket);
    return continueFlag;
}
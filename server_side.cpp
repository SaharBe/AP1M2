
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



void MyTestClientHandler::handlerClient(ofstream outputStream, ifstream inputStream) {
  while(true){
    char question[1024];
    inputStream.getline(question,1024);
    //if question in empty,the client didnt sent a question yet,keep waiting for it
    if(strlen(question) == 0){
      continue;
    }
    //if client sent in the stream "end",go back to server which waiting for other client
    if(question == "end"){
      break;
    }
    //else,there is a question and write the answer to the output stream
    else{
      char answer[] = file_cache_manager.returnSolution(question);
      outputStream.write(answer,answer.length());
    }
  }
}


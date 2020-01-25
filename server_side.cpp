#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include "server_side.h"

#include "Solver.h"

using namespace std;

//using namespace server_side;

void MySerialServer:: threadLoop(int streamSocket,ClientHandler c){

   c.handlerClient(streamSocket,streamSocket);


}

}

void  MySerialServer :: open(int port,ClientHandler c){

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

            std::thread t(&MySerialServer::threadLoop, this, client_socket,c);

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




void MyTestClientHandler::handlerClient(int outputStream, int inputStream) {
  while(true){
    char question[1024];
    int valRead = read(inputStream, question, 1024);
    if(valRead ==-1){
        cout << "error in reading" << endl;
        return;
    }

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

        WriteAnswerToClient(outputStream,question);

    }
}

namespace boot{

    class Main{

        int main(int argc, char* args[]) {
          int port = stoi(args[0]);

          Server* server = new MySerialServer();


          Solver* solver = new Solver<P,s> ();
          ClientHandler* clientHandler = new ClientHandler(solver,
          server(clientHandler);

          server->open(port, reinterpret_cast<ClientHandler &&>(clientHandler));

        //  ObjectAdapter objectAdapter;
          CacheManager* cacheManager = new FileCacheManager;


        }



    };

}


void MyTestClientHandler::WriteAnswerToClient(int outPutStream,string question) {
    string answer;
    if(file_cache_manager.DoesSolutionExist(question)) {
        string answer = file_cache_manager.returnSolution(question);
    }
    else{
        string answer = stringRevers.getstring(question);
    }
    int valWrite = write(outPutStream,answer.c_str(), answer.length());
}


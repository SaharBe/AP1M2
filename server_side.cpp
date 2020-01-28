#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include "server_side.h"

#include "Solver.h"

using namespace std;

//using namespace server_side;




void  MySerialServer :: open(int port,ClientHandler& c){

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




    while(continueFlag) {
        timeval tv;
        tv.tv_sec = 10;
        tv.tv_usec = 0;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);

        if (client_socket == -1){

            if(!continueFlag){
                break;
            }
            if(errno == EWOULDBLOCK){
                continue;
            }

            else{
                throw invalid_argument("error connecting to client.EWOULDBLOCK should have been set to true");
            }


        }else {

            std::thread t(&ClientHandler::handlerClient, &c, client_socket, client_socket);

            t.join();
        }



    }


}



bool MySerialServer::stop(int socket) {
    continueFlag = false;
    return continueFlag;
}

MySerialServer:: MySerialServer() {

}
MySerialServer::~MySerialServer() {

}





void MyTestClientHandler::handlerClient(int outputStream, int inputStream) {
    while (true) {
        char question[1024];
        int valRead = read(inputStream, question, 1024);
        if (valRead == -1) {
            cout << "error in reading" << endl;
            return;
        }

        //if question in empty,the client didnt sent a question yet,keep waiting for it
        if (strlen(question) == 0) {
            continue;
        }
        //if client sent in the stream "end",go back to server which waiting for other client
        if (question == "end") {
            break;
        }
            //else,there is a question and write the answer to the output stream
        else {

         //   WriteAnswerToClient(outputStream, *question);


        }
    }
}






void MyTestClientHandler::WriteAnswerToClient(int outPutStream,string question) {

    if(file_cache_manager.DoesSolutionExist(question)) {

     //   Solution answer = file_cache_manager.returnSolution(question);
    }
    else{
      //   answer = stringRevers.solve(question);


    }
    //int valWrite = write(outPutStream,answer.c_str(), answer.length());
}

void MyClientHandler::handlerClient(int outputStream, int inputStream) {
    string line = "";
    string problem;
    char buffer[1024];
    char c;
    int i;
    bool end = false;

    while (!end) {

        int valRead = recv(inputStream, buffer, 1024, 0);
        if (valRead == -1) {
            cout << "error in reading" << endl;
            return;
        }
        for (i = 0; i < valRead; i++) {
            c = problem[i];
            if (c == '\n') {
                problem += line + "\n";
                line="";
                continue;
            }

            if (!line.compare("end")) {
                end = true;
                break;
            }
            line += c;
            continue;
        }
    }
    string solution;
    if (cacheManager->DoesSolutionExist(problem)){
        solution =cacheManager->returnSolution(problem);
    }
    else {
        solution = solver->solve(problem);
    }
    solution+="\n";
   if(!write(outputStream,solution.c_str(),solution.length()));{
       throw "error in writing to client";
   }
}

int boot::Main::main(int argc, char *args[]) {
    int port = stoi(args[0]);

    Server* server = new MySerialServer();

    string sahar = "sahar";


    // Solver<string,string> solver = new StringRevers ();
    //  ClientHandler< testClientHandler = new MyTestClientHandler();



    //  ObjectAdapter objectAdapter;



}




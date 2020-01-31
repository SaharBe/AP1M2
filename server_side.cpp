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


void  MySerialServer :: open(int port,ClientHandler* c){

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

            std::thread t(&ClientHandler::handlerClient, c, client_socket, client_socket);

            t.join();
        }



    }


}



bool MySerialServer::stop(int socket) {
    continueFlag = false;
    close(socket);
    return continueFlag;
}

MySerialServer:: MySerialServer() {

}
MySerialServer::~MySerialServer() {

}


string MyTestClientHandler::fromCharToString(char *question) {
    string questionString = "";
    int i = 0;
    char c;
    do {

        c = question[i];
        questionString += c;
        i++;


    } while (c != '\0');
    return questionString;
}

void MyTestClientHandler::handlerClient(int outputStream, int inputStream) {
    while (true) {
        char question[1024];
        string stringQuestion;
        int valRead = read(inputStream, question, 1024);
        stringQuestion = fromCharToString(question);
        stringQuestion = stringQuestion.erase(stringQuestion.find("\r"));
        if (valRead == -1) {
            cout << "error in reading" << endl;
            return;
        }

        //if question in empty,the client didnt sent a question yet,keep waiting for it
        if (stringQuestion .length() == 0) {
            continue;
        }
        //if client sent in the stream "end",go back to server which waiting for other client
        if (stringQuestion  == "end") {
            break;
        }
            //else,there is a question and write the answer to the output stream
        else {


            WriteAnswerToClient(outputStream, stringQuestion );


        }
    }
}






void MyTestClientHandler::WriteAnswerToClient(int outPutStream,string question) {
    string answer;
    if(cacheManager->DoesSolutionExist(question)) {
        answer = cacheManager->returnSolution(question);
    }
    else{

        answer = solver->solve(question);
        cacheManager->SaveSolution(question,answer);

    }
    answer+="\r\n";
    write(outPutStream,answer.c_str(),answer.length());



}

void MyClientHandler::handlerClient(int outputStream, int inputStream) {
    string line = "";
    string problem = "";
    char buffer[1024];
    char c;
    int i;
    bool end = false;

    while (!end) {
        int valRead = recv(inputStream, buffer, sizeof(buffer), 0);

        if (valRead == -1) {
            cout << "error in reading" << endl;
            return;
        }
        for (i = 0; i < valRead; i++) {

            if (!(line.compare("end"))){
                end = true;
                break;
            }
            c = buffer[i];
            if (c == '\n') {
                problem += line + ",\n";
                line="";
                continue;
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
        cacheManager->SaveSolution(problem,solution);
    }
    solution+="\n";
    if(!write(outputStream,solution.c_str(),solution.length()));{
        throw "error in writing to client";
    }
}
namespace boot{
//int boot::Main::
int main(int argc, char *args[]) {
    double port = stod(args[1]);

    Server *server = new MySerialServer();
    //  StringRevers stringRevers;
    //FileCacheManager fc;


    server->open(port, new MyTestClientHandler(new StringRevers, new FileCacheManager));


    server->stop(port);
    delete (server);
    return 0;

}
}
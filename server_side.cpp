

#include "server_side.h"

using namespace server_side;

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

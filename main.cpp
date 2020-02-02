
#include "Server.h"
#include "MyParallelServer.h"
#include "MatrixSolver.h"
#include "Searcher.h"
#include "AStar.h"

#include "BFS.h"
#include "DFS.h"
#include "Node.h"


int main(int numArg, char *args[]) {
    int port;
    if(numArg==2){
        port = stod(args[1]);
    }
    else{
        port = 5600;
    }


    MyParallelServer server;
    BFS<Node> searcher;






    server.open(port, new MyClientHandler(new MatrixSolver(&searcher), new FileCacheManager));
        server.stop(port);



    return 0;
}
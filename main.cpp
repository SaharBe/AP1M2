
#include "Server.h"
#include "MyParallelServer.h"
#include "MatrixSolver.h"
#include "Searcher.h"
#include "AStar.h"

#include "BFS.h"
#include "DFS.h"
#include "Node.h"


int main(int numArg, char *args[]) {

    double port = 8023;
    MyParallelServer server;
    DFS<Node> searcher;






    server.open(port, new MyClientHandler(new MatrixSolver(&searcher), new FileCacheManager));
        //this_thread::sleep_for(chrono::milliseconds(100000));
        server.stop(port);



    return 0;
}
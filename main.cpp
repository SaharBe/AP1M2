//
// Created by sahar on 30/01/2020.
//
#include "Server.h"
#include "MyParallelServer.h"
#include "MatrixSolver.h"
#include "Searcher.h"
#include "AStar.h"
#include "BestFS.h"
#include "BFS.h"
#include "DFS.h"
#include "Node.h"


int main(int numArg, char *args[]) {

    double port = stod(args[1]);
    MyParallelServer server;

  //  BFS<Node>* searcher;

  MatrixSolver matrixSolver(new BFS<Node> );
   string str = "1,2,3\n4,5,6\n7,8,9\n(0,0)\n(2,2)\nend";
   matrixSolver.solve(str);

   /*  server.open(port, new MyClientHandler(new MatrixSolver(searcher), new FileCacheManager));
        //this_thread::sleep_for(chrono::milliseconds(100000));
        server.stop(port); */



    return 0;
}
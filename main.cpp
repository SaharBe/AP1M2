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
   string str = "14,10,16,4,17,2,11,15,5,-1\n1,10,6,10,2,7,4,15,1,2\n2,13,3,8,15,20,11,17,12,19\n5,7,14,6,18,13,20,2,8,5\n4,15,-1,20,15,7,11,12,19,2\n4,4,18,14,16,1,-1,1,18,15\n10,5,1,10,17,19,18,0,15,9\n15,10,20,15,0,2,20,3,0,13\n13,2,19,2,-1,8,-1,7,19,15\n-1,12,5,1,5,9,18,11,-1,5\n(0,0)\n(9,9)\nend";
   matrixSolver.solve(str);

   /*  server.open(port, new MyClientHandler(new MatrixSolver(searcher), new FileCacheManager));
        //this_thread::sleep_for(chrono::milliseconds(100000));
        server.stop(port); */



    return 0;
}
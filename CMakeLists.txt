cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)


add_executable(untitled server_side.cpp server_side.h Searchable.h Searcher.h State.h BestFS.h DFS.h BFS.h AStar.h CacheManager.h CacheManager.cpp Solver.h StringRevers.cpp StringRevers.h Matrix.h MyParallelServer.cpp MyParallelServer.h Node.cpp Node.h PathNode.cpp PathNode.h MatrixSolver.h CostComparator.h Position.h)




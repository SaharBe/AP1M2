cmake_minimum_required(VERSION 3.15)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)


add_executable(untitled server_side.cpp server_side.h Searchable.h Searcher.h State.cpp State.h BFS.h DFS.h BreadthFirstSearch.h AStar.h CacheManager.h Solver.h ObjectAdapter.cpp ObjectAdapter.h Matrix.cpp Matrix.h MyParallelServer.cpp MyParallelServer.h)



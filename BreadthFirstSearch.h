//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_BREADTHFIRSTSEARCH_H
#define UNTITLED_BREADTHFIRSTSEARCH_H

#include <iostream>
#include <unordered_map>
#include <hash_map>
#include <vector>
#include <queue>

#include "Searchable.h"
#include "Searcher.h"
#include "State.h"


using namespace std;

template <class T>
class BreadthFirstSearch: public Searcher<T> {

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    visited[i] = false;

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }


}


#endif //UNTITLED_BREADTHFIRSTSEARCH_H

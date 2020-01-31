//
// Created by sahar on 22/01/2020.
//

#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#include "Searchable.h"
#include "Searcher.h"
#include "State.h"
#include <map>

using namespace std;

template <class T>
class BFS: public Searcher<T> {

    vector<State<T>> search (const Searchable<T>& searchable){
        map<State<T>, bool> visited;
        map<State<T>, State<T>> parents;
        queue<State<T>> stateQueue;
        vector<State<T>> solutionStateList;

        stateQueue.push(searchable.getInitialState());

        while(!stateQueue.empty()) {
            State<T> curState = stateQueue.front();
            stateQueue.pop();
            visited[curState] = true; /// yakir

            if ( curState != searchable.getGoalState()) {
                vector<State<T>> possibleStates = searchable.getAllPossibleStates(curState);


                for (int i = 0; i < possibleStates.size(); i++) {
                    State<T> stateFromList = possibleStates[i];
                    if (visited.count(stateFromList) == 0) {

                        stateQueue.push(stateFromList); /// yakir
                        parents[stateFromList] = curState;
                    }
                }
            } else {
                State<T>& stateToAdd = curState;

                while (parents.count(stateToAdd) != 0) {
                    solutionStateList.insert(solutionStateList.begin(), stateToAdd);
                    stateToAdd = parents[stateToAdd];

//                    typename std::vector<State<T>>::iterator it; /// yakir
//                    it = solutionStateList.begin();
//                    it = solutionStateList.insert ( it , curState );
//
//                    State<T>* tmp =  parents.at(&curState); /// yakir
//                    curState = *tmp; /// yakir
                }

                solutionStateList.insert(solutionStateList.begin(), stateToAdd);
//                typename std::vector<State<T>>::iterator it;
//                it = solutionStateList.begin();
//                it = solutionStateList.insert ( it , curState );

                break;
            }
        }

        return solutionStateList;
    }

/*
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
    } */


};


#endif //UNTITLED_BFS_H
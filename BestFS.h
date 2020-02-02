
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <set>
#include "Searcher.h"
#include "CostComparator.h"
#include "State.h"
#include <unordered_set>

#include <vector>

//template <typename T>
struct CompareCosrr {
    bool operator()(const State<Node> & c1, const State<Node> & c2) {
        return c1.getCost() > c2.getCost();
    }
};

template <class T>
class BestFS : public Searcher<T> {

public:



  vector<State<Node>> backTrace(State<Node> s, map<State<T>, State<T>>& cameFrom,State<T> initialState) {

          vector<State<Node> > backTracevector;
          State<Node>& state = s;
          ///enter all the back Trace to the vector
          while (state != initialState) {
              backTracevector.insert(backTracevector.begin(), state);
              state = cameFrom[state];
          }
          //return all back trace
          backTracevector.insert(backTracevector.begin(), state);
          return backTracevector;
  }

   // template <T>
    bool findInOpen(const priority_queue<State<Node>, vector<State<Node>>, CompareCosrr>& que, State<Node> state){
        priority_queue<State<Node>, vector<State<Node>>, CompareCosrr> temp = que;
        while(!temp.empty()) {
            if (state != temp.top()) {
                temp.pop();
            } else {
                return true;
            }
        }
        return false;
   }
    double costBetweenNodes(State<Node> start, State<Node> end) {
        return start.getCost() + end.getOriginalCost();
    }

    void erase( priority_queue<State<Node>, vector<State<Node>>, CompareCosrr> &que, State<Node> state){
        priority_queue<State<Node>, vector<State<Node>>, CompareCosrr> newQ ;

        while(que.top() != state){
            newQ.push(que.top());
            que.pop();
        }
        que.pop();
        while(!que.empty()){
            newQ.push(que.top());
            que.pop();
        }
        que = newQ;
    }






    virtual vector<State<Node>> search (const Searchable<Node>& searchable)  {
        priority_queue<State<Node>, vector<State<Node>>, CompareCosrr> open; //
        map<State<T>, State<T>> cameFrom;
        open.push(searchable.getInitialState());
        set <State<Node>> closed;
        State<Node> p =        searchable.getInitialState();
        cameFrom[searchable.getInitialState()] = searchable.getInitialState();

        while (!open.empty()) {
            State<Node> n = open.top();
            closed.insert(n);
            open.pop();
            if (n == searchable.getGoalState()) {
                return backTrace(n, cameFrom, searchable.getInitialState());; //backTrace(searchable.getGoalState());
              cout << n.getCost()<< endl;
            }
            vector<State<Node>> successor = searchable.getAllPossibleStates(n);
            for (State<Node> succ : successor) {
                if (closed.find(succ) == closed.end() && !findInOpen(open, succ)) {
                //    succ.setCameFrom(n);
                    cameFrom[succ] = n;
                    open.push(succ);

                }else {
                    double cost = costBetweenNodes(n, succ);
                    if (cost < succ.getCost()) {// If there is a better path - update cost;

                        // If it's a new path
                        //State<Node> *t = succ.getCameFrom();
                        State<Node> t = cameFrom[succ];
                     //   if (*t != n) {
                        if(t != n) {
                        //    succ.setCameFrom(n);
                            cameFrom[succ] = n;
                            // It's the same path as before - remove the node and insert back to update priority
                        } else {
                            erase(open, succ);
                            closed.insert(succ);
                        }
                    }
                }

            }

        }
   }

/***/
};


#endif//EX4_BESTFS_H

    /*State<T> popFromOpen(multiset<State<T> , CostComparator<T>> &open) {
        this->evaluatedNodes++;

        State<T> x = *(open.begin());
        open.erase(x);
        return x;
    }*/



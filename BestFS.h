
#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <set>
#include "Searcher.h"
#include "CostComparator.h"
#include "State.h"

template<class T>
class BestFS : public Searcher<T> {

public:
    vector<State<T>> backTrace(State<T> s) {
        vector<State<T> > backTracevector;
        State<T>* state = &s;
        ///enter all the back Trace to the vector
        while (state->getCameFrom() != nullptr) {
            backTracevector.insert(backTracevector.begin(), s);
            state = state->getCameFrom();
        }
        ///
        if (backTracevector.empty()) {
            return backTracevector;
        }
        //return all back trace
        backTracevector.insert(backTracevector.begin(), s);
        return backTracevector;
    }

    virtual vector<State<T>> search(const Searchable<T>& searchable) {
        multiset<State<T> , CostComparator<T>> open;
        set<State<T>> closed;

        State<T> curr = searchable.getInitialState();
        open.insert(curr);

        while (!open.empty()) {
            curr = popFromOpen(open);
            closed.insert(curr);
            if (curr == searchable.getGoalState()) {
                break;
            }

            vector<State<T>> successors = searchable.getAllPossibleStates(curr);
            for (State<T> succ : successors) {
                // Ignoring walls
                if (succ.getCost() < 0) {
                    continue;
                }
                if (closed.find(succ) != closed.end()) {
                    continue;
                }
                // If 'succ' isn't in any of the lists - update it and add to 'open'
                if (open.find(succ) == open.end()) {
                    succ.setCameFrom(curr);
                    succ.setCost(succ.getCost() + curr.getCost());
                    open.insert(succ);
                    continue;
                }
                // If there is a better path - update cost
                double cost = costBetweenNodes(curr, succ);
                if (cost < succ.getCost()) {
                    succ.setCost(cost);

                    // If it's a new path
                    if (succ.getCameFrom() != &curr) {
                        succ.setCameFrom(curr);
                        // It's the same path as before - remove the node and insert back to update priority
                    } else {
                        open.erase(succ);
                        open.insert(succ);
                    }
                }
            }
        }

        State<T> goal = searchable.getGoalState();
        vector<State<T>> b = backTrace(goal);
        return b;
    }


    State<T> popFromOpen(multiset<State<T> , CostComparator<T>> &open) {
        this->evaluatedNodes++;

        State<T> x = *(open.begin());
        open.erase(x);
        return x;
    }


    double costBetweenNodes(State<T> start, State<T> end) const {
        return start.getCost() + end.getOriginalCost();
    }
};

#endif //EX4_BESTFIRSTSEARCH_H
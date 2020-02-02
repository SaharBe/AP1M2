
#ifndef UNTITLED_ASTAR_H
#define UNTITLED_ASTAR_H


#include "BestFS.h"
#include "State.h"
#include "Node.h"


class Heuristic {

public:
    virtual ~Heuristic() {}
    virtual void setGoal(const State<Node>& goal) = 0;
    virtual double evaluateFromNode(const State<Node>& current) = 0;
};

class Distance{
    State<Node> goal;

public:
    virtual void setGoal(const State<Node>& goal)  {
        this->goal = goal;
    }

    virtual double evaluateFromNode(const State<Node>& current) const {
        double val;
        val = abs(goal.getState().getCol() - current.getState().getCol());
        val += abs(goal.getState().getRow() - current.getState().getRow());
        return val;
    }
};


class AStar : public BestFS<Node>{
    Distance distance;

protected:
    virtual double costBetweenNodes(const State<Node> &start, const State<Node>&end) const {
        if (start == end) {
            return distance.evaluateFromNode(end);
        }
        return start.getCost() + end.getOriginalCost();
    }

public:

    virtual ~AStar() {}

    virtual vector<State<Node>> search (const Searchable<Node>& searchable) {
        distance.setGoal(searchable.getGoalState());
        return BestFS<Node>::search(searchable);
    }
};

#endif //UNTITLED_ASTAR_H

//
// Created by sahar on 21/01/2020.
//

#ifndef UNTITLED_SEARCHABLE_H
#define UNTITLED_SEARCHABLE_H
#include <list>
#include <deque>
#include <iostream>
#include <vector>

#include "State.h"


template <class T>
class Searchable {
public:
 virtual State<T> getInitialState() const = 0;
 virtual State<T> getGoalState() const = 0;
 virtual std::vector<State<T>> getAllPossibleStates(const State<T>& state) const = 0;

};



#endif //UNTITLED_SEARCHABLE_H

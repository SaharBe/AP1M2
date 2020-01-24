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
 virtual State<T> getInitialState();
 virtual State<T> getGoalState();
 virtual  std::vector<State<T>*> getAllPossibleStates(State<T> state);

};



#endif //UNTITLED_SEARCHABLE_H

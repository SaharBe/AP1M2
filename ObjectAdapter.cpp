//
// Created by sahar on 23/01/2020.
//

#include "ObjectAdapter.h"
string StringRevers::getstring(string str) {
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    return  str;

}



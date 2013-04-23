/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * patterns_common.cpp
 *
 * commnonly used funcions
 */

#include "patterns_common.h"
#include "Point.h"
#include "deque.h"
#include "patterns_algorithm.h"
#include <iostream>

using std::istream;
using std::ostream;
using std::endl;

Point* readPoints(istream& is, int *size) {
    Point *p_arr;
    int i, s;
    is >> s;
    if(size) {
        *size = s;
    }

    p_arr = new Point[s];
    for(i = 0; i < s; i++) {
        is >> p_arr[i];
    }

    return p_arr;
}

void printLines(ostream& os, Deque<LineSeg>& result) {
    Deque<LineSeg>::Iterator itr(result);
    int i, s = result.size();

    for(i = 0; i < s; i++, itr++) {
        os << (*itr) << endl;
    }
}

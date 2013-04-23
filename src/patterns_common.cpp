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

int readInt(istream& is) {
    char c;
    int i;
    while(c = is.get(), c < '0' || c > '9') {
    }
    i = c - '0';
    while(c = is.get(), c >= '0' && c <= '9' && is.good()) {
        i = i * 10 + c - '0';
    }
    return i;
}

Point* readPoints(istream& is, int *size) {
    Point *p_arr;
    int i, s, t;
    is >> s;
    if(size) {
        *size = s;
    }

    p_arr = new Point[s];
    for(i = 0; i < s; i++) {
        t = readInt(is);
        p_arr[i].setX(t);
        t = readInt(is);
        p_arr[i].setY(t);
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

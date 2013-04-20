/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Brute.cpp
 *
 * The brute force version of pattern check
 */

#include "pattern_algorithm.h"
#include "Point.h"
#include "Vector2D.h"
#include "deque.h"
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
    int i;
    deque<LineSeg> res;
    deque<LineSeg>::Iterator itr(res);
    Point *p_arr;
    int size;
    ifstream is("input.txt", ifstream::in);
    is >> size;
    p_arr = new Point[size];

    for(i = 0; i < size; i++) {
        is >> p_arr[i];
    }

    res = Brute(p_arr, size);

    for(i = 0; i < res.size(); i++, itr++) {
        cout << (*itr) << endl;
    }
    delete [] p_arr;
    return 0;
}

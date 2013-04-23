/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Fast.cpp
 *
 * The fast version of pattern check
 */

#include "patterns_algorithm.h"
#include "patterns_common.cpp"
#include "Point.h"
#include "Vector2D.h"
#include "deque.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char **argv) {
    Deque<LineSeg> res;
    Point *p_arr;
    int size;
    ifstream is("input.txt", ifstream::in);

    p_arr = readPoints(is, &size);
    res = Fast(p_arr, size);
    printLines(cout, res);

    delete [] p_arr;
    return 0;
}

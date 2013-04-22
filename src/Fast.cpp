/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Point.cpp
 *
 * The implementation of point
 */

#include "Point.h"
#include "computational_geometry.h"

bool isCollinear(const Point &p1, const Point &p2) const {
    //Collinear if sin<p1-this, p2-this> = 0
    return ((p1 - (*this)).cross(p2 - (*this))) == 0;
}

int main(int argc, char **argv) {
    int i;
    Deque<LineSeg> res;
    Deque<LineSeg>::Iterator itr(res);
    Point *p_arr;
    int size;
    ifstream is("input.txt", ifstream::in);
    is >> size;
    p_arr = new Point[size];

    for(i = 0; i < size; i++) {
        is >> p_arr[i];
    }

    res = Fast(p_arr, size);

    for(i = 0; i < res.size(); i++, itr++) {
        cout << (*itr) << endl;
    }
    delete [] p_arr;
    return 0;
}

/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * pattern_algorithm.h
 *
 * The header file for algorithms of patterns
 */

#ifndef _PATTERN_ALGORITHM_H
#define _PATTERN_ALGORITHM_H

#include "Point.h"
#include "deque.h"
#include <iostream>
#include <algorithm>
#include <cstring>

using std::ostream;
using std::sort;

//Line segment
class LineSeg {
    public:
        /* default constructor/destructor */
        LineSeg();
        ~LineSeg();
        
        /* conversion constructor */
        LineSeg(int);
        
        /* operator[] for iterate */
        Point& operator[](int) const;

        /*
         * getSize
         *
         * return the number of point on this line segment
         */
        int getSize();
        
    private:
        Point** arr_point;
        int size;
        
};

//Reload output
ostream& operator<<(ostream&, const LineSeg&);

/*
 * Brute
 *
 * point_list: the array of point to solve
 * size: the size of the point_list
 *
 * processing the point_list using Brute Force method and return a deque
 * of LineSeg meeting requirement
 */
typename deque<LineSeg> Brute(Point* point_list, int size);

/*
 * Brute
 *
 * point_list: the array of point to solve
 * size: the size of the point_list
 *
 * processing the point_list using Fast method and return a deque
 * of LineSeg meeting requirement
 */
typename deque<LineSeg> Fast(Point* point_list, int size);

#endif

/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * patterns_algorithm.h
 *
 * The header file for algorithms of patterns
 */

#ifndef _PATTERNS_ALGORITHM_H
#define _PATTERNS_ALGORITHM_H

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
       
        /* copy constructor */
        LineSeg(const LineSeg&);

        /* conversion constructor */
        LineSeg(int);
        
        /* operator[] for iterate */
        Point*& operator[](int);
        Point* const& operator[](int) const;

        /*
         * getSize
         *
         * return the number of point on this line segment
         */
        int getSize() const;
        
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
Deque<LineSeg> Brute(Point* point_list, int size);

/*
 * Brute
 *
 * point_list: the array of point to solve
 * size: the size of the point_list
 *
 * processing the point_list using Fast method and return a deque
 * of LineSeg meeting requirement
 */
Deque<LineSeg> Fast(Point* point_list, int size);

#endif

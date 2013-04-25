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

        /* assign operator */
        LineSeg& operator=(const LineSeg&);
        
        /* operator[] for iterate */
        inline Point*& operator[](int);
        inline Point* const& operator[](int) const;

        /*
         * getSize
         *
         * return the number of point on this line segment
         */
        inline int getSize() const;
        
    private:
        Point** arr_point;
        int size;
        
};

//Reload output
ostream& operator<<(ostream&, const LineSeg&);

class Brute {
    public:
        Brute();
        ~Brute();

        /* conversion constructor */
        Brute(Point* p, int s);

        /*
         * Run
         *
         * processing the point_list using Brute Force method and return a deque
         * of LineSeg meeting requirement
         */
        Deque<LineSeg> Run();

    private:
        Point* point_list;
        int size;
};

class Fast {
    public:
        Fast();
        ~Fast();

        /* conversion constructor */
        Fast(Point* p, int s);

        /*
         * Run
         *
         * processing the point_list using Fast method and return a deque
         * of LineSeg meeting requirement
         */
        Deque<LineSeg> Run();

    private:
        Point* point_list;
        int size;
};

//Include those inline functions
inline Point*& LineSeg::operator[](int idx) {
    if(idx < 0 || idx >= size) {
        throw runtime_error("Out of range");
    }
    return arr_point[idx];
}

inline Point* const& LineSeg::operator[](int idx) const {
    if(idx < 0 || idx >= size) {
        throw runtime_error("Out of range");
    }
    return arr_point[idx];
}

inline int LineSeg::getSize() const {
    return size;
}

#endif

/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Point.h
 *
 * The header file for Point, an ADT for points
 */

#ifndef _POINT_H
#define _POINT_H

#include "Vector2D.h"
#include <qcolor.h>
#include <qpainter.h>
#include <iostream>

using std::istream;
using std::ostream;

//Point can be regarded as one kind of Vector
class Point: public Vector2D {
    public:
        /*
         * isCollinear
         *
         * p1: the first point to compare
         * p2: the second point to compare
         *
         * return whether the three points are collinear
         */
        bool isCollinear(const Point &p1, const Point &p2) const;
        
        /*
         * draw
         *
         * painter: the painter alive
         * scaleX: the scale to transform x-coordinate
         * scaleY: the scale to transform y-coordinate
         * leftX: the transformed origin x
         * bottomY: the transformed origin y
         *
         * draw a point
         */
        void draw(QPainter *painter, double scaleX, double scaleY, int leftX, int bottomY) const;
        
        /*
         * drawTo
         *
         * p: the point to draw to
         * painter: the painter alive
         * scaleX: the scale to transform x-coordinate
         * scaleY: the scale to transform y-coordinate
         * leftX: the transformed origin x
         * bottomY: the transformed origin y
         *
         * draw a line between this line and the p
         */
        void drawTo(const Point& p, QPainter *painter, double scaleX, double scaleY, int leftX, int bottomY) const;
        
};

//Reload Input and Output stream
istream& operator>>(istream&, Point&);
ostream& operator<<(ostream&, const Point&);

//Comparator to compare two Point
class Comparator {
    public:
        /* default constructor/destructor */
        Comparator();
        ~Comparator();
        
        /* conversion constructor */
        Comparator(const Point&);
        
        /* reload operator() to act as a function object */
        bool operator()(const Point&, const Point&) const;
        
    private:
        Point origin;
};

#endif

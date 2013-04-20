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

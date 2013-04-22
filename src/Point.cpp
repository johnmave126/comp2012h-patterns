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
#include "Vector2D.h"
#include <qcolor.h>
#include <qpainter.h>

bool Point::isCollinear(const Point &p1, const Point &p2) const {
    //Collinear if sin<p1-this, p2-this> = 0
    return (( (p1 - (*this)) ^ (p2 - (*this)) ) == 0);
}

void Point::draw(QPainter *painter, double scaleX, double scaleY, int leftX, int bottomY) const {
    painter->setBrush(QColor(29, 37, 183));
    painter->drawEllipse( static_cast<int>(x * scaleX + leftX), static_cast<int>(bottomY - y * scaleY), 6, 6);
}

void Point::drawTo(const Point& p, QPainter *painter, double scaleX, double scaleY, int leftX, int bottomY) const {
    painter->drawLine(static_cast<int>(x * scaleX + leftX), static_cast<int>(bottomY - y * scaleY),
                    p.x * scaleX + leftX, bottomY - p.y * scaleY);
}

istream& operator>>(istream& is, Point& p) {
    int x, y;
    is >> x >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << " (" << p.getX() << ", " << p.getY() << ") ";
    return os;
}

Comparator::Comparator()
:origin(Point()) {
}

Comparator::~Comparator() {
}

Comparator::Comparator(const Point &p)
:origin(p) {
}

bool Comparator::operator()(const Point &p1, const Point &p2) const {
    Vector2D l1 = p1 - origin, l2 = p2 - origin;
    //Reverse if below y axis
    if(l1.getY() < 0) {
        l1 = -l1;
    }
    else if(l1.getY() == 0 && l1.getX() < 0) {
        l1 = -l1;
    }
    if(l2.getY() < 0) {
        l2 = -l2;
    }
    else if(l2.getY() == 0 && l2.getX() < 0) {
        l2 = -l2;
    }
    return ( (l1 ^ l2) == 0)?(l1 < l2):( (l1 ^ l2) > 0);
}

bool Comparator::operator()(Point* const &p1, Point* const &p2) const {
    //Reuse operator() above
    return this->operator(*p1, *p2);
}

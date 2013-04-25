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
#include <qtextstream.h>

Point::Point()
:Vector2D() {
}

Point::~Point() {
}

Point::Point(const Point &v)
:Vector2D(v) {
}

Point::Point(int px, int py)
:Vector2D(px, py) {
}

void Point::draw(QPainter *painter, double scaleX, double scaleY, int leftX, int bottomY) const {
    painter->setBrush(QColor(29, 37, 183));
    painter->drawEllipse( static_cast<int>(x * scaleX + leftX) - 3, static_cast<int>(bottomY - y * scaleY) - 3, 6, 6);
}

void Point::drawTo(const Point& p, QPainter *painter, double scaleX, double scaleY, int leftX, int bottomY) const {
    painter->drawLine(static_cast<int>(x * scaleX + leftX), static_cast<int>(bottomY - y * scaleY),
                    static_cast<int>(p.x * scaleX + leftX), static_cast<int>(bottomY - p.y * scaleY));
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

QTextStream& operator>>(QTextStream& is, Point& p) {
    int x, y;
    is >> x >> y;
    p.setX(x);
    p.setY(y);
    return is;
}

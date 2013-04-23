/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Vector2D.cpp
 *
 * The implementation of vector
 */

#include "Vector2D.h"

Vector2D::Vector2D()
:x(0), y(0) {
}

Vector2D::~Vector2D() {
}

Vector2D::Vector2D(const Vector2D &v)
:x(v.x), y(v.y) {
}

Vector2D::Vector2D(int px, int py)
:x(px), y(py) {
}

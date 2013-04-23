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

#pragma message("here")

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

inline Vector2D& Vector2D::operator=(const Vector2D &v) {
    x = v.x;
    y = v.y;
    return (*this);
}

inline Vector2D Vector2D::operator+(const Vector2D &v) const {
    return Vector2D(x + v.x, y + v.y);
}

inline Vector2D Vector2D::operator-(const Vector2D &v) const {
    return Vector2D(x - v.x, y - v.y);
}

inline Vector2D Vector2D::operator-() const {
    return Vector2D(-x, -y);
}

inline int Vector2D::operator*(const Vector2D &v) const {
    return (x * v.x) + (y * v.y);
}

inline int Vector2D::operator^(const Vector2D &v) const {
    return (x * v.y) - (y * v.x);
}

inline bool Vector2D::operator==(const Vector2D &v) const {
    return (x == v.x) && (y == v.y);
}

inline bool Vector2D::operator!=(const Vector2D &v) const {
    //Reuse operator==
    return !((*this) == v);
}

inline bool Vector2D::operator<(const Vector2D &v) const {
    return (x == v.x)?(y < v.y):(x < v.x);
}

inline bool Vector2D::operator>=(const Vector2D &v) const {
    //Reuse oeprator<
    return !((*this) < v);
}

inline bool Vector2D::operator>(const Vector2D &v) const {
    return (x == v.x)?(y > v.y):(x > v.x);
}

inline bool Vector2D::operator<=(const Vector2D &v) const {
    //Reuse oeprator>
    return !((*this) > v);
}

inline int Vector2D::dot(const Vector2D &v) const {
    //Reuse operator*
    return (*this) * v;
}

inline int Vector2D::cross(const Vector2D &v) const {
    return (*this) ^ v;
}

inline int Vector2D::getX() const {
    return x;
}

inline int Vector2D::getY() const {
    return y;
}

inline void Vector2D::setX(int px) {
    x = px;
}

inline void Vector2D::setY(int py) {
    y = py;
}

inline Vector2D operator*(const Vector2D& v, int r) {
    return Vector2D(v.getX() * r, v.getY() * r);
}

inline Vector2D operator*(int r, const Vector2D& v) {
    //Reuse operator* of reverse order
    return (v * r);
}

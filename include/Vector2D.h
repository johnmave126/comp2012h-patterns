/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Vector2D.h
 *
 * The header file for Vector2D, containing a set of 
 * utility function of computational geometry
 */

#ifndef _VECTOR2D_H
#define _VECTOR2D_H

class Vector2D {
    public:
        /* default constructor/destructor */
        Vector2D();
        ~Vector2D;
        
        /* copy constructor */
        Vector2D(const Vector2D &);
        
        /* conversion constructor */
        Vector2D(int, int);
        
        /* operator= for Vector2D */
        Vector2D& operator=(const Vector2D&);
        
        /* operator+ for Vector2D */
        Vector2D operator+(const Vector2D&) const;
        
        /* operator-(binary) for Vector2D */
        Vector2D operator-(const Vector2D&) const;
        
        /* operator-(unary) for Vector2D */
        Vector2D operator-() const;
        
        /* operator* as dot multiply for Vector2D */
        int operator*(const Vector2D&) const;
        
        /* operator^ as cross multiply for Vector2D */
        int operator^(const Vector2D&) const;
        
        /* operator==/!= for comparison */
        bool operator==(const Vector2D&) const;
        bool operator!=(const Vector2D&) const;
        
        /* operator</>=/>/<= for comparison */
        /* compare using the coordinate */
        bool operator<(const Vector2D&) const;
        bool operator>=(const Vector2D&) const;
        bool operator>(const Vector2D&) const;
        bool operator<=(const Vector2D&) const;
        
        /*
         * dot
         *
         * p: the vector to be dot multiply to
         *
         * behave same as operator*
         */
        int dot(const Vector2D&) const;
        
        /*
         * cross
         *
         * p: the vector to be cross multiply to
         *
         * return the cross product of two vectors
         */
        int cross(const Vector2D&) const;
        
        /*
         * getX
         *
         * return the x-coordinate of the Vector2D
         */
        int getX() const;
        
        /*
         * getY
         *
         * return the y-coordinate of the Vector2D
         */
        int getY() const;
        
        /*
         * setX
         *
         * px: the coordinate to set
         *
         * set the x-coordinate of the Vector2D
         */
        void setX(int px);
        
        /*
         * setY
         *
         * py: the coordinate to set
         *
         * set the y-coordinate of the Vector2D
         */
        void setY(int py);
        
    private:
        //Two component
        int x, y;
};

/* operator*(binary arithmetic) for Vector2D */
Vector2D operator*(const Vector2D&, int);
Vector2D operator*(int, const Vector2D&);

#endif
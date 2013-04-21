/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * pattern_algorithm.cpp
 *
 * Algorithms of patterns
 */

#include "pattern_algorithm.h"
#include "Point.h"

LineSeg::LineSeg()
:arr_point(NULL), size(0) {
}

LineSeg::~LineSeg() {
    if(arr_point) {
        delete [] arr_point;
    }
}

LineSeg::LineSeg(const LineSeg& l)
:arr_point((l.size > 0)?(new Point*[l.size]):NULL),
 size(l.size) {
    if(size) {
        memcpy(arr_point, l.arr_point, size * sizeof(Point*));
    }
}

LineSeg::LineSeg(int s)
:arr_point(new Point*[s]), size(s) {
    memset(arr_point, 0, sizeof(Point*) * s);
}

Point*& LineSeg::operator[](int idx) {
    if(idx < 0 || idx >= size) {
        throw runtime_error("Out of range");
    }
    return arr_point[idx];
}

int LineSeg::getSize() const {
    return size;
}

ostream& operator<<(ostream& os, const LineSeg& l) {
    int i, s = l.getSize();
    os << s << ":";
    for(i = 0; i < s - 1; i++) {
        os << *l[i] << "->";
    }
    if(i < s) {
        os << *l[i];
    }
    return os;
}

//Used to do a rough sort of Point*
static bool PointCmp(Point* const &a, Point* const &b) {
    return (*a) < (*b);
}

Deque<LineSeg> Brute(Point* point_list, int size) {
    int i, j, k, l;
    Point **sorting_list = new Point*[size];
    Deque<LineSeg> result;

    //Copy the data into the list
    for(i = 0; i < size; i++) {
        sorting_list[i] = &point_list[i];
    }
    //Sort the list to maintain orderness when pushing into LineSeg
    sort(sorting_list, sorting_list + size, PointCmp);

    for(i = 0; i < size; i++) {
        for(j = i + 1; j < size; j++) {
            for(k = j + 1; k < size; k++) {
                //Check if the three point collinear
                if(!sorting_list[i]->isCollinear(*sorting_list[j], *sorting_list[k])) {
                    //Not collinear, pass
                    continue;
                }
                for(l = k + 1; l < size; l++) {
                    if(sorting_list[i]->isCollinear(*sorting_list[j], *sorting_list[l])) {
                        //Add to result
                        LineSeg tmp(4);
                        tmp[0] = sorting_list[i];
                        tmp[1] = sorting_list[j];
                        tmp[2] = sorting_list[k];
                        tmp[3] = sorting_list[l];
                        result.addLast(tmp);
                    }
                }
            }
        }
    }
    delete [] sorting_list;
    return result;
}

Deque<LineSeg> Fast(Point* point_list, int size) {
    int i, j, k, l;
    Point *sorting_list = new Point[size];
    Deque<LineSeg> result;

    memcpy(sorting_list, point_list, size * sizeof(Point));
    delete [] sorting_list;
    return result;
}

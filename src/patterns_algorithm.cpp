/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * patterns_algorithm.cpp
 *
 * Algorithms of patterns
 */

#include "patterns_algorithm.h"
#include "Point.h"
#include <cstring>

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

inline bool Comparator(Point* const &p1, Point* const &p2) {
    char f1 = 1, f2 = 1;
    int res;
    //Reverse if below y axis
    if( (p1->getY() < 0) || (p1->getY() == 0 && p1->getX() < 0)) {
        f1 = -1;
    }
    if( (p2->getY() < 0) || (p2->getY() == 0 && p2->getX() < 0)) {
        f2 = -1;
    }
    res = ((*p1) ^ (*p2)) * f1 * f2;
    return (res == 0) ? ((*p1) < (*p2)) : (res > 0);
}

//Used to do a rough sort of Point*
static inline bool PointCmp(Point* const &a, Point* const &b) {
    return (*a) < (*b);
}

Deque<LineSeg> Brute(Point* point_list, int size) {
    int i, j, k, l;
    Point **sorting_list = new Point*[size];
    Deque<LineSeg> result;
    LineSeg tmp(4);

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
    int i, j, k, onLine;
    Point **original_list = new Point*[size];
    Point **sorting_list = new Point*[size];
    Deque<LineSeg> result;
    LineSeg *tmp_l;
    Point *tmp_swap, *origin;
    for(i = 0; i < size; i++) {
        original_list[i] = &point_list[i];
    }
    //Sort the list to give a rough sort
    sort(original_list, original_list + size, PointCmp);

    for(i = 0; i < size; i++) {
        //Copy the original into the list
        memcpy(sorting_list, original_list, size * sizeof(Point*));
        //Swap the current origin to sorting_list[0]
        tmp_swap = sorting_list[0];
        sorting_list[0] = sorting_list[i];
        sorting_list[i] = tmp_swap;

        origin = sorting_list[0];

        //Shift all the points
        for(j = 1; j < size; j++) {
            *sorting_list[j] -= *origin;
        }

        //Sort the Points relative to sorting_list[0]
        sort(sorting_list + 1, sorting_list + size, Comparator);

        //Iterate over the sorted list
        j = 1;
        while(j < size) {
            onLine = 1;

            //Go over the line
            while(j + onLine < size && ((*sorting_list[j]) ^
             (*sorting_list[j + onLine]) == 0) ) {
                onLine++;
            }
            //For order correctness and uniqueness
            //The origin should be the left-bottom most point on the line
            //Also there should be no less than 4 points on the line
            if((*origin) < (*sorting_list[j]) && onLine >= 3) {
                //Insert the line
                tmp_l = new LineSeg(onLine + 1);
                (*tmp_l)[0] = origin;
                for(k = 0; k < onLine; k++) {
                    (*tmp_l)[k + 1] = sorting_list[j + k];
                }
                result.addLast(*tmp_l);
                delete tmp_l;
            }

            j += onLine;
        }

        //Restore all the points
        for(j = 1; j < size; j++) {
            *sorting_list[j] += *origin;
        }
    }

    delete [] sorting_list;
    return result;
}

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

LineSeg& LineSeg::operator=(const LineSeg& l) {
    if(arr_point) {
        delete [] arr_point;
    }
    size = l.size;
    arr_point = new Point*[size];
    memcpy(arr_point, l.arr_point, size * sizeof(Point*));
    return (*this);
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
    bool f1 = true, f2 = true;
    int res = (*p1) ^ (*p2);
    //Reverse if below y axis
    if( (p1->getY() < 0) || (p1->getY() == 0 && p1->getX() < 0)) {
        f1 = false;
    }
    if( (p2->getY() < 0) || (p2->getY() == 0 && p2->getX() < 0)) {
        f2 = false;
    }
    if( (f1 && !f2) || (!f1 && f2) ) {
        return (res < 0) || (res == 0 && (*p1) < (*p2));
    }
    else {
        return (res > 0) || (res == 0 && (*p1) < (*p2));
    }
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
    int i, j, k, onLine, nSize = size;
    bool exFlag;
    Point **original_list = new Point*[size];
    Point **sorting_list = new Point*[size];
    Deque<LineSeg> result;
    LineSeg *tmp_l;
    Point *tmp_swap, *origin;
    Point abs_origin(0, 0);
    for(i = 0; i < size; i++) {
        original_list[i] = &point_list[i];
    }
    //Sort the list to give a rough sort
    sort(original_list, original_list + size, PointCmp);

    for(i = 0; i < size; i++) {
        exFlag = false;

        //Swap the current origin to original_list[size - nSize]
        tmp_swap = original_list[size - nSize];
        original_list[size - nSize] = original_list[i];
        original_list[i] = tmp_swap;
        //Copy the original into the list
        memcpy(sorting_list, original_list + size - nSize, nSize * sizeof(Point*));

        origin = sorting_list[0];

        //Shift all the points
        for(j = 1; j < nSize; j++) {
            *sorting_list[j] -= *origin;
        }

        //Sort the Points relative to sorting_list[0]
        sort(sorting_list + 1, sorting_list + nSize, Comparator);

        //Iterate over the sorted list
        j = 1;
        while(j < nSize) {
            onLine = 1;

            //Skip some indexes
            while(j < nSize && abs_origin >= (*sorting_list[j])) {
                j++;
            }

            //Go over the line
            while(j + onLine < nSize &&
              ( (*sorting_list[j]) ^ (*sorting_list[j + onLine]) ) == 0) {
                onLine++;
            }
            //For order correctness and uniqueness
            //The origin should be the left-bottom most point on the line
            //Also there should be no less than 4 points on the line
            if(onLine >= 3 && 
             (((*sorting_list[j]) ^ (*sorting_list[j - 1])) != 0 || j == 1)) {
                //Insert the line
                tmp_l = new LineSeg(onLine + 1);
                (*tmp_l)[0] = origin;
                for(k = 0; k < onLine; k++) {
                    (*tmp_l)[k + 1] = sorting_list[j + k];
                }
                result.addLast(*tmp_l);
                delete tmp_l;
                exFlag = true;
            }

            j += onLine;
        }

        //Restore all the points
        for(j = 1; j < nSize; j++) {
            *sorting_list[j] += *origin;
        }

        //Can be eliminated
        if(!exFlag) {
            nSize--;
        }
    }

    delete [] sorting_list;
    return result;
}

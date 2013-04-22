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

Point* const& LineSeg::operator[](int idx) const {
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
    Point **sorting_list = new Point*[size];
    Deque<LineSeg> result;
    LineSeg *tmp_l;
    Point *tmp_swap, *origin;

    for(i = 0; i < size; i++) {
        //Copy the original into the list
        for(j = 0; j < size; j++) {
            sorting_list[j] = &point_list[j];
        }
        //Swap the current origin to sorting_list[0]
        tmp_swap = sorting_list[0];
        sorting_list[0] = sorting_list[i];
        sorting_list[i] = tmp_swap;

        origin = sorting_list[0];

        //Sort the Points relative to sorting_list[0]
        sort(sorting_list + 1, sorting_list + size, Comparator(*origin));

        //Iterate over the sorted list
        j = 1;
        while(j < size) {
            onLine = 1;
            //Go over the line
            while(j + onLine < size && origin->isCollinear(*sorting_list[j],
             *sorting_list[j + onLine])) {
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
    }

    delete [] sorting_list;
    return result;
}

/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * patterns_common.h
 *
 * The header file for commnonly used funcions
 */

#ifndef _PATTERNS_COMMON_H
#define _PATTERNS_COMMON_H

#include "Point.h"
#include "deque.h"
#include "patterns_algorithm.h"
#include <iostream>

using std::istream;
using std::ostream;

//Other utility functions
/*
 * readInt
 *
 * is: the input stream
 *
 * read from a stream, generate a integer
 * The >> operator is too slow, so create this function
 * without verifying data validity
 */
int readInt(istream& is);

/*
 * readPoints
 *
 * is: the input stream
 * size: the pointer to store final size
 *
 * read from a stream, generate a Point array accordingly
 * note that the array should be deleted to prevent memory leak
 */
Point* readPoints(istream& is, int *size);

/*
 * printLines
 *
 * os: the output stream
 * result: the deque of lines to print
 *
 * output a deque of lines to output stream
 */
void printLines(ostream& os, Deque<LineSeg>& result);

#endif

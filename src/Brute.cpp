/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * Brute.cpp
 *
 * The brute force version of pattern check
 */

#include "patterns_algorithm.h"
#include "patterns_common.h"
#include "Point.h"
#include "Vector2D.h"
#include "deque.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

void print_help() {
    cout << "Usage: Brute [OPTION]..." << endl;
    cout << "Process a series of points and find lines." << endl;
    cout << endl;
    cout << "  -i FILE               use FILE as input instead of stdin" << endl;
    cout << "  -h                    display this help and exit" << endl;
    cout << endl;
    cout << "Brute takes input from standard input or file, and find" << endl;
    cout << "lines on which there are four points using Brute Force" << endl;
    cout << "algorithm." << endl;
    cout << endl;
    cout << "Written by TAN, Shuhao <stanab@stu.ust.hk>" << endl;
}

int main(int argc, char **argv) {
    int i;
    Deque<LineSeg> res;
    Point *p_arr;
    int size;
    //stdin
    bool flag = true;
    ifstream is;
    
    //Process command-line input
    //Omit the filename
    i = 1;
    while(i < argc) {
        if(argv[i][0] == '-') {
            if(strlen(argv[i]) != 2) {
                cout << "Brute: unknown option: " << argv[i] << endl;
                cout << "Try `Brute -h' for more information." << endl;
                exit(EXIT_FAILURE);
            }
            switch(argv[i][1]) {
                case 'h':
                    //Help
                    print_help();
                    exit(EXIT_SUCCESS);
                case 'i':
                    //Another input file
                    if(!flag) {
                        cout << "Brute: duplicated option: " << argv[i] << endl;
                        cout << "Try `Brute -h' for more information." << endl;
                        exit(EXIT_FAILURE);
                    }
                    i++;
                    is.open(argv[i], ifstream::in);
                    if(!is) {
                        cout << "Brute: file not found: " << argv[i] << endl;
                        cout << "Try `Brute -h' for more information." << endl;
                        exit(EXIT_FAILURE);
                    }
                    flag = false;
                    break;
                default:
                    //Unrecognized
                    cout << "Brute: unknown option: " << argv[i] << endl;
                    cout << "Try `Brute -h' for more information." << endl;
                    exit(EXIT_FAILURE);
            }
        }
        else {
            cout << "Brute: invalid input" << endl;
            cout << "Try `Brute -h' for more information." << endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }

    if(flag) {
        p_arr = readPoints(cin, &size);
    }
    else {
        p_arr = readPoints(is, &size);
    }
    p_arr = readPoints(is, &size);
    Brute solver(p_arr, size);
    res = solve.Run(p_arr, size);
    printLines(cout, res);

    delete [] p_arr;
    return 0;
}

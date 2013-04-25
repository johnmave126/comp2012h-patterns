/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * patterns_window.h
 *
 * header file for graphical interface
 */

#ifndef _PATTERNS_WINDOW_H
#define _PATTERNS_WINDOW_H

#include "patterns_algorithm.h"
#include "patterns_common.h"
#include "Point.h"
#include "deque.h"
#include <qmainwindow.h>
#include <qapplication.h>

class PatternsMainWindow: public QMainWindow {
    // All classes that contain signals or slots
    // must mention Q_OBJECT in their declaration.
    Q_OBJECT

    public:
        PatternsMainWindow(QWidget* parent = 0, const char* name = 0);
        ~PatternsMainWindow();

    public slots:
        //File Menu begins

        /*
         * OnLoadFile
         *
         * slot that handle action when try to load from a file
         */
        void OnLoadFile();

        /*
         * onLoadBrute
         *
         * slot that handle action when try to run Brute Force algorithm
         */
        void OnLoadBrute();

        /*
         * onLoadFast
         *
         * slot that handle action when try to run Fast algorithm
         */
        void OnLoadFast();

        /*
         * onExit
         *
         * slot that handle action when try to Exit
         */
        void OnExit();
        //File Menu End

        //Help Menu Begin
        
        /*
         * ShowAbout
         *
         * slot that handle action when try to show About info
         */
        void ShowAbout();
        //Help Menu End
        
    protected:
        /** handler for paint event */
        virtual void paintEvent(QPaintEvent*);

    private:
        
        /*
         * processPoints
         *
         * process input points for convenience
         */
        void processPoints();

        //Store Points
        Point *p_arr;
        int size;

        //Store result
        Deque<LineSeg> result;

        //Painting related
        int min_x, max_x, min_y, max_y;
};

#endif

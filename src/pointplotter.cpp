/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * pointplotter.cpp
 *
 * program entry for pointplotter
 */

#include <qapplication.h>
#include "patterns_window.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QWidget* w = new PatternsMainWindow();
    a.setMainWidget(w);
    w->show();
    return a.exec();
};

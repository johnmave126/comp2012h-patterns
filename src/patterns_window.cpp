/*
 * Patterns for COMP2012H
 * Author: TAN, Shuhao
 * Stu ID: 20090398
 * 2013 Spring
 *
 * patterns_window.cpp
 *
 * graphical interface for Patterns
 */

#include "patterns_window.h"
#include "patterns_common.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <qmainwindow.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qstring.h>

using std::cout;

PatternsMainWindow::PatternsMainWindow(QWidget* parent, const char* name) 
:QMainWindow(parent, name), p_arr(NULL), size(0),
 min_x(0), max_x(32768), min_y(0), max_y(32768) {
    //Create File Menu
    //File Menu Begin
    QPopupMenu* file = new QPopupMenu(this);

    //Create Load and Calculate Section
    file->insertItem("&Load input file", this, SLOT(OnLoadFile()), CTRL+Key_N);
    file->insertItem("Load &Brute Algorithm", this, SLOT(OnLoadBrute()), CTRL+Key_B);
    file->insertItem("Load &Fast Algorithm", this, SLOT(OnLoadFast()), CTRL+Key_F);
    file->insertSeparator();
    
    //Create Exit Section
    file->insertItem("&Exit", this, SLOT(OnExit()), CTRL+Key_X);

    //Insert File Menu
    menuBar()->insertItem("&File", file);
    //File Menu End

    //Create Help Menu
    //Help Menu Begin
    QPopupMenu* help = new QPopupMenu(this);
    
    //Create Help items
    help->insertItem("&About", this, SLOT(ShowAbout()));
    
    //Insert Help Menu
    menuBar()->insertItem("&Help", help);
    //Help Menu End
}

PatternsMainWindow::~PatternsMainWindow() {
    if(p_arr) {
        delete [] p_arr;
    }
}

void PatternsMainWindow::OnLoadFile() {
    //Prompt a window to get filename
    QString filename = QFileDialog::getOpenFileName(QString::null,
        "All Files (*.*)", this, 0, "Load input file...");
    
    //Something meaningful be input
    if(!filename.isNull()) {
        QFile file(filename);
        if(file.open(IO_ReadOnly)) {
            QTextStream is(&file);
            if(p_arr) {
                delete [] p_arr;
            }
            p_arr = readPoints(is, &size);
            //Pre process
            processPoints();
            result = Deque<LineSeg>();

            //Call for repaint
            repaint();
        }
    }
}

void PatternsMainWindow::OnLoadBrute() {
    clock_t last_tick, cur_tick;
    if(!p_arr) {
        QMessageBox::critical( this, "No File loaded",
            "No file has been loaded!\n"
            "Please use File->Load input file to load one.",
            QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else {
        last_tick = clock();
        result = Brute(p_arr, size);
        cur_tick = clock();

        printLines(cout, result);
        QMessageBox::information( this, "Running time",
            QString("%1 ms").arg(
                1000.0 * (cur_tick - last_tick) / CLOCKS_PER_SEC, 0, 'f', 2) );

        //Call for repaint
        repaint();
    }
}

void PatternsMainWindow::OnLoadFast() {
    clock_t last_tick, cur_tick;
    if(!p_arr) {
        QMessageBox::critical( this, "No File loaded",
            "No file has been loaded!\n"
            "Please use File->Load input file to load one.",
            QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else {
        last_tick = clock();
        result = Fast(p_arr, size);
        cur_tick = clock();

        printLines(cout, result);
        QMessageBox::information( this, "Running time",
            QString("%1 ms").arg(
                1000.0 * (cur_tick - last_tick) / CLOCKS_PER_SEC, 0, 'f', 2) );

        //Call for repaint
        repaint();
    }
}

void PatternsMainWindow::OnExit() {
    qApp->quit();
}

void PatternsMainWindow::ShowAbout() {
    QMessageBox::information( this, "About",
        "COMP2012H Project4 Patterns\n"
        "By TAN, Shuhao(20090398)");
}

void PatternsMainWindow::paintEvent(QPaintEvent*) {
    int h_offset = menuBar()->height(), w_offset = 10,
        real_h = height() - menuBar()->height - 20,
        real_w = width() - 20;
    int leftX = floor(min_x * 0.9), rightX = ceil(max_x * 1.1), 
        bottomY = floor(min_y * 0.9), topY = ceil(max_y * 1.1);
    double scaleX = 1.0 * real_w / (rightX - leftX),
        scaleY = 1.0 * real_h / (topY - bottomY);
    QPainter painter;
    int i;

    painter.begin(this);
    //Draw Axis
    painter.drawLine(10, 10 + h_offset + real_h, 10 + real_w, 10 + h_offset + real_h);
    painter.drawLine(10, 10 + h_offset + real_h, 10, h_offset + 10);

    //Draw ruler
    for(i = 1; i <= 5; i++) {
        painter.drawLine(10 + floor(1. 0 * real_w / 5 * i),
            10 + h_offset + real_h, 10 + floor(1. 0 * real_w / 5 * i),
            10 + h_offset + real_h - 4);
        painter.drawLine(10, 10 + h_offset + real_h - floor(1. 0 * real_h / 5 * i),
            14, 10 + h_offset + real_h - floor(1. 0 * real_h / 5 * i));
    }
    painter.end();
}

void PatternsMainWindow::processPoints() {
    int i;
    min_x = min_y = 0;
    max_x = max_y = 32768;
    for(i = 0; i < size; i++) {
        //Process the region of display
        if(p_arr[i].getX() < min_x) {
            min_x = p_arr[i].getX();
        }
        else if(p_arr[i].getX() > max_x) {
            max_x = p_arr[i].getX();
        }
        if(p_arr[i].getY() < min_y) {
            min_y = p_arr[i].getY();
        }
        else if(p_arr[i].getY() > max_y) {
            max_y = p_arr[i].getY();
        }
    }
}

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
    //Set size
    setMinimumSize(600, 400);
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
    const int margin = 30;
    int h_offset = menuBar()->height(),
        real_h = height() - menuBar()->height() - 2 * margin,
        real_w = width() - 2 * margin;
    int leftX = (min_x > 20)?(min_x - 20):(0),
        rightX = (max_x < 32748)?(max_x + 20):(32768), 
        bottomY = (min_y > 10)?(min_y - 20):(0),
        topY = (max_y < 32748)?(max_y + 20):(32768);
    double scaleX = 1.0 * real_w / (rightX - leftX),
        scaleY = 1.0 * real_h / (topY - bottomY);
    int real_left = static_cast<int>(margin - leftX * scaleX),
        real_top = static_cast<int>(h_offset + margin + topY * scaleY);
    QPainter painter;
    int i;
    Deque<LineSeg>::Iterator itr(result);

    painter.begin(this);
    //Draw Axis
    painter.drawLine(margin, margin + h_offset + real_h, margin + real_w, margin + h_offset + real_h);
    painter.drawLine(margin, margin + h_offset + real_h, margin, h_offset + margin);

    //Draw ruler
    for(i = 0; i <= 5; i++) {
        painter.drawLine(margin + static_cast<int>(1.0 * real_w / 5 * i),
            margin + h_offset + real_h, margin + static_cast<int>(1.0 * real_w / 5 * i),
            margin + h_offset + real_h - 4);
       painter.drawLine(margin, margin + h_offset + real_h - static_cast<int>(1.0 * real_h / 5 * i),
            margin + 4, margin + h_offset + real_h - static_cast<int>(1.0 * real_h / 5 * i));
    }
    //Draw points
    if(p_arr) {
        for(i = 0; i < size; i++) {
            p_arr[i].draw(&painter, scaleX, scaleY, real_left, real_top);
        }
    }

    //Draw Lines
    for(i = 0; i < result.size(); i++, itr++) {
        (*itr)[0]->drawTo(*((*itr)[itr->getSize() - 1]), &painter, scaleX, scaleY, real_left, real_top);
    }

    //Draw ruler text
    for(i = 0; i <= 5; i++) {
        painter.drawText(static_cast<int>(1.0 * real_w / 5 * i),
                margin + h_offset + real_h, 2 * margin, margin, Qt::AlignCenter,
                QString("%1").arg(leftX + 1.0 * (rightX - leftX) / 5 * i, 0, 'f', 1));
        painter.drawText(0, margin / 2 + h_offset + real_h - static_cast<int>(1.0 * real_h / 5 * i),
                2 * margin, margin, Qt::AlignLeft,
                QString("%1").arg(bottomY + 1.0 * (topY - bottomY) / 5 * i, 0, 'f', 1));
    } 
    painter.end();
}

void PatternsMainWindow::processPoints() {
    int i;
    min_x = min_y = 32768;
    max_x = max_y = 0;
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
    max_x = (max_x - min_x > 6) ? (max_x) : (min_x + 6);
    max_y = (max_y - min_y > 6) ? (max_y) : (min_y + 6);
}

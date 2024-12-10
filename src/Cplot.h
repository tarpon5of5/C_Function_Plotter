/*
**********************************************************************************

Author: Tarpon Thompson
Date: November 2024

This software is distributed under the MIT license:

MIT License

Copyright (c) 2024 Tarpon Thompson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

**********************************************************************************
*/

#ifndef CPLOT_H
#define CPLOT_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QtCore/QVariant>

#include <QApplication>

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>



/*
QT_BEGIN_NAMESPACE

namespace Ui 
{
class Cplot;
}

QT_END_NAMESPACE
*/

class Cplot : public QMainWindow
{
    Q_OBJECT

public:
    Cplot(QWidget *parent = nullptr);
    ~Cplot();
    Cplot *ui;

    void retranslateUi(QMainWindow *Mainwindow);
    

private slots:
    //void newInstance();
    void quit();
    //...


private:
    QAction *actionQuit;
    QAction *actionSave;
    QAction *actionPlot;
    QAction *actionEvaluate;
    QAction *actionContents;
    QAction *actionAbout;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionZoom_Reset;
    QAction *actionConnect_Points;
    QAction *actionDecimal;
    QAction *actionRadians;
    QAction *actionRadians_2;
    QAction *actionCustom;
    QAction *actionExport_Resolution;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *y1_input;
    QPushButton *eval_fns_btn;
    QPushButton *zoom_out_btn;
    QLabel *y2_label;
    QLabel *y_max_label;
    QPushButton *zoom_reset_btn;
    QPushButton *plot_fns_btn;
    QLabel *x_min_label;
    QPushButton *zoom_in_btn;
    QLineEdit *y_max_input;
    QLabel *y_min_label;
    QLineEdit *y_min_input;
    QWidget *Graph;
    QLabel *y3_label;
    QLineEdit *x_max_input;
    QLineEdit *y3_input;
    QLineEdit *x_min_input;
    QLineEdit *y2_input;
    QLabel *x_max_label;
    QLabel *y1_label;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuGraph;
    QMenu *menuScale_Style;
    QMenu *menuHelp;
    QStatusBar *statusbar;




    // Junk code I probably don't need anymore.
 //   void retranslateUi(QMainWindow *Mainwindow);
    
    /*Ui::*///Cplot *ui;
    

};

#endif
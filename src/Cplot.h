/*
**********************************************************************************

Author: Tarpon Thompson
Date: November 2024

This software is distributed under the MIT license.

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




//QT_BEGIN_NAMESPACE
/*
namespace Ui 
{
class Cplot;
}
*/
//QT_END_NAMESPACE


class Cplot : public QMainWindow
{
    Q_OBJECT

public:
    Cplot(QWidget *parent = nullptr);
    ~Cplot();

    

private:
    QAction *actionAbout;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_8;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    
    /*
    Ui::Cplot *ui;
    */

};

#endif // MAINWINDOW_H

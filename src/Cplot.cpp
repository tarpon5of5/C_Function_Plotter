/*
****************************************************************************

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

****************************************************************************
*/

#include "Cplot.h"
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
#include <QIcon>


QT_BEGIN_NAMESPACE
/*****************************************************************************************************************/
Cplot::Cplot(QWidget *parent)
    : QMainWindow(parent)
    {
        if (this->objectName().isEmpty())
            this->setObjectName(QString::fromUtf8("MainWindow"));
        resize(800, 600);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("Cplot")));
        this->setWindowIcon(icon);

/*______Actions_Here_________________________________________________________________________________*/
        actionQuit = new QAction(this);
        actionQuit->setObjectName("actionQuit");
        actionQuit->setShortcuts(QKeySequence::Quit);
        actionQuit->setIcon(QIcon::fromTheme(QString("application-exit")));

        actionSave = new QAction(this);
        actionSave->setObjectName("actionSave");
        
        actionPlot = new QAction(this);
        actionPlot->setObjectName("actionPlot");
        
        actionEvaluate = new QAction(this);
        actionEvaluate->setObjectName("actionEvaluate");
        
        actionContents = new QAction(this);
        actionContents->setObjectName("actionContents");
        
        actionAbout = new QAction(this);
        actionAbout->setObjectName("actionAbout");
        actionAbout->setIcon(QIcon::fromTheme(QString("help-about")));
        
        actionZoom_In = new QAction(this);
        actionZoom_In->setObjectName("actionZoom_In");
        
        actionZoom_Out = new QAction(this);
        actionZoom_Out->setObjectName("actionZoom_Out");
        
        actionZoom_Reset = new QAction(this);
        actionZoom_Reset->setObjectName("actionZoom_Reset");
        
        actionConnect_Points = new QAction(this);
        actionConnect_Points->setObjectName("actionConnect_Points");
        actionConnect_Points->setCheckable(true);
        
        actionDecimal = new QAction(this);
        actionDecimal->setObjectName("actionDecimal");
        
        actionRadians = new QAction(this);
        actionRadians->setObjectName("actionRadians");
        
        actionRadians_2 = new QAction(this);
        actionRadians_2->setObjectName("actionRadians_2");
        
        actionCustom = new QAction(this);
        actionCustom->setObjectName("actionCustom");
        
        actionExport_Resolution = new QAction(this);
        actionExport_Resolution->setObjectName("actionExport_Resolution");

/*______Gui_components_here_______________________________________________________________________________________*/
        centralwidget = new QWidget(this);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        y1_input = new QLineEdit(centralwidget);
        y1_input->setObjectName("y1_input");
        y1_input->setMinimumSize(QSize(479, 0));

        gridLayout->addWidget(y1_input, 2, 1, 1, 8);

        eval_fns_btn = new QPushButton(centralwidget);
        eval_fns_btn->setObjectName("eval_fns_btn");
        eval_fns_btn->setMaximumSize(QSize(131, 16777215));

        gridLayout->addWidget(eval_fns_btn, 0, 4, 1, 1);

        zoom_out_btn = new QPushButton(centralwidget);
        zoom_out_btn->setObjectName("zoom_out_btn");
        zoom_out_btn->setMaximumSize(QSize(84, 16777215));

        gridLayout->addWidget(zoom_out_btn, 0, 6, 1, 1);

        y2_label = new QLabel(centralwidget);
        y2_label->setObjectName("y2_label");
        y2_label->setMaximumSize(QSize(29, 16777215));

        gridLayout->addWidget(y2_label, 4, 0, 1, 1);

        y_max_label = new QLabel(centralwidget);
        y_max_label->setObjectName("y_max_label");
        y_max_label->setMaximumSize(QSize(38, 16777215));

        gridLayout->addWidget(y_max_label, 4, 11, 1, 1);

        zoom_reset_btn = new QPushButton(centralwidget);
        zoom_reset_btn->setObjectName("zoom_reset_btn");
        zoom_reset_btn->setMaximumSize(QSize(89, 16777215));

        gridLayout->addWidget(zoom_reset_btn, 0, 7, 1, 1);

        plot_fns_btn = new QPushButton(centralwidget);
        plot_fns_btn->setObjectName("plot_fns_btn");
        plot_fns_btn->setMaximumSize(QSize(103, 16777215));

        gridLayout->addWidget(plot_fns_btn, 0, 3, 1, 1);

        x_min_label = new QLabel(centralwidget);
        x_min_label->setObjectName("x_min_label");
        x_min_label->setMaximumSize(QSize(38, 16777215));

        gridLayout->addWidget(x_min_label, 2, 9, 1, 1);

        zoom_in_btn = new QPushButton(centralwidget);
        zoom_in_btn->setObjectName("zoom_in_btn");
        zoom_in_btn->setMaximumSize(QSize(84, 16777215));

        gridLayout->addWidget(zoom_in_btn, 0, 5, 1, 1);

        y_max_input = new QLineEdit(centralwidget);
        y_max_input->setObjectName("y_max_input");
        y_max_input->setMaximumSize(QSize(118, 16777215));

        gridLayout->addWidget(y_max_input, 4, 12, 1, 1);

        y_min_label = new QLabel(centralwidget);
        y_min_label->setObjectName("y_min_label");
        y_min_label->setMaximumSize(QSize(38, 16777215));

        gridLayout->addWidget(y_min_label, 2, 11, 1, 1);

        y_min_input = new QLineEdit(centralwidget);
        y_min_input->setObjectName("y_min_input");
        y_min_input->setMinimumSize(QSize(118, 0));
        y_min_input->setMaximumSize(QSize(118, 16777215));

        gridLayout->addWidget(y_min_input, 2, 12, 1, 1);

        Graph = new QWidget(centralwidget);
        Graph->setObjectName("Graph");
        Graph->setMouseTracking(true);

        gridLayout->addWidget(Graph, 6, 0, 1, 13);

        y3_label = new QLabel(centralwidget);
        y3_label->setObjectName("y3_label");
        y3_label->setMaximumSize(QSize(29, 16777215));

        gridLayout->addWidget(y3_label, 5, 0, 1, 1);

        x_max_input = new QLineEdit(centralwidget);
        x_max_input->setObjectName("x_max_input");
        x_max_input->setMinimumSize(QSize(97, 0));
        x_max_input->setMaximumSize(QSize(97, 16777215));

        gridLayout->addWidget(x_max_input, 4, 10, 1, 1);

        y3_input = new QLineEdit(centralwidget);
        y3_input->setObjectName("y3_input");

        gridLayout->addWidget(y3_input, 5, 1, 1, 8);

        x_min_input = new QLineEdit(centralwidget);
        x_min_input->setObjectName("x_min_input");
        x_min_input->setMinimumSize(QSize(97, 0));
        x_min_input->setMaximumSize(QSize(97, 16777215));

        gridLayout->addWidget(x_min_input, 2, 10, 1, 1);

        y2_input = new QLineEdit(centralwidget);
        y2_input->setObjectName("y2_input");

        gridLayout->addWidget(y2_input, 4, 1, 1, 8);

        x_max_label = new QLabel(centralwidget);
        x_max_label->setObjectName("x_max_label");
        x_max_label->setMaximumSize(QSize(38, 16777215));

        gridLayout->addWidget(x_max_label, 4, 9, 1, 1);

        y1_label = new QLabel(centralwidget);
        y1_label->setObjectName("y1_label");
        y1_label->setMaximumSize(QSize(29, 16777215));

        gridLayout->addWidget(y1_label, 2, 0, 1, 1);

/*______Menu_Items_here_________________________________________________________________________________________*/
        this->setCentralWidget(centralwidget);
        menubar = new QMenuBar(this);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 895, 30));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuGraph = new QMenu(menubar);
        menuGraph->setObjectName("menuGraph");
        menuScale_Style = new QMenu(menuGraph);
        menuScale_Style->setObjectName("menuScale_Style");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        this->setMenuBar(menubar);
        statusbar = new QStatusBar(this);
        statusbar->setObjectName("statusbar");
        this->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuGraph->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExport_Resolution);
        menuFile->addAction(actionQuit);
        menuGraph->addAction(actionPlot);
        menuGraph->addAction(actionEvaluate);
        menuGraph->addAction(actionZoom_In);
        menuGraph->addAction(actionZoom_Out);
        menuGraph->addAction(actionZoom_Reset);
        menuGraph->addAction(actionConnect_Points);
        menuGraph->addAction(menuScale_Style->menuAction());
        menuScale_Style->addAction(actionDecimal);
        menuScale_Style->addAction(actionRadians);
        menuScale_Style->addAction(actionRadians_2);
        menuScale_Style->addAction(actionCustom);
        menuHelp->addAction(actionContents);
        menuHelp->addAction(actionAbout);

 //       retranslateUi(this);
        QObject::connect(actionQuit, &QAction::triggered, this, qOverload<>(&QMainWindow::close));
        //QObject::connect(actionAbout, &QAction::triggered, this, AboutWindow());
/*        QObject::connect(zoom_in_btn, SIGNAL(clicked()), this, SLOT(zoom_in()));
        QObject::connect(eval_fns_btn, SIGNAL(clicked()), this, SLOT(evaluate()));
        QObject::connect(zoom_out_btn, SIGNAL(clicked()), this, SLOT(zoom_out()));
        QObject::connect(zoom_reset_btn, SIGNAL(clicked()), this, SLOT(zoom_reset()));
        QObject::connect(plot_fns_btn, SIGNAL(clicked()), this, SLOT(plot_function()));
        QObject::connect(y1_input, SIGNAL(returnPressed()), this, SLOT(y1_input()));
        QObject::connect(y2_input, SIGNAL(returnPressed()), this, SLOT(y3_input()));
        QObject::connect(x_min_input, SIGNAL(returnPressed()), this, SLOT(xmin_input()));
        QObject::connect(x_max_input, SIGNAL(returnPressed()), this, SLOT(xmax_input()));
        QObject::connect(y_min_input, SIGNAL(returnPressed()), this, SLOT(ymin_input()));
        QObject::connect(y_max_input, SIGNAL(returnPressed()), this, SLOT(ymax_input()));
        QObject::connect(y3_input, SIGNAL(returnPressed()), this, SLOT(y3_input()));
*/
        QMetaObject::connectSlotsByName(this);
//    } // setupUi

    void retranslateUi(QMainWindow *Mainwindiw);
    {
        this->setWindowTitle(QCoreApplication::translate("MainWindow", "Something", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "&Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Saves plot as a .png", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPlot->setText(QCoreApplication::translate("MainWindow", "&Plot", nullptr));
#if QT_CONFIG(shortcut)
        actionPlot->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEvaluate->setText(QCoreApplication::translate("MainWindow", "&Evaluate", nullptr));
#if QT_CONFIG(shortcut)
        actionEvaluate->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionContents->setText(QCoreApplication::translate("MainWindow", "&Contents", nullptr));
#if QT_CONFIG(shortcut)
        actionContents->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "&About", nullptr));
        actionZoom_In->setText(QCoreApplication::translate("MainWindow", "&Zoom In", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_In->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl++", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Out->setText(QCoreApplication::translate("MainWindow", "Zoom &Out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Out->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_Reset->setText(QCoreApplication::translate("MainWindow", "Zoom &Reset", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_Reset->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionConnect_Points->setText(QCoreApplication::translate("MainWindow", "&Connect Points", nullptr));
        actionDecimal->setText(QCoreApplication::translate("MainWindow", "&Decimal", nullptr));
        actionRadians->setText(QCoreApplication::translate("MainWindow", "&Radians", nullptr));
        actionRadians_2->setText(QCoreApplication::translate("MainWindow", "Rad&ians", nullptr));
        actionCustom->setText(QCoreApplication::translate("MainWindow", "&Custom", nullptr));
        actionExport_Resolution->setText(QCoreApplication::translate("MainWindow", "&Export Resolution", nullptr));
        eval_fns_btn->setText(QCoreApplication::translate("MainWindow", "Evaluate Functions", nullptr));
        zoom_out_btn->setText(QCoreApplication::translate("MainWindow", "Zoom Out", nullptr));
        y2_label->setText(QCoreApplication::translate("MainWindow", "y2 = ", nullptr));
        y_max_label->setText(QCoreApplication::translate("MainWindow", "Y max", nullptr));
        zoom_reset_btn->setText(QCoreApplication::translate("MainWindow", "Zoom Reset", nullptr));
        plot_fns_btn->setText(QCoreApplication::translate("MainWindow", "Plot Functions", nullptr));
        x_min_label->setText(QCoreApplication::translate("MainWindow", "X min", nullptr));
        zoom_in_btn->setText(QCoreApplication::translate("MainWindow", "Zoom In", nullptr));
        y_min_label->setText(QCoreApplication::translate("MainWindow", "Y min", nullptr));
        y3_label->setText(QCoreApplication::translate("MainWindow", "y3 = ", nullptr));
        x_max_label->setText(QCoreApplication::translate("MainWindow", "X max", nullptr));
        y1_label->setText(QCoreApplication::translate("MainWindow", "y1 = ", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "Fi&le", nullptr));
        menuGraph->setTitle(QCoreApplication::translate("MainWindow", "&Graph", nullptr));
        menuScale_Style->setTitle(QCoreApplication::translate("MainWindow", "&Scale Style", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));

        }; // retranslateUi
    } // setupUi
/*******************************************************************************************************************/
void Cplot::quit()
{
    QApplication::quit();
}






Cplot::~Cplot()
    {
        //delete ui;

    }



QT_END_NAMESPACE

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_data_for_animation;
    QAction *actionSave_animation;
    QAction *actionPlay;
    QAction *actionSet_speed;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menusdsad;
    QMenu *menuRun;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionLoad_data_for_animation = new QAction(MainWindow);
        actionLoad_data_for_animation->setObjectName("actionLoad_data_for_animation");
        actionSave_animation = new QAction(MainWindow);
        actionSave_animation->setObjectName("actionSave_animation");
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName("actionPlay");
        actionSet_speed = new QAction(MainWindow);
        actionSet_speed->setObjectName("actionSet_speed");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menusdsad = new QMenu(menubar);
        menusdsad->setObjectName("menusdsad");
        menuRun = new QMenu(menubar);
        menuRun->setObjectName("menuRun");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menusdsad->menuAction());
        menubar->addAction(menuRun->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menusdsad->addAction(actionLoad_data_for_animation);
        menusdsad->addAction(actionSave_animation);
        menuRun->addAction(actionPlay);
        menuSettings->addAction(actionSet_speed);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionLoad_data_for_animation->setText(QCoreApplication::translate("MainWindow", "Load data for animation", nullptr));
        actionSave_animation->setText(QCoreApplication::translate("MainWindow", "Save animation", nullptr));
        actionPlay->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        actionSet_speed->setText(QCoreApplication::translate("MainWindow", "Set speed", nullptr));
        menusdsad->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuRun->setTitle(QCoreApplication::translate("MainWindow", "Run", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

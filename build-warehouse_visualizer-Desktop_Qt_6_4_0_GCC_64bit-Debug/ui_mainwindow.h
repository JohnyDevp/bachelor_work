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
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnLoadOriginalJson;
    QPushButton *btnLoadFinalJson;
    QPushButton *btnShowOriginalJson;
    QPushButton *btnShowFinalJson;
    QPushButton *btnCompare;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(355, 130);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(355, 130));
        centralwidget->setMaximumSize(QSize(355, 130));
        btnLoadOriginalJson = new QPushButton(centralwidget);
        btnLoadOriginalJson->setObjectName("btnLoadOriginalJson");
        btnLoadOriginalJson->setGeometry(QRect(10, 10, 161, 26));
        btnLoadFinalJson = new QPushButton(centralwidget);
        btnLoadFinalJson->setObjectName("btnLoadFinalJson");
        btnLoadFinalJson->setGeometry(QRect(180, 10, 161, 26));
        btnShowOriginalJson = new QPushButton(centralwidget);
        btnShowOriginalJson->setObjectName("btnShowOriginalJson");
        btnShowOriginalJson->setGeometry(QRect(10, 40, 111, 26));
        btnShowFinalJson = new QPushButton(centralwidget);
        btnShowFinalJson->setObjectName("btnShowFinalJson");
        btnShowFinalJson->setGeometry(QRect(180, 40, 111, 26));
        btnCompare = new QPushButton(centralwidget);
        btnCompare->setObjectName("btnCompare");
        btnCompare->setGeometry(QRect(10, 90, 331, 26));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLoadOriginalJson->setText(QCoreApplication::translate("MainWindow", "Load original JSON", nullptr));
        btnLoadFinalJson->setText(QCoreApplication::translate("MainWindow", "Load final JSON", nullptr));
        btnShowOriginalJson->setText(QCoreApplication::translate("MainWindow", "Show original", nullptr));
        btnShowFinalJson->setText(QCoreApplication::translate("MainWindow", "Show final", nullptr));
        btnCompare->setText(QCoreApplication::translate("MainWindow", "COMPARE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

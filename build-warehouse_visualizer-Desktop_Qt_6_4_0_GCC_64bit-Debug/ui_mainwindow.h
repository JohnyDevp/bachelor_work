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
#include <QtWidgets/QComboBox>
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
    QPushButton *btnRun;
    QComboBox *cmbGroupingAlg;
    QComboBox *cmbBPAlgorithm;
    QComboBox *cmbTSPAlg;
    QComboBox *cmbNumKMeansIter;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(407, 328);
        MainWindow->setMaximumSize(QSize(16777213, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(355, 130));
        btnLoadOriginalJson = new QPushButton(centralwidget);
        btnLoadOriginalJson->setObjectName("btnLoadOriginalJson");
        btnLoadOriginalJson->setGeometry(QRect(10, 20, 161, 26));
        btnLoadFinalJson = new QPushButton(centralwidget);
        btnLoadFinalJson->setObjectName("btnLoadFinalJson");
        btnLoadFinalJson->setGeometry(QRect(230, 20, 161, 26));
        btnShowOriginalJson = new QPushButton(centralwidget);
        btnShowOriginalJson->setObjectName("btnShowOriginalJson");
        btnShowOriginalJson->setEnabled(false);
        btnShowOriginalJson->setGeometry(QRect(10, 70, 111, 26));
        btnShowFinalJson = new QPushButton(centralwidget);
        btnShowFinalJson->setObjectName("btnShowFinalJson");
        btnShowFinalJson->setEnabled(false);
        btnShowFinalJson->setGeometry(QRect(230, 70, 111, 26));
        btnRun = new QPushButton(centralwidget);
        btnRun->setObjectName("btnRun");
        btnRun->setEnabled(false);
        btnRun->setGeometry(QRect(20, 270, 331, 26));
        cmbGroupingAlg = new QComboBox(centralwidget);
        cmbGroupingAlg->setObjectName("cmbGroupingAlg");
        cmbGroupingAlg->setEnabled(true);
        cmbGroupingAlg->setGeometry(QRect(20, 190, 311, 26));
        cmbBPAlgorithm = new QComboBox(centralwidget);
        cmbBPAlgorithm->setObjectName("cmbBPAlgorithm");
        cmbBPAlgorithm->setGeometry(QRect(20, 160, 311, 26));
        cmbTSPAlg = new QComboBox(centralwidget);
        cmbTSPAlg->setObjectName("cmbTSPAlg");
        cmbTSPAlg->setGeometry(QRect(20, 220, 311, 26));
        cmbNumKMeansIter = new QComboBox(centralwidget);
        cmbNumKMeansIter->setObjectName("cmbNumKMeansIter");
        cmbNumKMeansIter->setGeometry(QRect(340, 190, 41, 26));
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
        btnRun->setText(QCoreApplication::translate("MainWindow", "RUN", nullptr));
        cmbGroupingAlg->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose grouping customer algorithm", nullptr));
        cmbBPAlgorithm->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose Bin Packing algorithm", nullptr));
        cmbTSPAlg->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose TSP algorithm", nullptr));
#if QT_CONFIG(whatsthis)
        cmbNumKMeansIter->setWhatsThis(QCoreApplication::translate("MainWindow", "Number of K-Means iterations", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

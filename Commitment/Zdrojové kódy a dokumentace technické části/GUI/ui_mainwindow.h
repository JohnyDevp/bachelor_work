/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
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
    QTextEdit *txtBoxHeight;
    QTextEdit *txtBoxDepth;
    QPushButton *btnAddBox;
    QPushButton *btnRemoveBoxes;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *txtBoxMaxWeight;
    QLabel *label_5;
    QTextEdit *txtBoxName;
    QTextEdit *txtBoxCount;
    QLabel *label_6;
    QLabel *labelWrong;
    QTextEdit *txtBoxWidth;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(401, 511);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(16777213, 16777215));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        centralwidget->setMinimumSize(QSize(355, 130));
        btnLoadOriginalJson = new QPushButton(centralwidget);
        btnLoadOriginalJson->setObjectName("btnLoadOriginalJson");
        btnLoadOriginalJson->setGeometry(QRect(53, 27, 135, 26));
        sizePolicy.setHeightForWidth(btnLoadOriginalJson->sizePolicy().hasHeightForWidth());
        btnLoadOriginalJson->setSizePolicy(sizePolicy);
        btnLoadFinalJson = new QPushButton(centralwidget);
        btnLoadFinalJson->setObjectName("btnLoadFinalJson");
        btnLoadFinalJson->setGeometry(QRect(270, 30, 113, 26));
        sizePolicy.setHeightForWidth(btnLoadFinalJson->sizePolicy().hasHeightForWidth());
        btnLoadFinalJson->setSizePolicy(sizePolicy);
        btnShowOriginalJson = new QPushButton(centralwidget);
        btnShowOriginalJson->setObjectName("btnShowOriginalJson");
        btnShowOriginalJson->setEnabled(false);
        btnShowOriginalJson->setGeometry(QRect(53, 77, 100, 26));
        sizePolicy.setHeightForWidth(btnShowOriginalJson->sizePolicy().hasHeightForWidth());
        btnShowOriginalJson->setSizePolicy(sizePolicy);
        btnShowFinalJson = new QPushButton(centralwidget);
        btnShowFinalJson->setObjectName("btnShowFinalJson");
        btnShowFinalJson->setEnabled(false);
        btnShowFinalJson->setGeometry(QRect(270, 80, 80, 26));
        sizePolicy.setHeightForWidth(btnShowFinalJson->sizePolicy().hasHeightForWidth());
        btnShowFinalJson->setSizePolicy(sizePolicy);
        btnRun = new QPushButton(centralwidget);
        btnRun->setObjectName("btnRun");
        btnRun->setEnabled(false);
        btnRun->setGeometry(QRect(30, 430, 321, 26));
        sizePolicy.setHeightForWidth(btnRun->sizePolicy().hasHeightForWidth());
        btnRun->setSizePolicy(sizePolicy);
        cmbGroupingAlg = new QComboBox(centralwidget);
        cmbGroupingAlg->addItem(QString());
        cmbGroupingAlg->addItem(QString());
        cmbGroupingAlg->addItem(QString());
        cmbGroupingAlg->addItem(QString());
        cmbGroupingAlg->setObjectName("cmbGroupingAlg");
        cmbGroupingAlg->setEnabled(true);
        cmbGroupingAlg->setGeometry(QRect(10, 180, 279, 26));
        sizePolicy.setHeightForWidth(cmbGroupingAlg->sizePolicy().hasHeightForWidth());
        cmbGroupingAlg->setSizePolicy(sizePolicy);
        cmbBPAlgorithm = new QComboBox(centralwidget);
        cmbBPAlgorithm->addItem(QString());
        cmbBPAlgorithm->addItem(QString());
        cmbBPAlgorithm->addItem(QString());
        cmbBPAlgorithm->addItem(QString());
        cmbBPAlgorithm->addItem(QString());
        cmbBPAlgorithm->addItem(QString());
        cmbBPAlgorithm->setObjectName("cmbBPAlgorithm");
        cmbBPAlgorithm->setGeometry(QRect(13, 127, 354, 26));
        sizePolicy.setHeightForWidth(cmbBPAlgorithm->sizePolicy().hasHeightForWidth());
        cmbBPAlgorithm->setSizePolicy(sizePolicy);
        cmbTSPAlg = new QComboBox(centralwidget);
        cmbTSPAlg->addItem(QString());
        cmbTSPAlg->addItem(QString());
        cmbTSPAlg->addItem(QString());
        cmbTSPAlg->setObjectName("cmbTSPAlg");
        cmbTSPAlg->setGeometry(QRect(13, 227, 178, 26));
        sizePolicy.setHeightForWidth(cmbTSPAlg->sizePolicy().hasHeightForWidth());
        cmbTSPAlg->setSizePolicy(sizePolicy);
        cmbNumKMeansIter = new QComboBox(centralwidget);
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->addItem(QString());
        cmbNumKMeansIter->setObjectName("cmbNumKMeansIter");
        cmbNumKMeansIter->setGeometry(QRect(310, 180, 61, 26));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(200);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cmbNumKMeansIter->sizePolicy().hasHeightForWidth());
        cmbNumKMeansIter->setSizePolicy(sizePolicy1);
        txtBoxHeight = new QTextEdit(centralwidget);
        txtBoxHeight->setObjectName("txtBoxHeight");
        txtBoxHeight->setGeometry(QRect(120, 310, 91, 25));
        QFont font;
        font.setPointSize(10);
        txtBoxHeight->setFont(font);
        txtBoxHeight->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBoxDepth = new QTextEdit(centralwidget);
        txtBoxDepth->setObjectName("txtBoxDepth");
        txtBoxDepth->setGeometry(QRect(120, 340, 91, 25));
        txtBoxDepth->setFont(font);
        txtBoxDepth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        btnAddBox = new QPushButton(centralwidget);
        btnAddBox->setObjectName("btnAddBox");
        btnAddBox->setGeometry(QRect(230, 370, 131, 22));
        btnRemoveBoxes = new QPushButton(centralwidget);
        btnRemoveBoxes->setObjectName("btnRemoveBoxes");
        btnRemoveBoxes->setGeometry(QRect(230, 400, 131, 22));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 280, 66, 18));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 310, 66, 18));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 340, 66, 18));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 370, 101, 18));
        txtBoxMaxWeight = new QTextEdit(centralwidget);
        txtBoxMaxWeight->setObjectName("txtBoxMaxWeight");
        txtBoxMaxWeight->setGeometry(QRect(120, 370, 91, 25));
        txtBoxMaxWeight->setFont(font);
        txtBoxMaxWeight->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 400, 66, 18));
        txtBoxName = new QTextEdit(centralwidget);
        txtBoxName->setObjectName("txtBoxName");
        txtBoxName->setGeometry(QRect(120, 400, 91, 25));
        txtBoxName->setFont(font);
        txtBoxName->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBoxCount = new QTextEdit(centralwidget);
        txtBoxCount->setObjectName("txtBoxCount");
        txtBoxCount->setGeometry(QRect(230, 340, 91, 25));
        txtBoxCount->setFont(font);
        txtBoxCount->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBoxCount->setLineWrapMode(QTextEdit::WidgetWidth);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(230, 320, 66, 18));
        labelWrong = new QLabel(centralwidget);
        labelWrong->setObjectName("labelWrong");
        labelWrong->setGeometry(QRect(130, 470, 141, 18));
        labelWrong->setScaledContents(false);
        labelWrong->setAlignment(Qt::AlignCenter);
        txtBoxWidth = new QTextEdit(centralwidget);
        txtBoxWidth->setObjectName("txtBoxWidth");
        txtBoxWidth->setGeometry(QRect(120, 280, 91, 25));
        txtBoxWidth->setFont(font);
        txtBoxWidth->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtBoxWidth->setLineWrapMode(QTextEdit::WidgetWidth);
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
        btnRun->setText(QCoreApplication::translate("MainWindow", "RUN LOADING CARTS", nullptr));
        cmbGroupingAlg->setItemText(0, QCoreApplication::translate("MainWindow", "AVG DISTANCES METHOD", nullptr));
        cmbGroupingAlg->setItemText(1, QCoreApplication::translate("MainWindow", "LEAST SQUARE METHOD", nullptr));
        cmbGroupingAlg->setItemText(2, QCoreApplication::translate("MainWindow", "K MEANS CLUSTERING", nullptr));
        cmbGroupingAlg->setItemText(3, QCoreApplication::translate("MainWindow", "AUTO", nullptr));

        cmbGroupingAlg->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose grouping customer algorithm", nullptr));
        cmbBPAlgorithm->setItemText(0, QCoreApplication::translate("MainWindow", "1D_FFD_BASE_LINE", nullptr));
        cmbBPAlgorithm->setItemText(1, QCoreApplication::translate("MainWindow", "1D_FFD_ITEMS_SPLITTING", nullptr));
        cmbBPAlgorithm->setItemText(2, QCoreApplication::translate("MainWindow", "1D_FFDS_MULTI_BOXES", nullptr));
        cmbBPAlgorithm->setItemText(3, QCoreApplication::translate("MainWindow", "3D_LIBRARY_ONE_BOX", nullptr));
        cmbBPAlgorithm->setItemText(4, QCoreApplication::translate("MainWindow", "3D_LIBRARY_FFDSEnhancement_MULTI_BOXES", nullptr));
        cmbBPAlgorithm->setItemText(5, QCoreApplication::translate("MainWindow", "3D_LIBRARY_MULTI_BOXES_COUNT_DEFINED", nullptr));

        cmbBPAlgorithm->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose Bin Packing algorithm", nullptr));
        cmbTSPAlg->setItemText(0, QCoreApplication::translate("MainWindow", "NEAREST NEIGHBOR", nullptr));
        cmbTSPAlg->setItemText(1, QCoreApplication::translate("MainWindow", "GREEDY", nullptr));
        cmbTSPAlg->setItemText(2, QCoreApplication::translate("MainWindow", "NONE", nullptr));

        cmbTSPAlg->setPlaceholderText(QCoreApplication::translate("MainWindow", "Choose TSP algorithm", nullptr));
        cmbNumKMeansIter->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        cmbNumKMeansIter->setItemText(1, QCoreApplication::translate("MainWindow", "10", nullptr));
        cmbNumKMeansIter->setItemText(2, QCoreApplication::translate("MainWindow", "15", nullptr));
        cmbNumKMeansIter->setItemText(3, QCoreApplication::translate("MainWindow", "20", nullptr));
        cmbNumKMeansIter->setItemText(4, QCoreApplication::translate("MainWindow", "30", nullptr));
        cmbNumKMeansIter->setItemText(5, QCoreApplication::translate("MainWindow", "40", nullptr));
        cmbNumKMeansIter->setItemText(6, QCoreApplication::translate("MainWindow", "60", nullptr));
        cmbNumKMeansIter->setItemText(7, QCoreApplication::translate("MainWindow", "100", nullptr));

#if QT_CONFIG(whatsthis)
        cmbNumKMeansIter->setWhatsThis(QCoreApplication::translate("MainWindow", "Number of K-Means iterations", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnAddBox->setText(QCoreApplication::translate("MainWindow", "ADD BOX", nullptr));
        btnRemoveBoxes->setText(QCoreApplication::translate("MainWindow", "REMOVE BOXES", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Width:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Height:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Depth:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Max-Weight:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        txtBoxCount->setPlaceholderText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Count:", nullptr));
        labelWrong->setText(QCoreApplication::translate("MainWindow", "CHYBA!!!!", nullptr));
        txtBoxWidth->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

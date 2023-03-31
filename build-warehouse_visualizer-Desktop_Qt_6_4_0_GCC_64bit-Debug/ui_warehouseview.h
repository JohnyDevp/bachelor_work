/********************************************************************************
** Form generated from reading UI file 'warehouseview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEVIEW_H
#define UI_WAREHOUSEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warehouseview
{
public:
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QListWidget *listWidget_2;
    QCheckBox *checkBox_sosc;
    QCheckBox *checkBox_dcc;
    QPushButton *btnRestore;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *Warehouseview)
    {
        if (Warehouseview->objectName().isEmpty())
            Warehouseview->setObjectName("Warehouseview");
        Warehouseview->resize(1150, 689);
        Warehouseview->setMouseTracking(false);
        graphicsView = new QGraphicsView(Warehouseview);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 871, 681));
        listWidget = new QListWidget(Warehouseview);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(880, 0, 261, 171));
        listWidget_2 = new QListWidget(Warehouseview);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(880, 180, 261, 171));
        checkBox_sosc = new QCheckBox(Warehouseview);
        checkBox_sosc->setObjectName("checkBox_sosc");
        checkBox_sosc->setGeometry(QRect(880, 360, 241, 24));
        checkBox_dcc = new QCheckBox(Warehouseview);
        checkBox_dcc->setObjectName("checkBox_dcc");
        checkBox_dcc->setGeometry(QRect(880, 390, 191, 24));
        btnRestore = new QPushButton(Warehouseview);
        btnRestore->setObjectName("btnRestore");
        btnRestore->setGeometry(QRect(880, 420, 251, 26));
        widget = new QWidget(Warehouseview);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(880, 460, 258, 218));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(true);
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(Warehouseview);

        QMetaObject::connectSlotsByName(Warehouseview);
    } // setupUi

    void retranslateUi(QWidget *Warehouseview)
    {
        Warehouseview->setWindowTitle(QCoreApplication::translate("Warehouseview", "Form", nullptr));
        checkBox_sosc->setText(QCoreApplication::translate("Warehouseview", "Show only selected cart", nullptr));
        checkBox_dcc->setText(QCoreApplication::translate("Warehouseview", "Differ cart's customers", nullptr));
        btnRestore->setText(QCoreApplication::translate("Warehouseview", "Restore", nullptr));
        label->setText(QCoreApplication::translate("Warehouseview", "Detail", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warehouseview: public Ui_Warehouseview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEVIEW_H

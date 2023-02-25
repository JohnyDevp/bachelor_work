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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warehouseview
{
public:
    QGraphicsView *graphicsView;
    QListWidget *listWidget;

    void setupUi(QWidget *Warehouseview)
    {
        if (Warehouseview->objectName().isEmpty())
            Warehouseview->setObjectName("Warehouseview");
        Warehouseview->resize(1609, 802);
        Warehouseview->setMouseTracking(false);
        graphicsView = new QGraphicsView(Warehouseview);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 0, 1291, 801));
        listWidget = new QListWidget(Warehouseview);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(1320, 10, 256, 192));

        retranslateUi(Warehouseview);

        QMetaObject::connectSlotsByName(Warehouseview);
    } // setupUi

    void retranslateUi(QWidget *Warehouseview)
    {
        Warehouseview->setWindowTitle(QCoreApplication::translate("Warehouseview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warehouseview: public Ui_Warehouseview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEVIEW_H

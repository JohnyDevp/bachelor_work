/********************************************************************************
** Form generated from reading UI file 'warehouseview.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEVIEW_H
#define UI_WAREHOUSEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warehouseview
{
public:
    QCheckBox *checkBox_showPath;
    QGraphicsView *graphicsView;
    QListWidget *listWidget;
    QCheckBox *checkBox_sosc;
    QPushButton *btnRestore;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QCheckBox *checkBox_dcc;

    void setupUi(QWidget *Warehouseview)
    {
        if (Warehouseview->objectName().isEmpty())
            Warehouseview->setObjectName("Warehouseview");
        Warehouseview->setWindowModality(Qt::WindowModal);
        Warehouseview->resize(1402, 810);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Warehouseview->sizePolicy().hasHeightForWidth());
        Warehouseview->setSizePolicy(sizePolicy);
        Warehouseview->setMouseTracking(false);
        checkBox_showPath = new QCheckBox(Warehouseview);
        checkBox_showPath->setObjectName("checkBox_showPath");
        checkBox_showPath->setGeometry(QRect(1130, 268, 96, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox_showPath->sizePolicy().hasHeightForWidth());
        checkBox_showPath->setSizePolicy(sizePolicy1);
        graphicsView = new QGraphicsView(Warehouseview);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(11, 11, 1111, 741));
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        graphicsView->setMaximumSize(QSize(4096, 4096));
        listWidget = new QListWidget(Warehouseview);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(1130, 10, 256, 192));
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        checkBox_sosc = new QCheckBox(Warehouseview);
        checkBox_sosc->setObjectName("checkBox_sosc");
        checkBox_sosc->setGeometry(QRect(1130, 208, 251, 24));
        sizePolicy1.setHeightForWidth(checkBox_sosc->sizePolicy().hasHeightForWidth());
        checkBox_sosc->setSizePolicy(sizePolicy1);
        btnRestore = new QPushButton(Warehouseview);
        btnRestore->setObjectName("btnRestore");
        btnRestore->setGeometry(QRect(1130, 298, 80, 26));
        sizePolicy1.setHeightForWidth(btnRestore->sizePolicy().hasHeightForWidth());
        btnRestore->setSizePolicy(sizePolicy1);
        widget = new QWidget(Warehouseview);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(1130, 330, 264, 427));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName("textEdit");
        textEdit->setEnabled(true);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(0, 401));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        formLayout->setWidget(1, QFormLayout::LabelRole, textEdit);

        checkBox_dcc = new QCheckBox(Warehouseview);
        checkBox_dcc->setObjectName("checkBox_dcc");
        checkBox_dcc->setGeometry(QRect(1130, 238, 176, 24));
        sizePolicy1.setHeightForWidth(checkBox_dcc->sizePolicy().hasHeightForWidth());
        checkBox_dcc->setSizePolicy(sizePolicy1);

        retranslateUi(Warehouseview);

        QMetaObject::connectSlotsByName(Warehouseview);
    } // setupUi

    void retranslateUi(QWidget *Warehouseview)
    {
        Warehouseview->setWindowTitle(QCoreApplication::translate("Warehouseview", "Form", nullptr));
        checkBox_showPath->setText(QCoreApplication::translate("Warehouseview", "Show path", nullptr));
        checkBox_sosc->setText(QCoreApplication::translate("Warehouseview", "Show only selected cart/customer", nullptr));
        btnRestore->setText(QCoreApplication::translate("Warehouseview", "Restore", nullptr));
        label->setText(QCoreApplication::translate("Warehouseview", "Detail", nullptr));
        checkBox_dcc->setText(QCoreApplication::translate("Warehouseview", "Differ cart's customers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warehouseview: public Ui_Warehouseview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEVIEW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "warehouseview.h"
#include "load_json_data.h"
#include "warehouse_final_controller.h"
#include "warehouse_original_controller.h"
#include "debug.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect buttons to their slots
    connect(ui->btnLoadFinalJson, &QPushButton::pressed, this, &MainWindow::btnLoadFinalJson_click);
    connect(ui->btnShowOriginalJson, &QPushButton::pressed, this, &MainWindow::btnShowOriginalJson_click);
    connect(ui->btnShowFinalJson, &QPushButton::pressed, this, &MainWindow::btnShowFinalJson_click);
    connect(ui->btnCompare, &QPushButton::pressed, this, &MainWindow::btnCompare_click);
    connect(ui->btnLoadOriginalJson, &QPushButton::pressed, this, &MainWindow::btnLoadOriginalJson_click);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnLoadOriginalJson_click()
{
    // load the file path and pass it to the loading_function
    Q_DEBUG_PRINTOUT("btnLoadOriginalJson_click")
    QUrl file_name = QFileDialog::getOpenFileUrl(this, tr("Select original JSON file"), QUrl("/home"), tr("*.json"));
    if (file_name.isEmpty())
    {
        // check whether the file has been chosen
        Q_DEBUG_PRINTOUT("None file selected!")
        return;
    }
    Q_DEBUG_PRINTOUT(file_name.toString())
    vector<OItem> item_vect;
    load_original_json_data(qPrintable(file_name.path()), &item_vect);

    // pass the loaded data to controller responsible for showing the original json file
    this->woc = new WarehouseOriginalController(item_vect);
}

void MainWindow::btnShowOriginalJson_click()
{
    // say proper controller to show the window
    Q_DEBUG_PRINTOUT("btnShowOriginalJson_click")
    woc->showGraphics();
}

void MainWindow::btnLoadFinalJson_click()
{
    Q_DEBUG_PRINTOUT("btnLoadFinalJson_click")
}

void MainWindow::btnShowFinalJson_click()
{
    Q_DEBUG_PRINTOUT("btnShowFinalJson_click")
}

void MainWindow::btnCompare_click()
{
    Q_DEBUG_PRINTOUT("btnCompare_click")
}

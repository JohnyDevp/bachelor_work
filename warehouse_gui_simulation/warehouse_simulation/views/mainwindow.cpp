#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMenuBar>
#include <QFileDialog>
#include "errors.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *menuBar = ui->actionLoad_data_for_animation;
    connect(menuBar, SIGNAL(triggered()), this, SLOT(btnLoadFile()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief function for loading file with data for creating simulation
 */
void MainWindow::btnLoadFile(){
    // load file if it should be loaded
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "JSON (*.json)");
    // nothing has been selected -> prompt and return
    if (fileName == "")
    {
        return;
    } else {
        errors::Alert("OK");
    }

}

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

#include "overtaken/WarehousePickingOpt.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // connect buttons to their slots
    connect(ui->btnLoadFinalJson, &QPushButton::pressed, this, &MainWindow::btnLoadFinalJson_click);
    connect(ui->btnShowOriginalJson, &QPushButton::pressed, this, &MainWindow::btnShowOriginalJson_click);
    connect(ui->btnShowFinalJson, &QPushButton::pressed, this, &MainWindow::btnShowFinalJson_click);
    connect(ui->btnRun, &QPushButton::pressed, this, &MainWindow::btnRunAlgorithm_click);
    connect(ui->btnLoadOriginalJson, &QPushButton::pressed, this, &MainWindow::btnLoadOriginalJson_click);
    connect(ui->btnAddBox, &QPushButton::pressed, this, &MainWindow::btnAddBox_click);
    connect(ui->btnRemoveBoxes, &QPushButton::pressed, this, &MainWindow::btnRemoveBoxes_click);

    // setup the box default params
    ui->txtBoxCount->setText("1");
    ui->txtBoxWidth->setText("28.0");
    ui->txtBoxHeight->setText("29.0");
    ui->txtBoxDepth->setText("45.0");
    ui->txtBoxMaxWeight->setText("4000");
    ui->txtBoxName->setText("masterBox");
    ui->labelWrong->setVisible(false);

}
MainWindow::~MainWindow()
{
    delete ui;
}

string original_file_path = "";

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

    cerr << "this: " << qPrintable(file_name.toDisplayString().replace("file://", "")) << endl;

    // store the original file path for case of running the algorithm
    original_file_path = qPrintable(file_name.toDisplayString().replace("file://", ""));

    vector<OItem_TMP> item_vect;
    try{
        load_original_json_data(qPrintable(file_name.path()), &item_vect);
    } catch (...){
        cerr << "Problem loading original file!" << endl;
        this->ui->labelWrong->setVisible(true);
        this->ui->labelWrong->setText("Problem loading original file!");
        return;
    }


    // pass the loaded data to controller responsible for showing the original json file
    this->woc = new WarehouseOriginalController(item_vect);
    this->ui->btnShowOriginalJson->setEnabled(true);
    // unlock the running algoritm button
    this->ui->btnRun->setEnabled(true);
}

void MainWindow::btnShowOriginalJson_click()
{
    // say proper controller to show the window
    Q_DEBUG_PRINTOUT("btnShowOriginalJson_click")
    woc->showGraphics();
}

void MainWindow::btnLoadFinalJson_click()
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
    vector<Cart_TMP> cart_vect;
    load_final_json_data(qPrintable(file_name.path()), &cart_vect);

    // pass the loaded data to controller responsible for showing the original json file
    this->wfc = new WarehouseFinalController(cart_vect);
    this->ui->btnShowFinalJson->setEnabled(true);
}

void MainWindow::btnShowFinalJson_click()
{
    Q_DEBUG_PRINTOUT("btnShowFinalJson_click")
    wfc->showGraphics();
}

// vector with all boxes added through UI
vector<pair<Box,int>> box_vect;
void MainWindow::btnAddBox_click(){
    try{
        Box b(
            strtof32(qPrintable(this->ui->txtBoxWidth->toPlainText()), NULL),
            strtof32(qPrintable(this->ui->txtBoxHeight->toPlainText()), NULL),
            strtof32(qPrintable(this->ui->txtBoxDepth->toPlainText()), NULL),
            strtof32(qPrintable(this->ui->txtBoxMaxWeight->toPlainText()), NULL),
            qPrintable(this->ui->txtBoxName->toPlainText())
            );
        int count = strtod(qPrintable(this->ui->txtBoxCount->toPlainText()), NULL);
        if (count <= 0)
            count = 1;
        box_vect.push_back({b, count});
    } catch (...){
        Q_DEBUG_PRINTOUT("ADDING BOX FAILURE")
    }
    Q_DEBUG_PRINTOUT("box added successfully!")
}

void MainWindow::btnRemoveBoxes_click(){
    box_vect.clear();
    Q_DEBUG_PRINTOUT("all boxes removed!")
}

void MainWindow::btnRunAlgorithm_click()
{
    Q_DEBUG_PRINTOUT("btnRunAlgorithm_click")

    short bp_alg_idx = this->ui->cmbBPAlgorithm->currentIndex();
    short group_alg_idx = this->ui->cmbGroupingAlg->currentIndex();
    short tsp_alg_idx = this->ui->cmbTSPAlg->currentIndex();
    short k_means_iter = this->ui->cmbNumKMeansIter->currentIndex();
    if (bp_alg_idx < 0 || group_alg_idx < 0 || tsp_alg_idx < 0 || (k_means_iter < 0 && group_alg_idx == 2) || box_vect.empty()){
        cerr << "NOT ALL PARAMETERS ARE SELECTED!!" << endl;
        return;
    }


    // create solver configuration
    switch (group_alg_idx) {
    case 0: cerr << "avg" << endl;
        break;
    case 1: cerr << "least" << endl;
        break;
    case 2: cerr << "k means" << endl;
        break;
    }
    switch (tsp_alg_idx) {
    case 0: case 1: cerr << "nearest n" << endl;
        break;
    case 2: case 3: cerr << "greedy" << endl;
        break;
    }
    SolverConfiguration sc((BPAlgorithms)bp_alg_idx, (GroupingCustomersAlgorithms)group_alg_idx, (ShortestPathAlgorithms)tsp_alg_idx);

    vector<int> k_means_iter_idx_to_value_mapping = {5,10,15,20,30,40,60,100};
    sc.Number_of_K_Means_Iterations = k_means_iter_idx_to_value_mapping[k_means_iter];

    BoxConfiguration bc;
    for (auto box : box_vect)
        bc.addBox(box.first,box.second);


    CartConfiguration cc(90, 200, 50, 1, 3);

    Warehouse w;
    CartsLoader CL(w);

    CL.loadItemsAndSpec(original_file_path);
    CL.loadingCartsRun(sc, cc, bc);

    vector<Cart_TMP> cart_vect;

    load_final_json_data(CL.exportCartsToJson(false), &cart_vect);

    // pass the loaded data to controller responsible for showing the original json file
    this->wfc = new WarehouseFinalController(cart_vect);
    this->ui->btnShowFinalJson->setEnabled(true);


}

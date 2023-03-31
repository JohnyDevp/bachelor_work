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

void MainWindow::btnRunAlgorithm_click()
{
    Q_DEBUG_PRINTOUT("btnRunAlgorithm_click")

    short bp_alg_idx = this->ui->cmbBPAlgorithm->currentIndex();
    short group_alg_idx = this->ui->cmbGroupingAlg->currentIndex();
    short tsp_alg_idx = this->ui->cmbTSPAlg->currentIndex();
    short k_means_iter = this->ui->cmbNumKMeansIter->currentIndex();
    if (bp_alg_idx < 0 || group_alg_idx < 0 || tsp_alg_idx < 0 || (k_means_iter < 0 && group_alg_idx == 2)){
        cerr << "NOT ALL PARAMETERS ARE SELECTED!!" << endl;
        return;
    }

//    is_debug_on = true;
    // create solver configuration
    SolverConfiguration sc((BPAlgorithms)bp_alg_idx, (GroupingCustomersAlgorithms)group_alg_idx, (ShortestPathAlgorithms)tsp_alg_idx);

    vector<int> k_means_iter_idx_to_value_mapping = {5,10,15,20,30,40,60,100};
    sc.Number_of_K_Means_Iterations = k_means_iter_idx_to_value_mapping[k_means_iter];

    BoxConfiguration bc;
    bc.addBox(Box(28.0, /*19*/ 29.0, 45.0, 4000, "masterBox"), 100); // the original and so far REAL box
    bc.addBox(Box(14.0, 29.0, 45.0, 4000, "box1"), 100);

    CartConfiguration cc(90, 200, 50, 1, 3);

    Warehouse w;
    CartsLoader CL(w);

    CL.loadItemsAndSpec(original_file_path);
    CL.loadingCartsRun(sc, cc, bc);

    vector<Cart_TMP> cart_vect;

    cerr << CL.exportCartsToJson(false) << endl;
    load_final_json_data(CL.exportCartsToJson(false), &cart_vect);

    // pass the loaded data to controller responsible for showing the original json file
    this->wfc = new WarehouseFinalController(cart_vect);
    this->ui->btnShowFinalJson->setEnabled(true);


}

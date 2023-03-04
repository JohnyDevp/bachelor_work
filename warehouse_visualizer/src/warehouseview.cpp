#include "warehouseview.h"
#include "src/warehouse_original_controller.h"
#include "ui_warehouseview.h"
#include "overtaken/waddress_functions.hpp"
#include <QListWidget>
Warehouseview::Warehouseview(QWidget *parent) : QWidget(parent),
                                                ui(new Ui::Warehouseview)
{
    ui->setupUi(this);
    this->setFixedSize(1150, 689);

    // set up the scene
    this->scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(this->scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    // set the coordinates to start at the top left corner
    this->scene->setSceneRect(0, 0, ui->graphicsView->maximumWidth(), ui->graphicsView->maximumHeight());
    this->ui->graphicsView->setBackgroundBrush(Qt::gray);
}

Warehouseview::~Warehouseview()
{
    delete ui;
}

void Warehouseview::addItem(ItemGui *ig)
{
    this->scene->addItem(ig);
    ig->sc = this->scene;
}

void Warehouseview::removeItem(ItemGui *ig)
{
    this->scene->removeItem(ig);
}

void Warehouseview::drawWarehouseGSectorLayout()
{
}

void Warehouseview::loadUpListWidget(QStringList customers, std::function<void(QListWidgetItem *)> fun)
{
    this->ui->listWidget->addItems(customers);

    // connect signals
    connect(this->ui->listWidget, &QListWidget::itemClicked, this, fun);
}

QTextEdit *Warehouseview::getDetailTextField()
{
    return this->ui->textEdit;
}

bool Warehouseview::getShowOnlySelectedCart_checkbox_value()
{
    return this->ui->checkBox_sosc->isChecked();
}

bool Warehouseview::getDifferCartsCustomers_checkbox_value()
{
    return this->ui->checkBox_dcc->isChecked();
}

void Warehouseview::setRestoreHandler(std::function<void()> fun)
{
    // connect signals
    connect(this->ui->btnRestore, &QPushButton::clicked, this, fun);
}
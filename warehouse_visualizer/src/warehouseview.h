#ifndef WAREHOUSEVIEW_H
#define WAREHOUSEVIEW_H

#include <QWidget>
#include <QGraphicsScene>
#include "itemgui.h"
#include "qlistwidget.h"
#include "interfaces/warehouse_controller_interface.h"
#include <QTextEdit>

namespace Ui
{
    class Warehouseview;
}

class Warehouseview : public QWidget
{
    Q_OBJECT

public:
    explicit Warehouseview(QWidget *parent = nullptr);
    ~Warehouseview();

    // drawing methods
    void addItem(ItemGui *ig);

    // remove item
    void removeItem(ItemGui *ig);

    // fill the listwidget with customers
    void loadUpListWidget(QStringList customers, std::function<void(QListWidgetItem *)> fun);

    QTextEdit *getDetailTextField();

    bool getShowOnlySelectedCart_checkbox_value();

    bool getDifferCartsCustomers_checkbox_value();

    void setRestoreHandler(std::function<void()> fun);

private:
    Ui::Warehouseview *ui;

    QGraphicsScene *scene;

    /// @brief function for drawing the layout of the warehouse's G sector
    void drawWarehouseGSectorLayout();
    /// @brief function for drawing the layout of the warehouse's V sector
    void drawWarehouseVSectorLayout();
    /// @brief function for drawing the layout of the warehouse's P sector
    void drawWarehousePSectorLayout();
};

#endif // WAREHOUSEVIEW_H

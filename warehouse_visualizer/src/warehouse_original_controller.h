#ifndef _WAREHOUSE_ORIGINAL_CONTROLLER_H
#define _WAREHOUSE_ORIGINAL_CONTROLLER_H

#include <vector>
#include <stdlib.h>
#include <QMap>
#include <QListWidget>

#include "./overtaken/objects.h"
#include "warehouseview.h"
#include "itemgui.h"
#include "interfaces/warehouse_controller_interface.h"

using namespace std;

class WarehouseOriginalController : public QObject
{
    Q_OBJECT
public:
    /// @brief constructor
    WarehouseOriginalController(vector<OItem_TMP> _item_vect);
    ~WarehouseOriginalController();

    /// @brief function for showing the graphical window
    void showGraphics();

private:
    /// @brief vector with all loaded items
    vector<OItem_TMP> item_vect;

    /// @brief set of graphical representations of each item bind to its data representation
    map<OItem_TMP *, ItemGui *> item_gui_map;

    /// @brief instance of view
    Warehouseview *wv;

    /// @brief function for generating proper colors for each customer
    QColor getNextCustomerColor();

public slots:
    void listWidgetItemClick_handler(QListWidgetItem *item);
};

#endif

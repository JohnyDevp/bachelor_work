#ifndef _WAREHOUSE_FINAL_CONTROLLER_H
#define _WAREHOUSE_FINAL_CONTROLLER_H

#include <vector>
#include <stdlib.h>

#include "warehouseview.h"
#include "./overtaken/objects.h"

using namespace std;

/// @brief controller for the final data display
class WarehouseFinalController
{
private:
    /// @brief vector with all loaded items
    vector<Cart> cart_vect;

    multimap<int, std::pair<OItem *, ItemGui *>> cart_item_gui_map;

    Warehouseview *wv;

public:
    QColor getNextCartColor();

    /// @brief constructor
    WarehouseFinalController(vector<Cart> _cart_vect);
    ~WarehouseFinalController();

    /// @brief method for show the window with warehouse graphical representation
    void showGraphics();

    /// @brief handler for clicking on item
    /// @param qwl_item
    void listWidgetItemClick_handler(QListWidgetItem *qwl_item);

    /// @brief handle notification about restoring the scene to the default
    void btnRestoreClick_handler();
};

#endif

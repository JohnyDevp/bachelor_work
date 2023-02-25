#ifndef _WAREHOUSE_FINAL_CONTROLLER_H
#define _WAREHOUSE_FINAL_CONTROLLER_H

#include <vector>
#include <stdlib.h>

#include "./overtaken/objects.h"

using namespace std;

/// @brief controller for the final data display
class WarehouseFinalController
{
private:
    /// @brief vector with all loaded items
    vector<Cart> cart_vect;

public:
    /// @brief constructor
    WarehouseFinalController(vector<Cart> _cart_vect);
    ~WarehouseFinalController();

    /// @brief method for show the window with warehouse graphical representation
    void showGraphics();
};


#endif

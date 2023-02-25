#ifndef _WAREHOUSE_CONTROLLER_INTERFACE_H
#define _WAREHOUSE_CONTROLLER_INTERFACE_H

#include <QListWidget>
class WarehouseController
{
public:
    virtual void listWidgetItemClick_handler(QListWidgetItem *item) = 0;
};
#endif
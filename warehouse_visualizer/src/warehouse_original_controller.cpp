#include "warehouse_original_controller.h"
#include "qlistwidget.h"
#include "src/debug.h"
#include <functional>

QColor WarehouseOriginalController::getNextCustomerColor()
{
    static int r = 0, g = 0, b = 30;
    static int round = 1;

    // generate color
    r = (r + round * 28) % 255;
    g = (g + (round - 1) * 15) % 255;
    b = (b + (round - 2) * 30) % 255;
    round++;

    // return generated color
    return QColor::fromRgb(r, g, b);
}

WarehouseOriginalController::WarehouseOriginalController(vector<OItem> _item_vect) : item_vect(_item_vect)
{
    // create an instance of the graphical window and store it
    Warehouseview *wv = new Warehouseview();
    this->wv = wv;

    // create space for listwidget, which will store all the customers and will be passed to the Warehouseview
    QStringList customer_list;

    // create map where will be connected customers and colors
    QMap<int, QColor> customer_to_color_map;

    // create gui for all items
    for (auto item = this->item_vect.begin(); item != this->item_vect.end(); item++)
    {
        // map the customers with colors
        if (customer_to_color_map.find(item->Customer) == customer_to_color_map.end())
        {
            // customer isnt mapped to color yet
            customer_to_color_map.insert(item->Customer, this->getNextCustomerColor());
            // add the customer to the q string list
            customer_list.append(QString::number(item->Customer));
        }

        // build the list of data to be shown by the item on the canvas
        vector<QString> data_vect;
        data_vect.push_back(QString::fromStdString(item->Address));
        data_vect.push_back("Customer: " + QString::number(item->Customer));
        data_vect.push_back("Product: " + QString::number(item->Product));
        data_vect.push_back("X: " + QString::number(item->waddress->getWarehouseWAddress().x_coord) + ", Y: " + QString::number(item->waddress->getWarehouseWAddress().y_coord));

        // build the item gui (the rectangle displayed in graphicsView)
        ItemGui *ig = new ItemGui(
            item->waddress->getWarehouseWAddress().x_coord,
            item->waddress->getWarehouseWAddress().y_coord,
            10.0,
            10.0,
            customer_to_color_map[item->Customer],
            data_vect);

        // attach the item to the scene and to this object vector
        this->wv->addItem(ig);
        this->item_gui_map.insert({item.base(), ig});
    }

    // load customers to the listview
    this->wv->loadUpListWidget(customer_list, std::bind(&WarehouseOriginalController::listWidgetItemClick_handler, this, std::placeholders::_1));
}

WarehouseOriginalController::~WarehouseOriginalController()
{
}

void WarehouseOriginalController::showGraphics()
{
    this->wv->show();
}

void WarehouseOriginalController::listWidgetItemClick_handler(QListWidgetItem *qwl_item)
{
    Q_DEBUG_PRINTOUT("Customer of num **" + qwl_item->text() + "** click-handler reaction")
    // loop through all the items and choose these which fits the customer number, the rest make 50% less visible
    for (auto item : this->item_gui_map)
    {
        if (item.first->Customer == qwl_item->text().toInt())
        {
            // if the item has the proper customer number
            Q_DEBUG_PRINTOUT("Item marked!")
            item.second->setOpacity(1.0);
            item.second->focus();
        }
        else
        {
            item.second->setOpacity(0.5);
            item.second->unfocus();
        }
    }
}

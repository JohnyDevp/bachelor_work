#include "warehouse_final_controller.h"
#include "qlistwidget.h"
#include "debug.h"
#include <functional>

QColor WarehouseFinalController::getNextCartColor()
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

WarehouseFinalController::WarehouseFinalController(vector<Cart_TMP> _cart_vect) : cart_vect(_cart_vect)
{
    // create an instance of the graphical window and store it
    Warehouseview *wv = new Warehouseview();
    this->wv = wv;

    // create space for listwidget, which will store all the carts and will be passed to the Warehouseview
    QStringList cart_list;

    // create map where will be connected customers and colors
    QMap<int, QColor> cart_to_color_map;

    // create gui for all items
    for (auto cart = this->cart_vect.begin(); cart != this->cart_vect.end(); cart++)
    {
        // get color and number for the current cart
        QColor cur_color = this->getNextCartColor();
        cart_list.append(QString::number(cart->id));

        // loop through the cart items and draw them to the scene
        for (auto item = cart->item_vect.begin(); item != cart->item_vect.end(); item++)
        {
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
                cur_color,
                data_vect);

            // attach the item to the scene and to this object vector
            this->wv->addItem(ig);
            this->cart_item_gui_map.insert({cart->id, {item.base(), ig}});
        }
    }

    // load customers to the listview
    this->wv->loadUpListWidget(cart_list, std::bind(&WarehouseFinalController::listWidgetItemClick_handler, this, std::placeholders::_1));

    // set handler for btn restore
    this->wv->setRestoreHandler(std::bind(&WarehouseFinalController::btnRestoreClick_handler, this));
}

WarehouseFinalController::~WarehouseFinalController()
{
}

void WarehouseFinalController::showGraphics()
{
    this->wv->show();
}

vector<QGraphicsLineItem*> ln_vect;
void WarehouseFinalController::listWidgetItemClick_handler(QListWidgetItem *qwl_item)
{
    // clear all previous draw path
    for (int i =0; i<ln_vect.size();i++)
        this->wv->removeLine(ln_vect[i]);
    ln_vect.clear();


    Q_DEBUG_PRINTOUT("Customer of num **" + qwl_item->text() + "** click-handler reaction")
    // remove text from the text_edit
    this->wv->getDetailTextField()->setText("");

    // color map for differing customers when using this option (checkbox mark)
    map<int, QColor> customer_color_map;

    // loop through all the items and choose these which fits the customer number, the rest make 50% less visible
    vector<QPoint> point_vect;
    for (auto item : this->cart_item_gui_map)
    {
        OItem_TMP *oit = item.second.first;
        ItemGui *igui = item.second.second;


        if (item.first == qwl_item->text().toInt())
        {
            point_vect.push_back(QPoint(igui->boundingRect().x(), igui->boundingRect().y()));
            // if the item has the proper customer number
            Q_DEBUG_PRINTOUT("Item marked!")
            if (this->wv->getDifferCartsCustomers_checkbox_value())
            {
                // let customers differ by color
                if (customer_color_map.find(oit->Customer) == customer_color_map.end())
                {
                    // the color for this customer doesn't exist yet
                    customer_color_map.insert({oit->Customer, this->getNextCartColor()});
                }
                // set different color for this item
                igui->setColor2(customer_color_map.find(oit->Customer)->second);
            } else {
                igui->setColor2(Qt::yellow);
            }

            // set the graphical interface for the item
            igui->setOpacity(1.0);
            igui->setZValue(30);
            igui->focus();
            igui->show();

            // add the description of current item to the text_edit
            this->wv->getDetailTextField()->append(
                "Product: " + QString::number(oit->Product) + "\n" +
                "Address: " + QString::fromStdString(oit->Address) + "\n" +
                "Customer: " + QString::number(oit->Customer) + "\n");
        }
        else
        {
            if (this->wv->getShowOnlySelectedCartOrCustomer_checkbox_value())
            {
                // hide all other items
                igui->hide();
            }
            else
            {
                igui->show();
                igui->setOpacity(0.35);
                igui->setZValue(15);
                igui->unfocus();
            }
        }
    }

    // show the path if checkbox is selected
    if (this->wv->getShowPath_checkbox_value()){
        for (size_t i = 0; i < point_vect.size()-1;i++){
            QGraphicsLineItem * ln = new QGraphicsLineItem();
            ln->setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap));
            ln->setLine(QLine(point_vect[i], point_vect[i+1]));
            ln->setZValue(40);
            ln->setPos(0,0);
            this->wv->addLine(ln);
            ln_vect.push_back(ln);
        }
    }
}

void WarehouseFinalController::btnRestoreClick_handler()
{
    Q_DEBUG_PRINTOUT("Restoring")
    // clear all previous draw path
    for (size_t i =0; i<ln_vect.size();i++)
        this->wv->removeLine(ln_vect[i]);
    ln_vect.clear();

    // remove text from the text_edit
    this->wv->getDetailTextField()->setText("");

    // loop through all the items and choose these which fits the customer number, the rest make 50% less visible
    for (auto item : this->cart_item_gui_map)
    {
        ItemGui *igui = item.second.second;
        igui->setOpacity(1);
        igui->setZValue(15);
        igui->unfocus();
    }
    this->wv->update();
}

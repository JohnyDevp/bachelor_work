/**
 * @file general_declarations.h
 * @author Jan Holan, xholan11
 * @brief
 * @version 0.1
 * @date 2022-12-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _GENERAL_DECLARATIONS_H_
#define _GENERAL_DECLARATIONS_H_

#include <string>
#include <list>
#include <vector>

#include "waddress.h"
#include "warehouse.h"
#include "setup_configuration.h"
#include "debug.h"

#include "WarehousePickingOpt.h"

#include "./../../libs/json/include/nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;

class SolverConfiguration;
class BoxConfiguration;
class CartConfiguration;
/*****************************************************/
/********************** CLASSES **********************/
/*****************************************************/

/// @brief
class ItemSpecification
{
public:
    /// @brief enum for item specification type (can be either Unit or Car as whole package of items)
    enum class Type
    {
        Unit,
        Carton,
        Pallet
    };

    /// @brief constructor
    /// @param Product product number
    /// @param Unit which kind of package do the data belong to
    /// @param PackageType
    /// @param ContentQty
    /// @param X
    /// @param Y
    /// @param Z
    /// @param Weight
    ItemSpecification(int _Product, ItemSpecification::Type _Unit, int _PackageType, int _ContentQty, float _X, float _Y, float _Z, float _Weight);
    ItemSpecification(){};
    ~ItemSpecification();

    int Product;
    ItemSpecification::Type Unit;
    int PackageType;
    int ContentQty;
    float X;
    float Y;
    float Z;
    float Weight;
    float Volume;
};


/// @brief class representing the item in order (with its address, and all description) -> Order Item
class OItem
{
private:
    /// @brief total weight of this item
    float weight;
    /// @brief total volume of this item
    float volume;

public:
    int Customer;
    int Product;
    string Address; // the address as used in real warehouse
    int Qty;
    /// @brief address in its representation for algorithm proposes
    WAddress *waddress;

    /// @brief item specification reference
    map<ItemSpecification::Type, ItemSpecification> item_spec;

    /// @brief constructor
    /// @param Customer Customer number - used for recognition which items belong to one customer
    /// @param Product Product number - used for recognition which item specification belongs to which item
    /// @param Address Address code string - the string, which contains exact position of item in warehouse in 3D coordinates
    /// @param Qty Quantity of units in this item
    OItem(int Customer, int Product, string AddressCode, int Qty);
    OItem() = default;
    ~OItem();

    /// @brief adding the item specification
    void addItemSpecification(ItemSpecification itspec) { this->item_spec.insert({itspec.Unit, itspec}); }

    /// @brief getter of item weight
    /// @return weight of item as float - ALL OF THE UNITS INCLUDED
    float getWeight();
    /// @brief  getter of item volume
    /// @return volume of item as float - ALL OF THE UNITS INCLUDED
    float getVolume();

    /// @brief function for counting the volume and weight of this item (because this item can include more units)
    void countWeightAndVolume();
};

/// @brief class which serves as representation of item in the box
/// in difference from OItem it doesn't represent order item of N units - instead of this BoxItem represents only
/// one unit of OItem or a package of N units of OItem
class BoxItem
{
private:
public:
    /// @brief the count of UNITS of this item in the box (even if this item represents package, this variable stores the count OF UNITS!!!!)
    /// e.g. 6 phones will be stored as one BoxItem of count=6 or 2 packs of phones will be stored as one BoxItem of count=2
    int count_of_units = 0;
    ItemSpecification item_specification;
    OItem order_item;

    BoxItem(ItemSpecification _item_specification, OItem _order_item);
    BoxItem() = default;

    /// @brief increase the number stored in count variable
    void countUnitsUp(int num);
    void setNumOfUnits(int num);
    int getCountOfUnits();

    int getVolume();
};

/// @brief structure
typedef struct items_into_boxes_decomposition
{
    vector<Box> full_box_vect;
    vector<Box> one_item_box_vect;
} ITEMS_IN_BOXES_DECOMP_T;

/// @brief the shelf in cart, which contains boxes
class CartShelf
{
private:
    float used_width = 0;

    ITEMS_IN_BOXES_DECOMP_T boxes;

    float width;
    float height;
    float depth;

public:
    CartShelf(float width, float height = MAXFLOAT, float depth = MAXFLOAT);

    void addBox_oneItemized(Box box);

    void addBox_fullItemized(Box box);

    ITEMS_IN_BOXES_DECOMP_T *getBoxes();

    float getWidth();
    float getHeight();
    float getDepth();
    float getFreeWidth();
};

/// @brief class representing the customer object (containing its items in warehouse - in order)
class Customer
{
private:
    float total_weight = 0.0f;
    float total_volume = 0.0f;

    /// @brief id of customer loaded from one of its items
    /// the -1 signs, that it has no item inside yet (after first gets loaded this variable will change)
    int customer_id = -1;

    /// @brief the decomposition of items into boxes in standart variant of cart (9 boxes of constant volume)
    vector<Box> box_vect;

public:
    /// @brief all items that belongs to the customer
    vector<OItem> item_vect;

    ~Customer();

    Customer(int cust_id) : customer_id(cust_id){};

    /// @brief add item to this customer
    void addOItem(OItem o_item);

    /// @brief function which counts volume and weight of all items
    void countTotalWeightAndVolume();

    void decompIntoBoxes(BoxConfiguration &bc, SolverConfiguration &sc);

    vector<Box> getBoxesDecomp();

    void setBoxesDecomp(vector<Box> _box_vect);

    float getTotalWeight();
    float getTotalVolume();
    int getCustomerID();
};

/// @brief class representing part or whole of order item in cart, differ from OItem only by
/// added RealQty integer member, which gives an information of how many pieces of order item is realy in the cart
class CartOItem
{
private:
    /// @brief gives an information of how many pieces of order item is realy in the cart
    OItem oitem_ref;

public:
    int RealQty = 0;
    CartOItem(OItem &_oitem_ref);
    void addToRealQty(int qty_to_add);
    int getRealQty();

    OItem getOItem() const;
};

/// @brief class representing one Cart loaded with items from customers
class Cart
{
private:
    /// @brief list of loaded customers
    vector<Customer> customer_vect;

    /// @brief vector with all items with its count of units in cart - finally it is SORTED to the best shortest path(TSP problem)
    vector<OItem> item_vect; // TODO remove
    vector<CartOItem> cartoitem_vect;
    void addOItemWithQty(OItem oitem, int qty);

    /// @brief vector
    vector<CartShelf> cart_shelves_vect;

    /// @brief whole free space in cart (all boxes's free space together)
    float cart_free_space;
    /// @deprecated not used for real anymore
    int free_boxes = 9;

    /// @brief the currently estimated walked distance between items assigned to this cart
    int estimated_walked_distance = 0;

    bool loadingCustomer_old(Customer &customer);
    bool loadingCustomer_new(SolverConfiguration &sc, Customer &customer, bool can_be_partly_loaded = false, vector<Box> *non_loaded_boxes = NULL);

public:
    Cart();
    /// @brief not in use but ready //TODO
    /// @param cart_shelf_vect
    Cart(vector<CartShelf> cart_shelf_vect);

    ~Cart();

    /// @brief function for attaching customer to some cart
    /// @param customer the customer to be loaded
    /// @return boolean according to the whether the customer fit the free space in cart or not
    bool loadCustomer(SolverConfiguration &sc, Customer &customer, bool can_be_partly_loaded = false, vector<Box> *non_loaded_boxes = NULL);

    /// @brief getter for whole free space on cart
    /// @return
    float getCartFreeSpace();

    /// @brief getter for the built customer list
    /// @return list of customers
    vector<Customer> getCustomerVector();

    /// @brief
    /// @return vector with items in cart
    vector<OItem> getItemVector();
    vector<CartOItem> getCartOItemVector();

    vector<CartShelf> getCartShelvesVector();
    /// @brief setter
    void setCartOItemVector(vector<CartOItem> _cartoitem_vect);

    /// @brief function for counting the distance which is any person supposed to walk when handling this cart
    /// @param dist distance to be counted
    void addToEstimatedWalkedDistance(int dist);

    int getEstimatedWalkedDistance();
};

#endif

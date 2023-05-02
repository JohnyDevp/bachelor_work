#ifndef _WAREHOUSE_PICKING_OPTIMIZATION_H_
#define _WAREHOUSE_PICKING_OPTIMIZATION_H_

#include <string>
#include <list>
#include <vector>
#include <map>

using namespace std;

//FIXME necessary
#include "general_declarations.h"

#include "warehouse.h"
#include "setup_configuration.h"

// incomplete declarations ===============
class OItem;
class BoxItem;
class Customer;
class Cart;

class SolverConfiguration;
class CartConfiguration;
class BoxConfiguration;

//==============================

/// @brief Box that can be loaded to the cart and which contains picked items in the warehouse
class Box
{
private:
    /// @brief this is computed according to the parameters of the box
    /// it is computed as width*height*depth*usable_capacity_percentage
    float capacity = 0;

    /// @brief capacity of box still free (not used by any items)
    float free_capacity = 0;

    /// @brief capacity of box used already by items
    float used_capacity = 0;

    /// @brief vector of items which are not neccessary all OItems
    map<int, BoxItem> product_boxitem_map;

public:
    /// @brief usable capacity in percentage
    float width, height, depth, max_weight;
    string name;
    float usable_capacity_percentage = 1;

    /// @brief constructor, parameters are considered looking from the front side of the box
    /// @param width width of the box (from the front side)
    /// @param height height of the box (from the front side)
    /// @param depth depth of the box (from the front side - the length from the front side to the back-side) \n
    /// @param max_weight maximal weight which can be loaded to the box
    /// @param name optional name of the box
    Box(float width, float height, float depth, float max_weight, string name, float _usable_capacity_percentage = 1);
    Box() = default;
    ~Box();

    /// @return capacity of box
    float getCapacity();

    /// @return free capacity of the box (this capacity is not necessarily usable in reality (e.g. some tight free space along item,...))
    float getFreeCapacity();

    /// @return capacity used by the items already in the box
    float getUsedCapacity();

    /// @return map of <Product,BoxItems> that represents Product's units in the box
    map<int, BoxItem> getItemsInTheBox();

    /// @brief function for adding item to box
    /// @warning it is without any check
    bool addItem(BoxItem &boxItem);

    /// @brief function returning the empty state of the box
    /// @return true when empty or false when not-empty
    bool isEmpty();
};

/// @brief main class representing something like an interface for it
class CartsLoader
{
private:
    /// @brief object describing warehouse
    Warehouse warehouse;

    /// @brief vector with all items passed to this algorithm (each is individual part)
    vector<OItem> item_vect;

    /// @brief vector with customers, that gather items to some undivideable groups
    map<int, Customer> id_customer_map;

    /// @brief list with finally loaded carts
    list<Cart> loaded_cart_list;

    /// @brief computes all implemented versions and choose the best
    /// @param solver_conf 
    /// @param cart_conf 
    /// @param volume_customer_map 
    /// @return the right algorithm
    short chooseBestAlgorithm(
        SolverConfiguration &solver_conf,
        CartConfiguration &cart_conf,
        multimap<int, Customer, greater<int>> volume_customer_map);

public:
    CartsLoader(Warehouse &warehouse);
    ~CartsLoader();

    /// @brief function for loading up all items given in order with their specification
    void loadItemsAndSpec(string path_or_text);

    /// @brief start algorithm
    void loadingCartsRun(SolverConfiguration &solver_conf, CartConfiguration &cart_conf, BoxConfiguration &box_conf);

    /// @brief export created carts to json file, which is created in the given or root directory
    string exportCartsToJson(bool export_shelves_boxes = true, bool export_sorted_items = true);
    void testUsedData(string path);
    string getStats();
    list<Cart> getLoadedCartsList();
};

#endif
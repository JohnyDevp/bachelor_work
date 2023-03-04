#include "load_json_data.h"

#include "debug.h"

#include "./../libs/json/include/nlohmann/json.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>

// shortcut for using json
using json = nlohmann::json;

void load_original_json_data(string file_path, vector<OItem> *item_vect)
{
    // read the raw json data
    ifstream f(file_path, ifstream::in);
    json jsfile;
    f >> jsfile;

    // iterate through all the items and load its values to the proper classes
    map<pair<int, int>, OItem> tmp_m;
    for (auto iter : jsfile.items())
    {
        json item = iter.value();
        // check whether this item of order has been loaded yet
        auto res = tmp_m.find(make_pair(item["Customer"], item["Product"]));
        if (res == tmp_m.end())
        {
            // not loaded yet -> create new item
            OItem new_item;
            new_item.Customer = item["Customer"];
            new_item.Product = item["Product"];
            new_item.Address = item["Address"];
            new_item.Qty = item["Qty"];
            new_item.waddress = new WAddress(new_item.Address);
            item_vect->push_back(new_item);

            // add it to the tmp map
            tmp_m.insert({make_pair(item["Customer"], item["Product"]), new_item});
        }
    }
    S_DEBUG_PRINTOUT(item_vect->size() << " items loaded!")
}

void load_final_json_data(string file_path, vector<Cart> *cart_vect)
{
    // read the raw json data
    ifstream f(file_path, ifstream::in);
    json jsfile;
    f >> jsfile;

    // the id which will be loaded to the cart object to make it recognizable
    int cur_cart_num = 0;
    // iterate through all the carts
    for (auto carts_iter : jsfile.items())
    {
        Cart new_cart;
        new_cart.id = ++cur_cart_num; // id of cart
        // iterate through all the items of one cart
        for (auto item_iter : carts_iter.value())
        {
            json item = item_iter;
            OItem new_item;
            new_item.Customer = item["Customer"];
            new_item.Product = item["Product"];
            new_item.Address = item["Address"];
            new_item.Qty = item["Qty"];
            new_item.waddress = new WAddress(new_item.Address);
            new_cart.item_vect.push_back(new_item);
        }
        // save the cart
        cart_vect->push_back(new_cart);
    }
    S_DEBUG_PRINTOUT(jsfile.size() << " carts loaded!")
}
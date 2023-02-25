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
    for (auto iter : jsfile.items())
    {
        json item = iter.value();
        OItem new_item;
        new_item.AddressCode = item["AddressCode"];
        new_item.Address = item["Address"];
        new_item.Customer = item["Customer"];
        new_item.ID = item["ID"];
        new_item.Product = item["Product"];
        new_item.Qty = item["Qty"];
        new_item.Wave = item["Wave"];
        new_item.waddress = new WAddress(new_item.AddressCode);
        item_vect->push_back(new_item);
    }
    S_DEBUG_PRINTOUT(jsfile.size() << " items loaded!")
}

void load_final_json_data(string file_path, vector<Cart> *cart_vect)
{
    (void)file_path, (void)cart_vect;
}
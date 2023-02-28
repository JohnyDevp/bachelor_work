#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include <string>
#include <stdlib.h>
#include <vector>

#include "waddress.h"

using namespace std;

/// @brief class for specification of one item
class OItem
{
public:
    int Customer;
    int Product;
    string Address; // the address as used in real warehouse
    int Qty;
    /// @brief address in its representation for algorithm proposes
    WAddress *waddress;
};

/// @brief class for specification of one cart
class Cart
{
public:
    /// @brief id of this cart
    int id;
    /// @brief vector with all items in the Cart
    vector<OItem> item_vect;
};

#endif
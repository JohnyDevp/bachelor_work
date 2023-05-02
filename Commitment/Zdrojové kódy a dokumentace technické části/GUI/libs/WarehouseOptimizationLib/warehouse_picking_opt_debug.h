/**
 * @file warehouse_picking_opt_debug.cpp
 * @author Jan Holáň, xholan11 (xholan11@vutbr.cz)
 * @brief translated with gcc version 12.2.1
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _DEBUG_H_
#define _DEBUG_H_

#pragma once

#include "stdbool.h"
#include "WarehousePickingOpt.h"

#include <iostream>
using namespace std;

/// @brief property enabling debug info
inline bool is_debug_on = false;

class Customer;
class Cart;
class BoxItem;
class Box;

#define DEBUG_MSG(msg, ...) is_debug_on ? fprintf(stderr, msg, ##__VA_ARGS__) : 0

/// @brief show all the customers details
/// @param cust_mult
void debugCustomerMultimap(multimap<int, Customer, greater<int>> cust_mult);

/// @brief show one customer detail
/// @param cust
void debugCustomer(Customer cust);

/// @brief show details of boxitems
/// @param boxitem_vect
void debugCustomerBoxItems(vector<BoxItem> boxitem_vect);

/// @brief show details of customer's boxes
/// @param box_vect
void debugCustomerBoxes(vector<Box> box_vect);

/// @brief show cart list details
/// @param cart_list
void debugCartsCustomers(list<Cart> cart_list);

/// @brief show all the items loaded for each cart
/// @param cart_list
/// @param additional_spec show more detailed info
void debugCartsOItems(list<Cart> cart_list, bool additional_spec = false);

/// @brief show info of boxes loaded for each cart
/// @param cart_list
void debugCartsBoxes(list<Cart> cart_list);

#endif
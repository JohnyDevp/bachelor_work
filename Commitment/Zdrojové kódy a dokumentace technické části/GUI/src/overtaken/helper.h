#ifndef _HELPER_H_
#define _HELPER_H_

#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include "./../bachelor_work_code/src/WarehousePickingOpt.h"

using namespace std;
using json = nlohmann::json;

/// @brief function for creating json object from file given as path
/// @param path to file .json
/// @return json object
json readJsonFromFile(string path);

class OItem;
/// @brief function for converting OItem to json
void to_json(json &j, const OItem &it);

class CartOItem;
void to_json(json &j, const CartOItem &coi);

class BoxItem;
void to_json(json &j, const BoxItem &bi);

/// @brief computation of the shortest (air) path between two points in warehouse
/// @param first_addr first address as first point of triangle
/// @param second_addr second address as second point of triangle
/// @return floating number as the lenght of the hypothenuse
float pythagoras(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr);

/// @brief computation of the distance between two points in euclidean space, meaning right-angle space
/// @param first_addr first address as first point of triangle
/// @param second_addr second address as second point of triangle
/// @return floating number as the lenght of the right-angle distance
float euclidean_distance(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr);

/// @brief factorial computation with memory of previously computed factorials
/// @param num number to be processed
/// @return factorial
int factorial(int num);

#endif

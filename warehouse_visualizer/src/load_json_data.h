#ifndef LOAD_JSON_DATA_H
#define LOAD_JSON_DATA_H

#include <string>
#include <vector>

#include "./libs/WarehouseOptimizationLib/WarehousePickingOpt.h"
#include "overtaken/objects.h"

using namespace std;

/// function for loading the json
void load_original_json_data(string file_path, vector<OItem_TMP> *item_vect);
void load_final_json_data(string file_path, vector<Cart_TMP> *cart_vect);

#endif // LOAD_JSON_DATA_H

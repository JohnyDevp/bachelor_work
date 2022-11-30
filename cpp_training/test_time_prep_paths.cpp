#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iterator>

//usings
using namespace std;

/**
 * @brief store for parsed parts of the string version of address
 * @example //floor row[Y-axis] regal_floor(00-04/15)[Z-axis] cell[X-axis]
 * G00       15             01                          027
 */
typedef struct parsed_product_adress
{
    char section; //G, V, P
    short int section_floor; //00 - 02 (cca, not sure)
    short int row;  //floor row[Y-axis]
    short int regal_floor; // regal_floor(00-04/15)[Z-axis]
    short int cell; //cell[X-axis]
}ppa_t;

/**
 * @brief structure describing main layout of warehouse
 * 
 */
typedef struct warehouse{
    //the numbers of cells, between which there is a corridor 
    //as corridors are not numbered, then the number is between the number of neighbouring cells
    const vector<float> vertical_corridors{7.5, 17.5, 24.5};
    const vector<int> horizontal_corridors{};
    
    //rows, which has 1-246 cells (the rest has 1-31)
    const vector<int> rows_of_246_cells{0,1,40};
}warehouse_t;
const warehouse_t warehouse_spec;

//declarations
ppa_t parseAddress(string raw_address);

int main() {    
    //just the case, when the paths are precomputed so there is nothing to do with it
    //just read it
    map<pair<string, string>, int> warehous_dist_m;
    warehous_dist_m[make_pair("first", "second")] = 3;

    for(int i=0; i<3000; i++) {
        warehous_dist_m[make_pair("first", "second")];
    }

    //case, when each path has been to be compute to the start point to know 
    //address to start with

    //address description - each has to have 10 digits
    //floor row[Y-axis] regal_floor(00-04/12)[Z-axis] cell[X-axis]
    // G00       15             01                          027
    vector<string> raw_addresses{"G001501027"};
    for (int i=0; i<3000; i++) {
        parseAddress(raw_addresses[0]);
    }

    return 0;
}

/**
 * @brief function for parsing the address of item into the structure
 * 
 * @param raw_address the string version of address, e.g. G001520356
 * @return ppa_t the struct of parsed parts of the address in their right types 
 */
ppa_t parseAddress(string raw_address) 
{
    //create the structure for address
    ppa_t parsed_addr;
    //load each part of address by the substring function
    parsed_addr.section = raw_address[0];
    parsed_addr.section_floor = stoi(raw_address.substr(1,2));
    parsed_addr.row = stoi(raw_address.substr(3,2));
    parsed_addr.regal_floor = stoi(raw_address.substr(5,2));
    parsed_addr.cell = stoi(raw_address.substr(7,3));

    return parsed_addr;
}

/**
 * @brief function for computing the distance between two adresses
 * according to pattern described by code
 * 
 * @param first struct with the first address
 * @param second struct with the second address
 * @return int the distance between two places above
 */
int computeDistance(ppa_t &first, ppa_t &second){
    //if first or second is addresses in 0th or 1st or 40th row, then recalculate its cell-value (x axis)
    //cause the rest of rows are each of 1-31 cells but in the rows mentioned above are each of 1-246 cells
    if (find(warehouse_spec.rows_of_246_cells.begin(), warehouse_spec.rows_of_246_cells.end(), first.row ) 
        != warehouse_spec.rows_of_246_cells.end())
    {
        //the row has 246 cells
        //1 cell in 31-celled-row is 8 cells in 246-celled-row 
        //WARNING - it is not everywhere like that

    }

    //do the pattern (it is for the euclidean space)
    float distance = 0;

    //find the nearest corridot from first and compute the distance to it
    for(auto corridor : warehouse_spec.vertical_corridors){
        if ((float)first.cell < corridor){
            distance = corridor-first.cell;
            break;
        }
    }

    
    return 0;
}
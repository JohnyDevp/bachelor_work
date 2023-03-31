#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <list>
#include <map>

#include "waddress.h"

/// @brief warehouse representation, distance computation
class Warehouse
{
private:
    /// @brief used as max x coordinate
    int width_x;

    /// @brief used as max y coordinate
    int height_y;

public:
    /// @brief constructor
    Warehouse();
    ~Warehouse();

    /// @brief function counting distance between two given addresses
    /// @return distance between two addresses
    int getDistanceBetweenAddresses(WAddress first_addr, WAddress second_addr);

    /// @brief function counting distance between two given addresses
    /// @warning both addresses have to have set up all values in struct, otherwise the result may be inappropriate
    /// @param first_addr 
    /// @param second_addr 
    /// @return distance between two addresses according to the warehouse layout
    int getDistanceBetweenAddresses(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr);
};

// // @brief warehouse sector - it is somehow logically separated from the other parts - sectors - of warehouse
// class WSector
// {
// private:
//     /// @brief name of the sector
//     string name;

//     /// @brief top left x coordinate of this sector in warehouse coordinates
//     int top_x;
//     /// @brief top left y coordinate of this sector in warehouse coordinates
//     int top_y;

//     /// @brief bottom right x coordinate of this sector in warehouse coordinates
//     int bottom_x;
//     /// @brief bottom right y coordinate of this sector in warehouse coordinates
//     int bottom_y;

//     vector<float> vertical_corridors;
//     vector<float> horizontal_corridors;

// public:
//     WSector(string name);
//     ~WSector();

//     /// @brief setter
//     /// @param horizontal_corridors vector
//     void setVerticalCorridors(vector<float> horizontal_corridors);
//     /// @brief setter
//     /// @param vertical_corridors vector
//     void setHorizontalCorridors(vector<float> vertical_corridors);

//     /// @brief count distance between two addresses, which lay in the same sector
//     /// @param addr_start start address
//     /// @param addr_end end address
//     /// @return distance between addresses as integer
//     int getDistanceBetweenAddresses(WAddress addr_start, WAddress addr_end);
// };

#endif

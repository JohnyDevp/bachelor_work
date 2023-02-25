#ifndef _WADDRESS_H_
#define _WADDRESS_H_

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <iterator>
#include <unistd.h>

using namespace std;

/// @brief this structure stores parsed address in usable form in computation
typedef struct
{
    string section; // G00,V02,GP1,P00,... (may vary depending on usage)
    int y_coord;    // floor row[Y-axis]
    int z_coord;    // regal_floor(00-04/15)[Z-axis]
    int x_coord;    // cell[X-axis]
} SECTOR_ADDR_T;

/// @brief class representing the WAddress of product in warehouse
class WAddress
{
public:
    /// @brief constructor with param of raw address which is immediately parsed to proper form
    /// @param raw_sector_addr the address of item in sector in string format
    WAddress(string raw_sector_addr);

    /// @brief Destroy the WAddress object
    ~WAddress();

    /// @brief Get the real Warehouse WAddress
    /// @return SECTOR_ADDR_T the real WAddress in warehouse
    SECTOR_ADDR_T getWarehouseWAddress();

    /// @brief getter
    /// @return raw address in sector in string
    string getRawSectorAddress();

private:
    /// @brief stored real warehouse WAddress of some place
    SECTOR_ADDR_T parsed_sector_addr;

    /// @brief raw sector addr as string
    string raw_sector_addr;
};

#endif
#include "waddress.h"
#include "waddress_functions.hpp"

WAddress::WAddress(string raw_addr) : raw_sector_addr(raw_addr)
{
    // get the sector spec
    // possibilities i am operating with are
    // G, GP, P, V
    string section = raw_addr.substr(0, 3);

    if (section.compare(0, 2, "GP") == 0)
    {
        this->parsed_sector_addr = ver2::mapping::GP_SectorMapping(raw_addr);
    }
    else if (section.compare(0, 1, "G") == 0)
    {
        this->parsed_sector_addr = ver2::mapping::G_SectorMapping(raw_addr);
    }
    else if (section.compare(0, 1, "V") == 0)
    {
        this->parsed_sector_addr = ver2::mapping::V_SectorMapping(raw_addr);
    }
    else if (section.compare(0, 1, "P") == 0)
    {
        this->parsed_sector_addr = ver2::mapping::P_SectorMapping(raw_addr);
    }
    // add the section
    this->parsed_sector_addr.section = section;
}

SECTOR_ADDR_T WAddress::getWarehouseWAddress()
{
    return this->parsed_sector_addr;
}

string WAddress::getRawSectorAddress()
{
    return this->raw_sector_addr;
}

WAddress::~WAddress() {}
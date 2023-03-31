#include "helper.h"
#include "general_declarations.h"

json readJsonFromFile(string path)
{
    ifstream f(path, ifstream::in);
    json new_obj;
    f >> new_obj;
    return new_obj;
}

void to_json(json &j, const OItem &it)
{
    j = json{{"Customer", it.Customer}, {"Product", it.Product}, {"Address", it.Address}, {"Qty", it.Qty}};
}

void to_json(json &j, const CartOItem &coi)
{
    j = json{
        {"Customer", coi.getOItem().Customer},
        {"Product", coi.getOItem().Product},
        {"Address", coi.getOItem().Address},
        {"Qty", coi.RealQty},
    };
}

void to_json(json &j, const BoxItem &bi)
{
    j = json{
        {"Customer", bi.order_item.Customer},
        {"Product", bi.order_item.Product},
        {"Address", bi.order_item.Address},
        {"Qty", bi.count_of_units},
    };
}

float pythagoras(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
{
    return sqrt(pow(abs(first_addr.x_coord - second_addr.x_coord), 2) + pow(abs(first_addr.y_coord - second_addr.y_coord), 2));
}

float euclidean_distance(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
{
    return abs(first_addr.x_coord - second_addr.x_coord) + abs(first_addr.y_coord - second_addr.y_coord);
}

int factorial(int num)
{
    static vector<pair<int, int>> prev_computed;
    for (auto i : prev_computed)
        if (i.first == num)
            return i.second;

    int res = 1;
    for (int i = 1; i <= num; i++)
        res *= i;

    prev_computed.push_back({num, res});
    return res;
}
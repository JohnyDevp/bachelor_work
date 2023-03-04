#ifndef _WADDRESS_FUNCTIONS_H_
#define _WADDRESS_FUNCTIONS_H_

#include <string>
#include <iostream>
#include <math.h>

#include "waddress.h"

namespace secV
{
    // V sector set up
    // TODO not sure about all these values
    const float x_offset = 25.0; // 2.5 meters from fictional left axis to the fictional corridor (at left)
    const float y_offset = 0.0;  // V addresses are at the top of the area - so zero offset set up
    const float horizontal_corridor_width = 24.0,
                middle_vertical_cor_width = 37.0, // middle and side-middle vertical corridors are of the same width as in G sector (also in the same place)
        side_middle_vertical_cor_width = 31.0,
                side_side_vertical_cor_width = 5.0;

    const float small_cell_depth = 4.0f,
                big_cell_depth = 6.0f,
                pallet_cell_depth = 12.0f,
                big_cell_width = 13.0f,
                small_cell_width = 1.3f,
                pallet_cell_width = 10.0f;

    // FIXME 380 is not probably accurate...
    const vector<string> rows_380_celled = {"BB", "DD"};
}

namespace secG
{
    // G sector set up
    const float x_offset = 40.0;                   // 4 meters from fictional left axis to the first vertical corridor
    const float y_offset = 130.0 + secV::y_offset; /*to the 00 row*/
    const float horizontal_corridor_width = 16.0,
                middle_vertical_cor_width = 37.0,
                side_middle_vertical_cor_width = 31.0,
                side_side_vertical_cor_width = 20.0;

    const float cell_depth = 4.0f,
                big_cell_width = 13.0f,
                small_cell_width = 1.6f;

    const vector<int> vertical_corridors = {
        (int)(x_offset + side_side_vertical_cor_width * 0.5),                                                                                                                               // the most left
        (int)(x_offset + side_side_vertical_cor_width + 7.0 * big_cell_width + side_middle_vertical_cor_width * 0.5),                                                                       // left from middle
        (int)(x_offset + side_side_vertical_cor_width + (7 + 10) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width * 0.5),                                      // middle
        (int)(x_offset + side_side_vertical_cor_width + (7 + 10 + 7) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width + side_middle_vertical_cor_width * 0.5), // right from middle
        (int)(x_offset + side_side_vertical_cor_width + (7 + 10 + 7) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width + side_middle_vertical_cor_width + 7.0 * big_cell_width + side_side_vertical_cor_width * 0.5)};
    const vector<int> rows_246_celled = {0, 1, 2, 3, 36, 37, 38, 39, 40};

    // exits of sector G

    // these coordinates should fit the exits of G sector towards the V sector
    const SECTOR_ADDR_T G_North_exits[] = {
        {"G00", (int)y_offset, 0, vertical_corridors[1]},
        {"G00", (int)y_offset, 0, vertical_corridors[2]},
        {"G00", (int)y_offset, 0, vertical_corridors[3]}};

    // these coordinates should fit the horizontal corridors between G and GP sectors
    // and so they should be usable when measuring distances also between G, GP and P sectors
    const map<int, int> G_East_exits = {
        {vertical_corridors[4], y_offset + 448},
        {vertical_corridors[4], y_offset + 448 + 24},
        {vertical_corridors[4], y_offset + 448 + 24 + 24},
        {vertical_corridors[4], y_offset + 448 + 24 + 24 + 24},
    };

    const map<int, int> G_South_exits = {
        {vertical_corridors[1], y_offset + 530.0}, // note that 530 is measured vertical length of G sector
        {vertical_corridors[2], y_offset + 530.0},
        {vertical_corridors[3], y_offset + 530.0}};
}

// namespace with functions usable when addresses are not mapped - addresses stay as they are, or at least letting all
// original information unchanged (no recomputing or some mathematical changing)
inline namespace ver1
{
    inline namespace mapping
    {
        inline SECTOR_ADDR_T G_SectorMapping(string raw_addr)
        {
            // create the structure for address
            SECTOR_ADDR_T parsed_addr;
            // load each part of address using substring function
            parsed_addr.section = raw_addr.substr(0, 3);
            parsed_addr.y_coord = stoi(raw_addr.substr(3, 2));
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            parsed_addr.x_coord = stoi(raw_addr.substr(7, 3));

            return parsed_addr;
        }
        inline SECTOR_ADDR_T GP_SectorMapping(string raw_addr)
        {
            // same process as by G_Sector
            return G_SectorMapping(raw_addr);
        }
        inline SECTOR_ADDR_T P_SectorMapping(string raw_addr)
        {
            // same process as by G_Sector
            return G_SectorMapping(raw_addr);
        }
        inline SECTOR_ADDR_T V_SectorMapping(string raw_addr)
        {
            (void)raw_addr;
            // TODO
            return SECTOR_ADDR_T();
        }
    }
    inline namespace measuring
    {
        inline int getDistanceInSectorG(WAddress first_addr, WAddress second_addr)
        {
            // the numbers of cells, between which there is a corridor
            // as corridors are not numbered, then the number is between the number of neighbouring cells
            const vector<float> vertical_corridors{7.5, 17.5, 24.5};
            const vector<int> horizontal_corridors{};
            // rows, which has 1-246 cells (the rest has 1-31)
            const vector<int> rows_of_246_cells{0, 1, 40};

            // if first_addr or second_addr is addresses in 0th or 1st or 40th row, then recalculate its cell-value (x axis)
            // cause the rest of rows are each of 1-31 cells but in the rows mentioned above are each of 1-246 cells
            // this knowledge is stored in these booleans
            bool first_addr_has_246_cells = false, second_addr_has_246_cells = false;
            if (find(rows_of_246_cells.begin(), rows_of_246_cells.end(), first_addr.getWarehouseWAddress().y_coord) != rows_of_246_cells.end())
            {
                // the row has 246 cells
                // 1 cell in 31-celled-row is 8 cells in 246-celled-row
                //! WARNING - it is not everywhere like described above
                first_addr_has_246_cells = true;
            }

            if (find(rows_of_246_cells.begin(), rows_of_246_cells.end(), second_addr.getWarehouseWAddress().y_coord) != rows_of_246_cells.end())
            {
                second_addr_has_246_cells = true;
            }

            // do the pattern (it is for the euclidean space)
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // THERE IS STORED THE USED CORRIDOR (the nearest to the first address)
            float used_corridor = -1; // -1 ... unset

            // DISTANCE TO THE NEAREST CORRIDOT from first address
            for (auto corridor : vertical_corridors)
            {
                float tmp;
                if ((float)first_addr.getWarehouseWAddress().x_coord < corridor && !first_addr_has_246_cells)
                {
                    // cell in row of 31 cells
                    used_corridor = corridor;
                    distance += abs((used_corridor - (float)first_addr.getWarehouseWAddress().x_coord));
                    break;
                }
                else if ((float)first_addr.getWarehouseWAddress().x_coord > vertical_corridors.back() && !first_addr_has_246_cells)
                {
                    // the cell number is greater then last (with highest number) corridor
                    // cell in row of 31 cells
                    used_corridor = vertical_corridors.back();
                    distance += abs((used_corridor - (float)first_addr.getWarehouseWAddress().x_coord));
                    break;
                }
                else if ((tmp = (float)first_addr.getWarehouseWAddress().x_coord / 8.0) < corridor && first_addr_has_246_cells)
                {
                    // cell in row of 246 cells - has to be normalized
                    used_corridor = corridor;
                    distance += abs((used_corridor - tmp));
                    break;
                }
                else if ((tmp = (float)first_addr.getWarehouseWAddress().x_coord / 8.0) < corridor && first_addr_has_246_cells)
                {
                    // the cell number is greater then last (with highest number) corridor
                    // cell in row of 246 cells - has to be normalized
                    used_corridor = vertical_corridors.back();
                    distance += abs((used_corridor - tmp));
                    break;
                }
            }

            // VERTICAL DISTANCE BETWEEN THE two addresses (first_addr and second_addr)
            distance += abs((second_addr.getWarehouseWAddress().y_coord - first_addr.getWarehouseWAddress().y_coord));

            // DISTANCE FROM THE CORRIDOR (stored above) TO THE SECOND ADDRESS
            if (!second_addr_has_246_cells)
            {
                // cell in row of 31 cells
                distance += abs((used_corridor - (float)second_addr.getWarehouseWAddress().x_coord));
            }
            else if (second_addr_has_246_cells)
            {
                // cell in row of 246 cells - has to be normalized
                distance += abs((used_corridor - (float)second_addr.getWarehouseWAddress().x_coord / 8.0));
            }

            // return the final distance between
            return distance;
        }
    }
}

// namespace with functions usable when addresses are mapped to some global format
inline namespace ver2
{
    inline namespace mapping
    {
        inline void GP_SectorMapping()
        {
        }

        inline SECTOR_ADDR_T G_SectorMapping(string raw_addr)
        {
            using namespace secG;

            SECTOR_ADDR_T parsed_addr;
            /****** G sector mapping *******/

            // Y coord -> row
            float y_tmp = stof(raw_addr.substr(3, 2));
            // parsed_addr.y_coord = ((int)(row_tmp / 2) * horizontal_corridor_width) + (row_tmp * cell_depth) + y_offset + ((int)row_tmp == 0 ? 0.0 : cell_depth) /*for the 00 row*/;
            parsed_addr.y_coord = y_offset;
            parsed_addr.y_coord += round((y_tmp - 0.3) / 2) * horizontal_corridor_width;
            parsed_addr.y_coord += ((int)y_tmp % 2 == 0) ? (y_tmp * cell_depth) : (y_tmp * cell_depth + cell_depth);
            // Z coord -> stays as it is
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            // X coord -> column
            if (find(rows_246_celled.begin(), rows_246_celled.end(), y_tmp) != rows_246_celled.end())
            {
                // if the row is of 246 cells then
                float x_tmp = stof(raw_addr.substr(7, 3));
                parsed_addr.x_coord = x_offset + side_side_vertical_cor_width + x_tmp * small_cell_width;
                if (x_tmp > 192)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 2 + middle_vertical_cor_width;
                else if (x_tmp > 136)
                    parsed_addr.x_coord += side_middle_vertical_cor_width + middle_vertical_cor_width;
                else if (x_tmp > 56)
                    parsed_addr.x_coord += side_middle_vertical_cor_width;
            }
            else
            {
                // if the row is of 31 cells
                float x_tmp = stof(raw_addr.substr(7, 3));
                parsed_addr.x_coord = x_offset + side_side_vertical_cor_width + x_tmp * big_cell_width;
                if (x_tmp > 24)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 2 + middle_vertical_cor_width;
                else if (x_tmp > 17)
                    parsed_addr.x_coord += side_middle_vertical_cor_width + middle_vertical_cor_width;
                else if (x_tmp > 7)
                    parsed_addr.x_coord += side_middle_vertical_cor_width;
            }

            // return of the parsed (mapped) address
            return parsed_addr;
        }

        inline void P_SectorMapping()
        {
        }

        inline SECTOR_ADDR_T V_SectorMapping(string raw_addr)
        {
            using namespace secV; // the specification for sector V is used

            SECTOR_ADDR_T parsed_addr;
            /****** V sector mapping *******/

            // Y coord -> row
            int y_coord = toupper(raw_addr.substr(1, 1)[0]) - (int)'A'; // from 'VAA' -> 'A' -> 65, etc...
            parsed_addr.y_coord = y_offset;
            parsed_addr.y_coord += round((y_coord + 0.3) / 2) * horizontal_corridor_width;
            parsed_addr.y_coord += pallet_cell_depth + (y_coord > 0) ? ((round((y_coord + 0.3) / 2) * small_cell_depth) + (y_coord / 2 * big_cell_depth)) : (0);
            // Z coord -> stays as it is
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            // X coord -> column
            float x_coord = stof(raw_addr.substr(7, 3));
            if (y_coord == 0)
            {
                // pallet row AAA
                // all constants used there serve for better coordinates expression according to the pallet row design
                parsed_addr.x_coord = (x_offset + side_side_vertical_cor_width + big_cell_width * 0.5) + (x_coord - 1) * pallet_cell_width + pallet_cell_width * 0.5;
                if (x_coord > 36)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 2.7 + middle_vertical_cor_width * 1.4;
                else if (x_coord > 26)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 1.2 + middle_vertical_cor_width * 1.4;
                else if (x_coord > 12)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 1.2;
            }
            else if (y_coord == 1 || y_coord == 3)
            {
                // rows BB and DD of 380 cells
                parsed_addr.x_coord = (x_offset + side_side_vertical_cor_width) + (x_coord - 1) * small_cell_width + small_cell_width * 0.5;
                if (x_coord > 280)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 1.66 /*some edit according to the real map*/ + middle_vertical_cor_width;
                else if (x_coord > 200)
                    parsed_addr.x_coord += side_middle_vertical_cor_width + middle_vertical_cor_width;
                else if (x_coord > 100)
                    parsed_addr.x_coord += side_middle_vertical_cor_width;
            }
            else
            {
                // rows CCC and EEE (of normal cells)
                parsed_addr.x_coord = (x_offset + side_side_vertical_cor_width) + (x_coord - 1) * big_cell_width + big_cell_width * 0.5;
                if (x_coord > 28)
                    parsed_addr.x_coord += side_middle_vertical_cor_width * 1.66 /*some edit according to the real map*/ + middle_vertical_cor_width;
                else if (x_coord > 20)
                    parsed_addr.x_coord += side_middle_vertical_cor_width + middle_vertical_cor_width;
                else if (x_coord > 10)
                    parsed_addr.x_coord += side_middle_vertical_cor_width;
            }
            // return of the parsed (mapped) address
            return parsed_addr;
        }
    }

    inline namespace measuring
    {
        inline int getDistanceInSectorG(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            using namespace secG;
            // order the two addresses from left to right
            if (first_addr.x_coord > second_addr.x_coord)
                swap(first_addr, second_addr);

            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // SPECIAL CASE - CHECK FOR THE SAME ROW - return just the difference
            if (first_addr.y_coord - second_addr.y_coord == 0)
                return abs(first_addr.x_coord - second_addr.x_coord);

            // stored x coord of both addresses for better readability
            auto first_addr_x = first_addr.x_coord;
            auto second_addr_x = second_addr.x_coord;
            for (size_t i = 0; i < vertical_corridors.size() - 1; i++)
            {
                // check the first address of being between current two corridors
                if (first_addr_x >= vertical_corridors[i] && first_addr_x <= vertical_corridors[i + 1])
                {
                    // found the column of the first address
                    if (second_addr_x >= vertical_corridors[i] && second_addr_x <= vertical_corridors[i + 1])
                    {
                        // the second address fits too
                        if (first_addr_x - vertical_corridors[i] + second_addr_x - vertical_corridors[i] <
                            vertical_corridors[i + 1] - first_addr_x + vertical_corridors[i + 1] - second_addr_x)
                        {
                            // better is left corridor
                            distance += first_addr_x - vertical_corridors[i];
                            distance += abs(first_addr.y_coord - second_addr.y_coord);
                            distance += second_addr_x - vertical_corridors[i];
                        }
                        else
                        {
                            // better is right corridor
                            distance += vertical_corridors[i + 1] - first_addr_x;
                            distance += abs(first_addr.y_coord - second_addr.y_coord);
                            distance += vertical_corridors[i + 1] - second_addr_x;
                        }
                    }
                    else
                    {
                        // the second address doesnt fit the column as the first address is set to - so count at rest as normall
                        // as we make first address be the left one, count distance to the right corridor
                        distance += vertical_corridors[i + 1] - first_addr_x;
                        distance += abs(first_addr.y_coord - second_addr.y_coord);
                        distance += second_addr_x - vertical_corridors[i + 1]; // we know that the second address has to have greater x value, cause its
                    }
                    // nothing more to compute - return the result of distance measurement
                    return distance;
                } // if
            }     // for
            return distance;
        }

        inline int getDistanceInSectorV(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            using namespace secV;

            const vector<int> vertical_corridors = {
                (int)(x_offset + side_side_vertical_cor_width * 0.5),                                                                                                                                // the most left
                (int)(x_offset + side_side_vertical_cor_width + 10.0 * big_cell_width + side_middle_vertical_cor_width * 0.5),                                                                       // left from middle
                (int)(x_offset + side_side_vertical_cor_width + (10 + 10) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width * 0.5),                                      // middle
                (int)(x_offset + side_side_vertical_cor_width + (10 + 10 + 8) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width + side_middle_vertical_cor_width * 0.5), // right from middle
                (int)(x_offset + side_side_vertical_cor_width + (10 + 10 + 8 + 10) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width + side_middle_vertical_cor_width + side_side_vertical_cor_width * 0.5)};

            // order the two addresses from left to right
            if (first_addr.x_coord > second_addr.x_coord)
                swap(first_addr, second_addr);

            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // SPECIAL CASE - CHECK FOR THE SAME ROW - return just the difference
            if (first_addr.y_coord - second_addr.y_coord == 0)
                return abs(first_addr.x_coord - second_addr.x_coord);

            // stored x coord of both addresses for better readability
            auto first_addr_x = first_addr.x_coord;
            auto second_addr_x = second_addr.x_coord;
            for (size_t i = 0; i < vertical_corridors.size() - 1; i++)
            {
                // check the first address whether it is between current two corridors
                if (first_addr_x >= vertical_corridors[i] && first_addr_x <= vertical_corridors[i + 1])
                {
                    // found the column of the first address
                    if (second_addr_x >= vertical_corridors[i] && second_addr_x <= vertical_corridors[i + 1])
                    {
                        // the second address fits too
                        if (first_addr_x - vertical_corridors[i] + second_addr_x - vertical_corridors[i] <
                            vertical_corridors[i + 1] - first_addr_x + vertical_corridors[i + 1] - second_addr_x)
                        {
                            // better is left corridor
                            distance += first_addr_x - vertical_corridors[i];
                            distance += abs(first_addr.y_coord - second_addr.y_coord);
                            distance += second_addr_x - vertical_corridors[i];
                        }
                        else
                        {
                            // better is right corridor
                            distance += vertical_corridors[i + 1] - first_addr_x;
                            distance += abs(first_addr.y_coord - second_addr.y_coord);
                            distance += vertical_corridors[i + 1] - second_addr_x;
                        }
                    }
                    else
                    {
                        // the second address doesnt fit the column as the first address is set to - so count at rest as normall
                        // as we make first address be the left one, count distance to the right corridor
                        distance += vertical_corridors[i + 1] - first_addr_x;
                        distance += abs(first_addr.y_coord - second_addr.y_coord);
                        distance += second_addr_x - vertical_corridors[i + 1]; // we know that the second address has to have greater x value, cause its
                    }
                    // nothing more to compute - return the result of distance measurement
                    return distance;
                } // if
            }     // for
            return distance;
        }
    }
}

#endif
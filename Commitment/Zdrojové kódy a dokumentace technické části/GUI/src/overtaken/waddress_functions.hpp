#ifndef _WADDRESS_FUNCTIONS_H_
#define _WADDRESS_FUNCTIONS_H_

#include <string>
#include <iostream>
#include <math.h>

#include "./../bachelor_work_code/src/WarehousePickingOpt.h"
#include "helper.h"

typedef struct : public SECTOR_ADDR_T
{
    int current_weight = 0;
} GRAPH_POINT_T;

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

    // the row (Y coordinate, but in addresse's format), which is first in the opposite of another row -> so there is a horizontal corridor between them
    // for the better computation of distance while both addresses are in the same horizontal corridor but not with the same Y coord
    const int first_row_opposite = 0;

    const vector<int> vertical_corridors = {
        (int)(x_offset + side_side_vertical_cor_width * 0.5),                                                                                                                                // the most left
        (int)(x_offset + side_side_vertical_cor_width + 10.0 * big_cell_width + side_middle_vertical_cor_width * 0.5),                                                                       // left from middle
        (int)(x_offset + side_side_vertical_cor_width + (10 + 10) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width * 0.5),                                      // middle
        (int)(x_offset + side_side_vertical_cor_width + (10 + 10 + 8) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width + side_middle_vertical_cor_width * 0.5), // right from middle
        (int)(x_offset + side_side_vertical_cor_width + (10 + 10 + 8 + 10) * big_cell_width + side_middle_vertical_cor_width + middle_vertical_cor_width + side_middle_vertical_cor_width + side_side_vertical_cor_width * 0.5)};

    // FIXME 380 is not probably accurate...
    const vector<string> rows_380_celled = {"BB", "DD"};

    const map<int, int> V_East_exits = {
        {vertical_corridors[4], y_offset + pallet_cell_depth + horizontal_corridor_width * 0.5},
        {vertical_corridors[4], y_offset + pallet_cell_depth + horizontal_corridor_width + small_cell_depth + big_cell_depth + horizontal_corridor_width * 0.5},
        {vertical_corridors[4], y_offset + pallet_cell_depth + 2 * horizontal_corridor_width + 2 * small_cell_depth + 2 * big_cell_depth + horizontal_corridor_width * 0.5},
    };

    const int y_for_south_exits = y_offset + pallet_cell_depth + 2 * horizontal_corridor_width + 2 * small_cell_depth + 2 * big_cell_depth + horizontal_corridor_width * 0.5;
    const map<int, int> V_South_exits = {
        {vertical_corridors[1], y_for_south_exits},
        {vertical_corridors[2], y_for_south_exits},
        {vertical_corridors[3], y_for_south_exits}};
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

    // the row (Y coordinate, but in addresse's format), which is first in the opposite of another row -> so there is a horizontal corridor between them
    // for the better computation of distance while both addresses are in the same horizontal corridor but not with the same Y coord
    const int first_row_opposite = 1;

    // exits of sector G
    // these coordinates should fit the exits of G sector towards the V sector
    const GRAPH_POINT_T G_north_exit = {"G00", (int)y_offset, 0, 545 + (int)x_offset};
    const GRAPH_POINT_T G_lower_exit = {"G00", (int)(y_offset + 448 + 24 + 24), 0, vertical_corridors[4] + (int)(side_side_vertical_cor_width * 0.5)};

    const SECTOR_ADDR_T G_North_exits[] = {
        {"G00", (int)y_offset, 0, vertical_corridors[1]},
        {"G00", (int)y_offset, 0, vertical_corridors[2]},
        {"G00", (int)y_offset, 0, vertical_corridors[3]}};

    // these coordinates should fit the horizontal corridors between G and GP sectors
    // and so they should be usable when measuring distances also between G, GP and P sectors
    const SECTOR_ADDR_T G_East_exits[] = {
        {"G00", (int)(y_offset + 448), 0, vertical_corridors[4]},
        {"G00", (int)(y_offset + 448 + 24), 0, vertical_corridors[4]},
        {"G00", (int)(y_offset + 448 + 24 + 24), 0, vertical_corridors[4]},
        {"G00", (int)(y_offset + 448 + 24 + 24 + 24), 0, vertical_corridors[4]},
    };

    const SECTOR_ADDR_T G_South_exits[] = {
        {"G00", (int)(y_offset + 530.0), 0, vertical_corridors[1]}, // note that 530 is measured vertical length of G sector
        {"G00", (int)(y_offset + 530.0), 0, vertical_corridors[2]},
        {"G00", (int)(y_offset + 530.0), 0, vertical_corridors[3]}};
}

namespace secP
{
    // P sector set up
    // notice, that P sector is turned by 90 degrees (so rows -> columns) against G sector
    const float x_offset = 714.0 + secG::x_offset; // to the first cell from left site
    const float y_offset = 115.0 + secV::y_offset;
    const float horizontal_corridor_width = 20.0, // width of the only one horizontal corridor
        vertical_cor_width = 34.0;

    const float cell_depth = 10.0f,
                cell_width = 9.5f; // note: measured vertically; it is with of one cell of four, which are in the once visible block

    // definition of only three corridors
    // defining X coordinates of them
    // the rest is neglected, because of the small difference when computing the distance of the far cells of the P sector
    const vector<int> vertical_corridors = {
        (int)(x_offset), // corridor that is along the 00 column
        (int)(x_offset + 2 * cell_depth + vertical_cor_width * 0.5),
        (int)(x_offset + 4 * cell_depth + vertical_cor_width * 1.5),
        (int)(x_offset + 6 * cell_depth + vertical_cor_width * 2.5)};

    // defining Y coordinates
    const vector<int> horizontal_cooridors = {
        (int)(y_offset),
        (int)(y_offset + 48 * cell_width + 0.5 * horizontal_corridor_width),
        (int)(y_offset + 48 * cell_width + horizontal_corridor_width + 10 * cell_width + 0.5 * horizontal_corridor_width)};

    // the row (X coordinate, but in addresse's format), which is first in the opposite of another column -> so there is a vertical corridor between them
    // for the better computation of distance while both addresses are in the same vertical corridor but not with the same X coord
    const int first_column_opposite = 1;

    // exits of sector P
    // these coordinates should fit the exits of P sector towards the G (GP) sector
    const GRAPH_POINT_T P_middle_exit = {"P00", (int)horizontal_cooridors[0], 0, (int)x_offset};

    const GRAPH_POINT_T P_north_exit = {"P00", (int)y_offset, 0, (int)x_offset};

    const GRAPH_POINT_T P_south_exit = {"P00", (int)y_offset + 683, 0, (int)x_offset};
}

namespace secGP
{
    // GP sector set up // TODO find the real layout
    // notice, that GP sector is turned by 90 degrees (so rows -> columns) against G sector
    const float x_offset = 545.0 + secG::x_offset;
    const float y_offset = 134.0 + secG::y_offset;
    const float horizontal_corridor_width = 32.0,
                vertical_cor_width = 18.0;

    const float cell_gap = 2.9f, // the gap between some cells (according to the real layout)
        cell_depth = 6.0f,
                cell_width = 11.7f; // the average of two types below, computed according to the layout of the column
                                    // first_type_cell_width = 10.0f,// the real widths, not used, just approximated
                                    // second_type_cell_width = 13.0f;

    const vector<int> vertical_corridors = {
        (int)(x_offset + cell_depth + vertical_cor_width * 0.5), // corridor that is along the 00 column
        (int)(x_offset + 2 * cell_depth + vertical_cor_width * 1.5),
        (int)(x_offset + 4 * cell_depth + vertical_cor_width * 2.5)};

    const vector<int> horizontal_corridors = {
        (int)(y_offset - 0.5 * horizontal_corridor_width),
        (int)(y_offset + 6 * cell_width + 2 * cell_gap + 0.5 * horizontal_corridor_width),
        (int)(y_offset + 26 * cell_width + 13 * cell_gap + 1.5 * horizontal_corridor_width)};

    const int first_column_opposite = 1;

    const vector<SECTOR_ADDR_T> GP_exits = {
        {"GP0", horizontal_corridors[0], 0, (int)(vertical_corridors[2] + vertical_cor_width * 0.5 + 30)},
        {"GP0", horizontal_corridors[1], 0, (int)(vertical_corridors[2] + vertical_cor_width * 0.5 + 30)},
        {"GP0", horizontal_corridors[2], 0, (int)(vertical_corridors[2] + vertical_cor_width * 0.5 + 30)},
    };
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
        inline SECTOR_ADDR_T GP_SectorMapping(string raw_addr)
        {
            // TODO this mapping IS NOT PERFECT, there are place for enhance
            using namespace secGP;

            SECTOR_ADDR_T parsed_addr;
            /****** GP sector mapping *******/
            // NOTE: SEE DWG FILE FOR BETTER UNDERSTANDING

            // X coord -> column
            float x_tmp = stof(raw_addr.substr(3, 2));
            parsed_addr.x_coord_original = x_tmp; // ORIDINAL PART
            // note: columns start from 01
            parsed_addr.x_coord = x_offset + x_tmp * cell_depth + (x_tmp - 1) * vertical_cor_width;
            parsed_addr.x_coord -= (x_tmp == 3 || x_tmp == 5) ? cell_depth : 0;         // correction according to the real layout and real possible of approach to the cells for picking
            parsed_addr.x_coord -= (x_tmp == 4 || x_tmp == 5) ? vertical_cor_width : 0; // correction according to the real layout and real possible of approach to the cells for picking

            // Z coord -> stays as it is
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            parsed_addr.z_coord_original = parsed_addr.z_coord; // ORIDINAL PART

            // Y coord -> row
            // if the row is of 246 cells then
            float y_tmp = stof(raw_addr.substr(7, 3));
            parsed_addr.y_coord_original = y_tmp; // ORIDINAL PART
            parsed_addr.y_coord = y_offset + y_tmp * cell_width + (y_tmp / 2) * cell_gap;
            if (x_tmp > 6)
                parsed_addr.y_coord += horizontal_corridor_width;

            // return of the parsed (mapped) address
            return parsed_addr;
        }

        inline SECTOR_ADDR_T G_SectorMapping(string raw_addr)
        {
            using namespace secG;

            SECTOR_ADDR_T parsed_addr;
            /****** G sector mapping *******/

            // Y coord -> row
            float y_tmp = stof(raw_addr.substr(3, 2));
            parsed_addr.y_coord_original = y_tmp; // ORIDINAL PART
            // parsed_addr.y_coord = ((int)(row_tmp / 2) * horizontal_corridor_width) + (row_tmp * cell_depth) + y_offset + ((int)row_tmp == 0 ? 0.0 : cell_depth) /*for the 00 row*/;
            parsed_addr.y_coord = y_offset;
            parsed_addr.y_coord += round((y_tmp - 0.3) / 2) * horizontal_corridor_width;
            parsed_addr.y_coord += ((int)y_tmp % 2 == 0) ? (y_tmp * cell_depth) : (y_tmp * cell_depth + cell_depth);
            // Z coord -> stays as it is
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            parsed_addr.z_coord_original = parsed_addr.z_coord; // ORIDINAL PART
            // X coord -> column
            float x_tmp = stof(raw_addr.substr(7, 3));
            parsed_addr.x_coord_original = x_tmp; // ORIDINAL PART
            if (find(rows_246_celled.begin(), rows_246_celled.end(), y_tmp) != rows_246_celled.end())
            {
                // if the row is of 246 cells then

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

        inline SECTOR_ADDR_T P_SectorMapping(string raw_addr)
        {
            using namespace secP;

            SECTOR_ADDR_T parsed_addr;
            /****** P sector mapping *******/

            // X coord -> column
            float x_tmp = stof(raw_addr.substr(3, 2));
            parsed_addr.x_coord_original = x_tmp; // ORIDINAL PART
            parsed_addr.x_coord = x_offset + round((x_tmp - 0.3) / 2) * vertical_cor_width;
            parsed_addr.x_coord += ((int)x_tmp % 2 == 0) ? (x_tmp * cell_depth) : (x_tmp * cell_depth + cell_depth);

            // Z coord -> stays as it is
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            parsed_addr.z_coord_original = parsed_addr.z_coord; // ORIDINAL PART

            // Y coord -> row
            // if the row is of 246 cells then
            float y_tmp = stof(raw_addr.substr(7, 3));
            parsed_addr.y_coord_original = y_tmp; // ORIDINAL PART
            parsed_addr.y_coord = y_offset + (y_tmp - 0.3 / 4) * cell_width + cell_width;
            if (x_tmp > 48) // TODO after that cell is marked horizontal corridor - BUT ONLY IN THIS CONFIGURATION, not sure if this is for real
                parsed_addr.y_coord += horizontal_corridor_width;

            // return of the parsed (mapped) address
            return parsed_addr;
        }

        inline SECTOR_ADDR_T V_SectorMapping(string raw_addr)
        {
            using namespace secV; // the specification for sector V is used

            SECTOR_ADDR_T parsed_addr;
            /****** V sector mapping *******/

            // Y coord -> row
            int y_coord = toupper(raw_addr.substr(1, 1)[0]) - (int)'A'; // from 'VAA' -> 'A' -> 65, etc...
            parsed_addr.y_coord_original = y_coord;
            parsed_addr.y_coord = y_offset;
            parsed_addr.y_coord += round((y_coord + 0.3) / 2) * horizontal_corridor_width;
            parsed_addr.y_coord += pallet_cell_depth + (y_coord > 0) ? ((round((y_coord + 0.3) / 2) * small_cell_depth) + (y_coord / 2 * big_cell_depth)) : (0);
            // Z coord -> stays as it is
            parsed_addr.z_coord = stoi(raw_addr.substr(5, 2));
            parsed_addr.z_coord_original = parsed_addr.z_coord;
            // X coord -> column
            float x_coord = stof(raw_addr.substr(7, 3));
            parsed_addr.x_coord_original = x_coord;
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

        /// @brief handling the special case of the addresses in the same horizontal corridor (the same row)
        /// @param first_addr
        /// @param second_addr
        /// @param first_row_opposite Y original coord of the first row which faces the first corridor from the sector's specification
        /// @return computed shortest distance or -1 when special case hasn't been recognized
        inline int horizontalCorridorSpecialCase_G_V(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr, int first_row_opposite)
        {
            // SPECIAL CASE - CHECK FOR THE SAME ROW - return just the difference
            //  this computation is handled later on, but here it is set for faster result
            if (first_addr.y_coord_original - second_addr.y_coord_original == 0)
            {
                return abs(first_addr.x_coord - second_addr.x_coord);
            }
            else
            {
                // for the next part of computation order the two addresses from down to up by Y coord (remember, in warehouse layout the beggining of axises are in the top left corner )
                if (first_addr.y_coord_original > second_addr.y_coord_original)
                    swap(first_addr, second_addr);

                // check for the same horizontal corridor, but not the same Y_coord
                // the same corridor if and only if odd number follows the even one

                // behave according to the number of the first row in first horizotnal corridor
                if (first_row_opposite % 2 == 0)
                {
                    if (first_addr.y_coord_original % 2 == 0 && first_addr.y_coord_original + 1 == second_addr.y_coord_original)
                        return pythagoras(first_addr, second_addr);
                }
                else
                {
                    if (first_addr.y_coord_original % 2 == 1 && first_addr.y_coord_original + 1 == second_addr.y_coord_original)
                        return pythagoras(first_addr, second_addr);
                }

                // NOTE: simple explanation - to match this case handled right above, first row has to be for one unit before the second one
            }

            return -1; // when special case hasn't been recognized
        }

        inline int horizontalCorridorSpecialCase_P_GP(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr, int first_row_opposite)
        {
            // SPECIAL CASE - CHECK FOR THE SAME ROW - return just the difference
            //  this computation is handled later on, but here it is set for faster result
            if (first_addr.x_coord_original - second_addr.x_coord_original == 0)
                return abs(first_addr.y_coord - second_addr.y_coord);
            else
            {
                // for the next part of computation order the two addresses from left to right by X coord (remember, in warehouse layout the beggining of axises are in the top left corner )
                if (first_addr.x_coord_original > second_addr.x_coord_original)
                    swap(first_addr, second_addr);

                // check for the same verticall corridor, but not the same X_coord
                // the same corridor if and only if odd number follows the even one

                // behave according to the number of the first row in first horizotnal corridor
                if (first_row_opposite % 2 == 0)
                {
                    if (first_addr.x_coord_original % 2 == 0 && first_addr.x_coord_original + 1 == second_addr.x_coord_original)
                        return pythagoras(first_addr, second_addr);
                }
                else
                {
                    if (first_addr.x_coord_original % 2 == 1 && first_addr.x_coord_original + 1 == second_addr.x_coord_original)
                        return pythagoras(first_addr, second_addr);
                }

                // NOTE: simple explanation - to match this case handled right above, first row has to be for one unit before the second one
            }

            return -1; // when special case hasn't been recognized
        }

        inline int getDistanceInSectorG(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            using namespace secG;
            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // handling special case
            int distance_tmp = horizontalCorridorSpecialCase_G_V(first_addr, second_addr, first_row_opposite);
            if (distance_tmp >= 0)
            {
                return distance_tmp;
            }
            
            // for the next part of computation order the two addresses from left to right
            if (first_addr.x_coord > second_addr.x_coord)
                swap(first_addr, second_addr);

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

            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // handling special case
            int distance_tmp = horizontalCorridorSpecialCase_G_V(first_addr, second_addr, first_row_opposite);
            if (distance_tmp >= 0)
                return distance_tmp;

            // for the next part of computation order the two addresses from left to right
            if (first_addr.x_coord > second_addr.x_coord)
                swap(first_addr, second_addr);

            // stored x coord of both addresses for better readability
            auto first_addr_x = first_addr.x_coord;
            auto second_addr_x = second_addr.x_coord;
            // first check for special case - both addresses in the same HORIZONTAL corridor (so the same Y coord) -> meaning there is shorter distacne to go

            // find the best way, if the addresses are in the same column (bordered from both sites by vertical corridors)
            // also there is handled the other way with simple subtraction of both coordinates
            for (size_t i = 0; i < vertical_corridors.size() - 1; i++)
            {
                // check the first address whether it is between current two corridors
                if (first_addr_x >= vertical_corridors[i] && first_addr_x <= vertical_corridors[i + 1])
                {
                    // decide the column of the second address
                    if (second_addr_x >= vertical_corridors[i] && second_addr_x <= vertical_corridors[i + 1])
                    {
                        // the second address fits the same corridor too
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
                        // the second address doesnt fit the column as the first address is set to - so count the rest as normall
                        // as we make first address be the left one, count distance to the right corridor
                        distance += abs(first_addr_x - second_addr_x);
                        distance += abs(first_addr.y_coord - second_addr.y_coord);
                    }
                    // nothing more to compute - return the result of distance measurement
                    return distance;
                } // if
            }     // for

            // return just euclidean space
            cerr << "not found proper solution for distance measuring, return euclidean distance" << endl;
            return euclidean_distance(first_addr, second_addr);

            return distance;
        }

        inline int getDistanceInSectorP(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            using namespace secP;
            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // handling special case
            int distance_tmp = horizontalCorridorSpecialCase_G_V(first_addr, second_addr, first_column_opposite);
            if (distance_tmp >= 0)
                return distance_tmp;

            // for the next part of computation order the two addresses from up to down
            if (first_addr.y_coord > second_addr.y_coord)
                swap(first_addr, second_addr);

            // decide in which row (divided by the corridor) the first address is
            for (int corr = 0; corr < (int)horizontal_cooridors.size() - 1; corr++)
            {
                // if the y coord of first addr fits the space between two corridors
                if (horizontal_cooridors[corr] <= first_addr.y_coord && first_addr.y_coord <= horizontal_cooridors[corr + 1])
                {
                    // if also the second address is in the same corridor
                    if (horizontal_cooridors[corr] <= second_addr.y_coord && second_addr.y_coord <= horizontal_cooridors[corr + 1])
                    {
                        // find the better one of the neighbouring corridors
                        if (abs(2 * horizontal_cooridors[corr] - first_addr.y_coord - second_addr.y_coord) <
                            abs(2 * horizontal_cooridors[corr + 1] - first_addr.y_coord - second_addr.y_coord))
                        {
                            // better is the upper corridor
                            distance += abs(2 * horizontal_cooridors[corr] - first_addr.y_coord - second_addr.y_coord);
                            distance += abs(first_addr.x_coord - second_addr.x_coord);
                        }
                        else
                        {
                            // better is the lower corridor
                            distance += abs(2 * horizontal_cooridors[corr + 1] - first_addr.y_coord - second_addr.y_coord);
                            distance += abs(first_addr.x_coord - second_addr.x_coord);
                        }
                    }
                    else
                    {
                        // the second address is in other row
                        distance += abs(first_addr.y_coord - second_addr.y_coord);
                        distance += abs(first_addr.x_coord - second_addr.x_coord);
                    }
                }
            }

            return distance;
        }

        inline int getDistanceInSectorGP(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            using namespace secGP;
            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // handling special case
            int distance_tmp = horizontalCorridorSpecialCase_G_V(first_addr, second_addr, first_column_opposite);
            if (distance_tmp >= 0)
                return distance_tmp;

            // for the next part of computation order the two addresses from up to down
            if (first_addr.y_coord > second_addr.y_coord)
                swap(first_addr, second_addr);

            // decide in which row (divided by the corridor) the first address is
            for (int corr = 0; corr < (int)horizontal_corridors.size() - 1; corr++)
            {
                // if the y coord of first addr fits the space between two corridors
                if (horizontal_corridors[corr] <= first_addr.y_coord && first_addr.y_coord <= horizontal_corridors[corr + 1])
                {
                    // if also the second address is in the same corridor
                    if (horizontal_corridors[corr] <= second_addr.y_coord && second_addr.y_coord <= horizontal_corridors[corr + 1])
                    {
                        // find the better one of the neighbouring corridors
                        if (abs(2 * horizontal_corridors[corr] - first_addr.y_coord - second_addr.y_coord) <
                            abs(2 * horizontal_corridors[corr + 1] - first_addr.y_coord - second_addr.y_coord))
                        {
                            // better is the upper corridor
                            distance += abs(2 * horizontal_corridors[corr] - first_addr.y_coord - second_addr.y_coord);
                            distance += abs(first_addr.x_coord - second_addr.x_coord);
                        }
                        else
                        {
                            // better is the lower corridor
                            distance += abs(2 * horizontal_corridors[corr + 1] - first_addr.y_coord - second_addr.y_coord);
                            distance += abs(first_addr.x_coord - second_addr.x_coord);
                        }
                    }
                    else
                    {
                        // the second address is in other row
                        distance += abs(first_addr.y_coord - second_addr.y_coord);
                        distance += abs(first_addr.x_coord - second_addr.x_coord);
                    }
                }
            }

            return distance;
        }

        inline int getDistanceBetweenSectors_G_V(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float distance = 0;

            // special case - both addresses share the same corridor (one between G and V)
            if (first_addr.y_coord_original == 0 && second_addr.y_coord_original == 4 /*stands for VEE*/)
                return pythagoras(first_addr, second_addr);

            // for the next part of computation order the two addresses from left to right
            if (first_addr.x_coord > second_addr.x_coord)
                swap(first_addr, second_addr);

            // mostly used numbers and variables for secV
            using namespace secG;

            // stored x coord of both addresses for better readability of the code below
            auto first_addr_x = first_addr.x_coord;
            auto second_addr_x = second_addr.x_coord;

            // loop through the corridors from 1, because these are same for both sectors (G&V)
            for (size_t i = 0; i < vertical_corridors.size() - 1; i++)
            {
                // check the first address of being between current two corridors
                if ((first_addr_x >= vertical_corridors[i] && first_addr_x <= vertical_corridors[i + 1]) ||
                    (first_addr_x < vertical_corridors[i] && i == 0) || /*the corridor is somewhere before the first corridor */
                    (first_addr_x > vertical_corridors[i + 1] && i + 1 == vertical_corridors.size() - 1) /*the corridor is somewhere after the last corridor*/)
                {
                    // now try to decide whether the second address is in the same column or not
                    if ((second_addr_x >= vertical_corridors[i] && second_addr_x <= vertical_corridors[i + 1]) ||
                        (second_addr_x < vertical_corridors[i] && i == 0) ||
                        (second_addr_x > vertical_corridors[i + 1] && i + 1 == vertical_corridors.size() - 1) /*the corridor is somewhere after the last corridor*/)
                    {
                        // the second address fits the same column too
                        if (((first_addr_x - vertical_corridors[i] + second_addr_x - vertical_corridors[i] <
                              vertical_corridors[i + 1] - first_addr_x + vertical_corridors[i + 1] - second_addr_x) &&
                             i != 0) ||
                            i + 1 == vertical_corridors.size() - 1)
                        {
                            // better is left corridor
                            // or the i+1 vertical corridor is the one most right, so there is no option to use it while passing
                            // from G to V
                            distance += first_addr_x - vertical_corridors[i];
                            distance += abs(first_addr.y_coord - second_addr.y_coord);
                            distance += second_addr_x - vertical_corridors[i];
                        }
                        else
                        {
                            // better is right corridor
                            // or the used vertical corridor is 0 (viz the condition), so there is no option to use
                            // left corridor - so use the right one
                            distance += vertical_corridors[i + 1] - first_addr_x;
                            distance += abs(first_addr.y_coord - second_addr.y_coord);
                            distance += vertical_corridors[i + 1] - second_addr_x;
                        }
                    }
                    else
                    {
                        // the second address doesnt fit the column as the first address is set to - so count at rest as normall
                        // as we make first address be the left one, count distance to the right corridor
                        distance += abs(second_addr_x - first_addr_x);
                        distance += abs(first_addr.y_coord - second_addr.y_coord);
                    }
                    // nothing more to compute - return the result of distance measurement
                    return distance;
                } // if
            }     // for
            return distance;
        }

        inline int getDistanceBetweenSectors_G_P(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            // swap the addresses to fit order G - P
            if (first_addr.section[0] == 'P')
                swap(first_addr, second_addr);

            //**************************** do the pattern (possible because of the EUCLIDEAN space) ***********************************************
            // THERE IS STORED THE FINAL DISTANCE
            float north_exit_distance = 0, lower_exit_distance = 0;
            using namespace secG;
            // distance to the north exit
            if (first_addr.x_coord > vertical_corridors[4])
            {
                north_exit_distance += abs(first_addr.x_coord - vertical_corridors[4]) + abs(vertical_corridors[4] - G_north_exit.x_coord);
                north_exit_distance += abs(first_addr.y_coord - G_north_exit.y_coord);
            }
            else
            {
                north_exit_distance += abs(first_addr.x_coord - G_north_exit.x_coord);
                north_exit_distance += abs(first_addr.y_coord - G_north_exit.y_coord);
            }
            // lower exit distance
            lower_exit_distance += euclidean_distance(first_addr, secG::G_lower_exit);
            vector<GRAPH_POINT_T> queue = {secP::P_north_exit, secP::P_middle_exit, secP::P_south_exit};
            int best_distance_lower = INT32_MAX;
            for (auto exit : queue)
            {
                int tmp = euclidean_distance(secG::G_lower_exit, exit) + lower_exit_distance;
                tmp += euclidean_distance(exit, second_addr);
                if (tmp < best_distance_lower)
                    best_distance_lower = tmp;
            }

            int best_distance_north = INT32_MAX;
            for (auto exit : queue)
            {
                int tmp = euclidean_distance(secG::G_north_exit, exit) + north_exit_distance;
                tmp += euclidean_distance(exit, second_addr);
                if (tmp < best_distance_north)
                    best_distance_north = tmp;
            }

            return (best_distance_lower < best_distance_north) ? best_distance_lower : best_distance_north;
        }

        inline int getDistanceBetweenSectors_G_GP(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            int distance = 0;

            // swap the addresses to be in order G -> GP
            if (first_addr.section.substr(0, 2) == "GP")
                swap(first_addr, second_addr);

            // compute the distance between G address and the edge between G and GP sector
            distance += euclidean_distance(first_addr, secG::G_lower_exit);

            // compute the distance between the edge and the GP address
            distance += getDistanceInSectorGP(secG::G_lower_exit, second_addr);

            return distance;
        }

        inline int getDistanceBetweenSectors_V_P(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            return euclidean_distance(first_addr, second_addr);
        }

        inline int getDistanceBetweenSectors_V_GP(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            return euclidean_distance(first_addr, second_addr);
        }

        inline int getDistanceBetweenSectors_GP_P(SECTOR_ADDR_T first_addr, SECTOR_ADDR_T second_addr)
        {
            using namespace secGP;
            if (first_addr.section[0] == 'P')
                swap(first_addr, second_addr);

            // loop through all the exists of GP, count all distances and to them and for each of them count distance to
            // the final address in P sector
            vector<GRAPH_POINT_T> queue = {secP::P_north_exit, secP::P_middle_exit, secP::P_south_exit};
            int current_best = INT32_MAX;
            for (auto exit : GP_exits)
            {
                int start_to_exit = getDistanceInSectorGP(first_addr, exit);
                int tmp_best = INT32_MAX;
                for (auto entrance : queue)
                {
                    int entrance_to_final = pythagoras(exit, entrance) + euclidean_distance(entrance, second_addr);
                    if (entrance_to_final < tmp_best)
                        tmp_best = entrance_to_final;
                }
                if (start_to_exit + tmp_best < current_best)
                    current_best = start_to_exit + tmp_best;
            }

            return current_best;
        }
    }
}

#endif

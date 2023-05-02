#ifndef _SOLVER_SETUP_H
#define _SOLVER_SETUP_H

#include "general_declarations.h"

#include <vector>


using namespace std;

class Box;
class Cart;
class CartShelf;

enum BPAlgorithms
{
    FFD_1D_ORDER_ITEMS_NO_SPLIT,
    FFD_1D_ORDER_ITEMS_SPLIT_ONE_BOX_TYPE,
    FFDS_1D_ORDER_ITEMS_SPLIT_MULTI_BOX_TYPE,
    PYLIB_3D_ORDER_ITEMS_SPLIT_ONE_BOX_TYPE,
    PYLIB_3D_FFDSEnhance_ORDER_ITEMS_SPLIT_MULTI_BOX_TYPE,
    PYLIB_3D_ORDER_ITEMS_SPLIT_MULTI_BOX_TYPE_COUNT_DEFINED
};

enum GroupingCustomersAlgorithms
{
    AVG_DISTANCES,
    LEAST_SQUARE_APPROXIMATION,
    K_MEANS_CLUSTERING,
    AUTO
};

enum ShortestPathAlgorithms
{
    NEAREST_NEIGHBOUR,
    NEAREST_NEIGHBOUR_BRUTE_FORCE_OPTIMIZATION,
    GREEDY,
    GREEDY_BRUTE_FORCE_OPTIMIZATION,
    JUST_MEASURE_DISTANCE,
    NONE
};

/// @brief object representing the setup for problem solving
class SolverConfiguration
{
public:
    /// @brief constructor, when no params set the default are used
    /// @param _bp_alg chosen algorithm for bin packing
    /// @param _grouping_customers_alg chosen algorithm for grouping customers
    /// @param _shortest_path_alg chosen algorithm for sorting the items in cart to shortest path
    SolverConfiguration(
        BPAlgorithms _bp_alg = BPAlgorithms::FFD_1D_ORDER_ITEMS_NO_SPLIT,
        GroupingCustomersAlgorithms _grouping_customers_alg = GroupingCustomersAlgorithms::AVG_DISTANCES,
        ShortestPathAlgorithms _shortest_path_alg = ShortestPathAlgorithms::NEAREST_NEIGHBOUR);

    // when selected K-means clustering, this is maximal number of iterations
    int Number_of_K_Means_Iterations = 10;

    BPAlgorithms getBPAlgorithm();
    GroupingCustomersAlgorithms getGroupingCustomerAlgorithm();
    ShortestPathAlgorithms getShortestPathAlgorithm();

private:
    BPAlgorithms bp_algorithm;
    GroupingCustomersAlgorithms grouping_customers_algorithm;
    ShortestPathAlgorithms shortest_path_algorithm;
};

/// @brief the configuration of the boxes, which will be used
class BoxConfiguration
{
private:
    /// @brief vector of pairs consisting of box_type and count of it
    vector<pair<Box, int>> box_types_count_vect;
    vector<Box> box_types_vect;

public:
    /// @brief add a box and its count
    /// @param b box instance
    /// @param count number representing the occurences of this box type
    /// in a warehouse, set to -1 when count its infinity
    void addBox(Box b, long count = -1);

    vector<pair<Box, int>> getBoxesWCountVector();

    vector<Box> getBoxesVector();
    /// @brief get the first box in the box vect
    /// @return first box in box vector or empty box instance if there is no box
    Box getFirstBox();
};

class CartConfiguration
{
private:
    /// @brief the cart pattern - include only
    vector<Cart> cart_pattern;

    /// @brief  vector of shelves in the cart
    vector<CartShelf> cart_shelf_vect;

    float cart_width = 0;
    float cart_height = 0;
    float cart_depth = 0;

    // TODO not used...
    float usable_capacity = 0;

    int number_of_shelves = 0;

public:
    /// @brief constructor for a cart pattern, this pattern will be used while creating new carts,
    /// paramteres like depth and width will be inhereted by cart shelves \n
    /// @warning be sure that it will be compatible with the box configuration, because there is slight simplification \n
    /// when called, there will be automaticcaly constructed cart with shelves according to the number, each of height in particular proportion
    /// @param _cart_width the usable width of the cart (the number must exclude all frames!)
    /// @param _cart_height the usable height of the cart (the number must exclude all frames!)
    /// @param _cart_depth the usable depth of the cart (the number must exclude all frames!)
    /// @param _usable_capacity the usable capacity of the whole computed capacity (volume) of the cart,
    /// will be inhereted by the shelves
    CartConfiguration(float _cart_width, float _cart_height, float _cart_depth, float _usable_capacity, int _number_of_shelves);

    /// @brief get the created cart pattern
    /// @return created cart pattern to be used while creating carts used in algorithm
    Cart getCartPattern();

    /// @brief removed all shelves from cart
    /// @warning when no else shelf created, the algorithm won't work
    void removeCartShelves();

    /// @brief add shelf of given parameters
    /// @warning the parameters can overflow the cart paramterers and it won't be noticed!!!!
    void addCartShelf(float _shelf_width, float _shelf_height, float _shelf_depth, float _usable_capacity);
};

#endif

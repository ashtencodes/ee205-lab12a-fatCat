///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Weight.h"

int main() {
    Weight weight =  Weight(6.0);
    weight.dump();
    Weight weight2 = Weight(12, Weight::SLUG, 12);
    weight2.dump();
    std::cout << weight2.getWeight(Weight::POUND) << std::endl;
    Weight weight3 = Weight(3, 6);
    weight3.dump();
    return 0;
}
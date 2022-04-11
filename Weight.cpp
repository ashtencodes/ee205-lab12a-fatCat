///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.cpp
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Weight.h"

const float Weight::KILOS_IN_A_POUND = 0.453592 ;

Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax = false;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) {
    bIsKnown = false;
    bHasMax = false;
    weight = newWeight;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    weight = newWeight;
    maxWeight = newMaxWeight;
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = false;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = newMaxWeight;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    maxWeight = newMaxWeight;
}

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
#include <cassert>
#include <iostream>

const float Weight::UNKNOWN_WEIGHT = -1 ;
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;

const std::string Weight::POUND_LABEL = "Pound";
const std::string Weight::KILO_LABEL = "Kilo";
const std::string Weight::SLUG_LABEL = "Slug";

Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    weight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight) {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
    weight = newWeight;
    assert( validate() );
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
    weight = UNKNOWN_WEIGHT;
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = true;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    maxWeight = UNKNOWN_WEIGHT;
    weight = newWeight;
    assert( validate() );
}

Weight::Weight(float newWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = POUND;
    maxWeight = newMaxWeight;
    weight = newWeight;
    assert( validate() );
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = false;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = UNKNOWN_WEIGHT;
    maxWeight = newMaxWeight;
    assert( validate() );
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = true;
    bHasMax = true;
    unitOfWeight = newUnitOfWeight;
    weight = newWeight;
    maxWeight = newMaxWeight;
    assert( validate() );
}

bool Weight::isWeightKnown() const noexcept {
    return bIsKnown;
}

bool Weight::hasMaxWeight() const noexcept {
    return bHasMax;
}

float Weight::getWeight() const noexcept {
    assert( isWeightValid( weight ) );
    return weight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    assert( isWeightValid( weight ) );
    float currentWeight = convertWeight(weight, unitOfWeight, weightUnits);
    return currentWeight;
}

float Weight::getMaxWeight() const noexcept {
    assert( isWeightValid( maxWeight ));
    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(float newWeight) {
    assert( isWeightValid( newWeight ) );
    weight = newWeight;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    assert( isWeightValid( newWeight ) );
    weight = newWeight;
    unitOfWeight = weightUnits;
}

void Weight::setMaxWeight(float newMaxWeight) {
    assert( isWeightValid( newMaxWeight ));
    maxWeight = newMaxWeight;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
    assert( (checkWeight > 0) || checkWeight == UNKNOWN_WEIGHT );
    if( bHasMax ){
        assert( checkWeight <= maxWeight );
    }
    return true;
}

bool Weight::validate() const noexcept {
    assert( isWeightValid( weight ) );
    assert( isWeightValid ( maxWeight ) );
    return true;
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    float pound = kilogram / KILOS_IN_A_POUND;
    return pound;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    float kilogram = pound * KILOS_IN_A_POUND;
    return kilogram;
}

float Weight::fromSlugToPound(float slug) noexcept {
    float pound = slug / SLUGS_IN_A_POUND;
    return pound;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    float slug = pound * SLUGS_IN_A_POUND;
    return slug;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    switch( fromUnit ){
        case POUND:
            switch( toUnit ){
                case POUND:
                    return fromWeight;
                case KILO:
                    return fromPoundToKilogram( fromWeight );
                case SLUG:
                    return fromPoundToSlug( fromWeight );
            }
        case KILO:
            switch( toUnit ){
                case POUND:
                    return fromKilogramToPound( fromWeight );
                case KILO:
                    return fromWeight;
                case SLUG:
                    float pound = fromKilogramToPound( fromWeight );
                    return fromPoundToSlug( pound );
            }
        case SLUG:
            switch( toUnit ){
                case SLUG:
                    return fromWeight;
                case POUND:
                    return fromSlugToPound( fromWeight );
                case KILO:
                    float pound = fromSlugToPound( fromWeight );
                    return fromPoundToKilogram( pound );
            }
    }
    return 0;
}

std::ostream& operator<<( std::ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
    }
    return lhs_stream << Weight::POUND_LABEL ;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    float leftWeight = convertWeight( weight, unitOfWeight, POUND );
    float rightWeight = convertWeight( rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND );
    if( leftWeight == rightWeight ){
        return true;
    }
    else {
        return false;
    }
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float leftWeight = convertWeight( weight, unitOfWeight, POUND );
    float rightWeight = convertWeight( rhs_Weight.weight, rhs_Weight.unitOfWeight, POUND );
    if( leftWeight < rightWeight ){
        return true;
    }
    else {
        return false;
    }
}

Weight &Weight::operator+=(float rhs_addToWeight) {
    weight += rhs_addToWeight;
    return *this;
}

void Weight::dump() const noexcept {
    std::cout << "======================================================" << std::endl;
    std::cout << "bIsKnown: " << bIsKnown << std::endl;
    std::cout << "bHasMax: " << bHasMax << std::endl;
    std::cout << "Unit of Weight: " << unitOfWeight << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Max Weight: " << maxWeight << std::endl;
}
///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.h
/// @version 1.0
///
/// @author @Ashten Akemoto <aakemoto@hawaii.edu>
/// @date   11_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

class Weight {
public: ////////////// Enumerations and Const /////////////
    enum UnitOfWeight { POUND, KILO, SLUG };

    static const float UNKNOWN_WEIGHT;
    static const float KILOS_IN_A_POUND;
    static const float SLUGS_IN_A_POUND;

    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    bool bIsKnown;
    bool bHasMax;

    enum UnitOfWeight unitOfWeight;

    float weight;
    float maxWeight;

public: ////////////// Constructors //////////////
    Weight() noexcept;
    Weight( float newWeight );
    Weight( UnitOfWeight newUnitOfWeight ) noexcept;
    Weight( float newWeight, UnitOfWeight newUnitOfWeight ) noexcept;
    Weight( float newWeight, float newMaxWeight );
    Weight( UnitOfWeight newUnitOfWeight, float newMaxWeight );
    Weight( float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight );

public: ////////////// Getters and Setters //////////////
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    float getWeight() const noexcept;
    float getWeight(UnitOfWeight weightUnits) const noexcept;
    float getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    void setWeight(float newWeight);
    void setWeight(float newWeight, UnitOfWeight weightUnits);
    void setMaxWeight(float newMaxWeight);

    bool isWeightValid(float checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;

public:
    bool operator==(const Weight &rhs_Weight) const;
    bool operator<(const Weight &rhs_Weight) const;
    Weight & operator+=(float rhs_addToWeight);
    static float fromKilogramToPound(float kilogram) noexcept;
    static float fromPoundToKilogram(float pound) noexcept;
    static float fromSlugToPound(float slug) noexcept;
    static float fromPoundToSlug(float pound) noexcept;
    static float convertWeight(float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;
};





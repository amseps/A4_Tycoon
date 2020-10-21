//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_APARTMENTBUILDING_H
#define A4_TYCOON_APARTMENTBUILDING_H

#include "Property.h"
#include "Tennant.h"

class ApartmentBuilding : public Property{
public:
    int rooms;
    bool hasTennant[10];
    Tennant tennantList[10];

    ApartmentBuilding();
    ApartmentBuilding(const ApartmentBuilding & in);
    ~ApartmentBuilding();
    ApartmentBuilding & operator=(const ApartmentBuilding & in);
};


#endif //A4_TYCOON_APARTMENTBUILDING_H

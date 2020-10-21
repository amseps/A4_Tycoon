//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_BUSINESSBUILDING_H
#define A4_TYCOON_BUSINESSBUILDING_H

#include "Property.h"
#include "Tennant.h"

class BusinessBuilding : public Property{
public:
    enum size{LARGE, MEDIUM, SMALL};
    int rooms;
    size roomSizes[5];
    bool hasTennant[5];
    Tennant tennantList[5];

    BusinessBuilding();
    BusinessBuilding(const BusinessBuilding & in);
    ~BusinessBuilding();
    BusinessBuilding & operator=(const BusinessBuilding & right);
};


#endif //A4_TYCOON_BUSINESSBUILDING_H

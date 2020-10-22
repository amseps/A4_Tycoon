//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_BUSINESSBUILDING_H
#define A4_TYCOON_BUSINESSBUILDING_H

#include "Property.h"
#include "Tennant.h"

class BusinessBuilding : public Property{
public:
    enum size{LARGE, MEDIUM, SMALL} ;
    int rooms;
    size roomSizes[5];
    int roomRent[5];
    bool hasTennant[5];
    Tennant tennantList[5];

    void adjustRentTo(const int & in, const int & space);

    BusinessBuilding();
    BusinessBuilding(const BusinessBuilding & in);
    ~BusinessBuilding();
    std::ostream & operator<<(std::ostream & _stream);
    BusinessBuilding & operator=(const BusinessBuilding & in);
};


#endif //A4_TYCOON_BUSINESSBUILDING_H

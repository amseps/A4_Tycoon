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
    Tennant * tennantList[10];

    ApartmentBuilding();
    ApartmentBuilding(const ApartmentBuilding & in);
    ~ApartmentBuilding();
    virtual operator std::string() const;
    virtual ApartmentBuilding & operator=(const ApartmentBuilding & in);
    std::ostream & operator<<(std::ostream & _stream);
    std::string ts();

    void adjustRentTo(const int & in, const int & space);

};


#endif //A4_TYCOON_APARTMENTBUILDING_H

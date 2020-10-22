//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_RESIDENTIALBUILDING_H
#define A4_TYCOON_RESIDENTIALBUILDING_H

#include "Property.h"
#include "Tennant.h"

class ResidentialBuilding : public Property{
public:
    bool hasTennant;
    Tennant * myTennant;

    ResidentialBuilding();
    ResidentialBuilding(const ResidentialBuilding & in);
    ~ResidentialBuilding();
    virtual operator std::string() const;
    ResidentialBuilding & operator=(const ResidentialBuilding & in);
    virtual std::ostream & operator<<(std::ostream & _stream);
    std::string ts();

    void adjustRentTo(const int & in, const int & space);
};


#endif //A4_TYCOON_RESIDENTIALBUILDING_H

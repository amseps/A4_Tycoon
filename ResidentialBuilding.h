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
    Tennant myTennant;

    ResidentialBuilding();
    ResidentialBuilding(const ResidentialBuilding & in);
    ~ResidentialBuilding();
    ResidentialBuilding & operator=(const ResidentialBuilding & in);

};


#endif //A4_TYCOON_RESIDENTIALBUILDING_H

//
// Created by AM on 10/20/2020.
//

#include "ApartmentBuilding.h"
#include "ResidentialTennant.h"

ApartmentBuilding::ApartmentBuilding() {
    srand (time(NULL));
    switch (rand() % 4){ // is there a better way to do this?
        case 0: loc = NE; break;
        case 1: loc = SE; break;
        case 2: loc = SW; break;
        case 3: loc = NW; break;
    }
    propertyValue = rand() % 300000 + 300000;
    propertyValueWithEvent = propertyValue;
    mortgageTotal = propertyValue;
    mortgageDuration = propertyValue % (rand() % 180 + 180);
    mortgageMonthly = mortgageTotal / mortgageDuration;
    int rooms = rand() % 10 + 1;
    for(int i = 0 ; i < rooms; i++){
        hasTennant[i] = true;
        tennantList[i] = * new ResidentialTennant();
    }
    rent = 0;
}

ApartmentBuilding::ApartmentBuilding(const ApartmentBuilding &in) {

}

ApartmentBuilding::~ApartmentBuilding() {

}


ApartmentBuilding &ApartmentBuilding::operator=(const ApartmentBuilding &in) {
    if(this == &in){
        return *this;
    }
    ApartmentBuilding * newApartmentBuilding = new ApartmentBuilding(in);
    return * newApartmentBuilding;
}


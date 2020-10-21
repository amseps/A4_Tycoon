//
// Created by AM on 10/20/2020.
//

#include "BusinessBuilding.h"
#include "BusinessTennant.h"

BusinessBuilding::BusinessBuilding() {
    srand (time(NULL));
    switch (rand() % 4){ // is there a better way to do this?
        case 0: loc = NE; break;
        case 1: loc = SE; break;
        case 2: loc = SW; break;
        case 3: loc = NW; break;
    }
    propertyValue = rand() % 200000 + 400000;
    mortgageTotal = propertyValue;
    mortgageDuration = propertyValue % (rand() % 180 + 180);
    mortgageMonthly = mortgageTotal / mortgageDuration;
    int rooms = rand() % 5 + 1;
    for(int i = 0 ; i < rooms; i++){
        switch(rand() % 3){
            case 0: roomSizes[i] == LARGE;
            case 1: roomSizes[i] == MEDIUM;
            case 2: roomSizes[i] == SMALL;
        }
        hasTennant[i] = true;
        tennantList[i] = * new BusinessTennant();
    }
}

BusinessBuilding::BusinessBuilding(const BusinessBuilding &in) {

}

BusinessBuilding::~BusinessBuilding() {

}

BusinessBuilding &BusinessBuilding::operator=(const BusinessBuilding & in) {
    if(this == &in){
        return *this;
    }
    BusinessBuilding * newBusinessBuilding = new BusinessBuilding(in);
    return *newBusinessBuilding;
}

//
// Created by AM on 10/20/2020.
//

#include <iostream>
#include "ResidentialBuilding.h"
#include "ResidentialTennant.h"

ResidentialBuilding::ResidentialBuilding() {
    srand (time(NULL));
    switch (rand() % 4){ // is there a better way to do this?
        case 0: loc = NE; break;
        case 1: loc = SE; break;
        case 2: loc = SW; break;
        case 3: loc = NW; break;
    }
    propertyValue = rand() % 500000 + 100000;
    propertyValueWithEvent = propertyValue;
    mortgageTotal = propertyValue;
    mortgageDuration = propertyValue % (rand() % 180 + 180);
    mortgageMonthly = mortgageTotal / mortgageDuration;

    hasTennant = true;
    myTennant = * new ResidentialTennant();

    rent = 0;
}

ResidentialBuilding::ResidentialBuilding(const ResidentialBuilding &in) {

}

ResidentialBuilding::~ResidentialBuilding() {
    if(&myTennant != nullptr) {
        Tennant * c = &myTennant;
        delete c;
        c = nullptr;
    }
}


ResidentialBuilding &ResidentialBuilding::operator=(const ResidentialBuilding &in) {
    if(this == &in){
        return *this;
    }
    ResidentialBuilding * newResidentialBuilding = new ResidentialBuilding(in);
    return *newResidentialBuilding;
}

void ResidentialBuilding::adjustRentTo(const int & in, const int & space = 0){
    rent = in;
    if(hasTennant){
        if(myTennant.monthlyBudget < rent){
            if(myTennant.agreeability < 2) {
                std::cout << "\n▲The tenant here is refusing to pay rent!";
                myTennant.willingToPay = false;
            }else{
                std::cout << "\n▲The tenant here has vacated the property!";
                hasTennant = false;
                myTennant.willingToPay = false;
            }
        }else{ // if now able to pay
            std::cout << "\n▲The tenant here is willing to pay again!";
            myTennant.willingToPay = true;
        }
    }
}
//
// Created by AM on 10/20/2020.
//

#include <iostream>
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
    propertyValueWithEvent = propertyValue;
    mortgageTotal = propertyValue;
    mortgageDuration = propertyValue % (rand() % 180 + 180);
    mortgageMonthly = mortgageTotal / mortgageDuration;
    int rooms = rand() % 5 + 1;
    for(int i = 0 ; i < rooms; i++){
        roomRent[i] = 0;
        switch(rand() % 3){
            case 0: roomSizes[i] == LARGE;
            case 1: roomSizes[i] == MEDIUM;
            case 2: roomSizes[i] == SMALL;
        }
        hasTennant[i] = true;
        tennantList[i] = * new BusinessTennant();
    }

    rent = 0;
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

void BusinessBuilding::adjustRentTo(const int &in, const int &space) {
    roomRent[space] = in;
    if(hasTennant[space]) {
        if (tennantList[space].monthlyBudget < in) {
            if (tennantList[space].agreeability < 2) {
                std::cout << "\n▲Tenant in space " << space << " is refusing to pay rent!\n";
                tennantList[space].willingToPay = false;
            } else {
                std::cout << "\n▲Tenant in space " << space << " has left the property!\n";
                tennantList[space].willingToPay = false;
                hasTennant[space] = false;
            }
        }else{ // if there is a tennant but is refusing to pay, and rent is now less than budget
            std::cout << "\n▲Tenant in space " << space << " is beginning to pay rent again\n";
            tennantList[space].willingToPay = true;
        }
    }
}







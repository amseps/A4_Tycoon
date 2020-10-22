//
// Created by AM on 10/20/2020.
//

#include <iostream>
#include "BusinessBuilding.h"
#include "BusinessTennant.h"

BusinessBuilding::BusinessBuilding() {
    switch (rand() % 4){ // is there a better way to do this?
        case 0: loc = NE; break;
        case 1: loc = SE; break;
        case 2: loc = SW; break;
        case 3: loc = NW; break;
    }
    propertyValue = rand() % 200000 + 400000;
    propertyValueWithEvent = propertyValue;
    mortgageTotal = propertyValue;
    mortgageDuration =  (rand() % 180 + 180);
    mortgageMonthly = mortgageTotal / mortgageDuration;
    for(int i = 0 ; i < 5; i++){
        roomRent[i] = 500;
        switch(rand() % 3){
            case 0: roomSizes[i] == LARGE;
            case 1: roomSizes[i] == MEDIUM;
            case 2: roomSizes[i] == SMALL;
        }
        hasTennant[i] = true;
        tennantList[i] = new BusinessTennant();
    }

    rent = 500;
}

BusinessBuilding::BusinessBuilding(const BusinessBuilding &in) {

}

BusinessBuilding::~BusinessBuilding() {
    for(int i = 0 ; i < 5; i++){
        if(&tennantList[i] != nullptr){
            Tennant * c = tennantList[i];
            delete c;
        }
    }
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
        if (tennantList[space]->monthlyBudget < in) {
            if (tennantList[space]->agreeability < 2) {
                std::cout << "\n▲Tenant in space " << space << " is refusing to pay rent!\n";
                tennantList[space]->willingToPay = false;
            } else {
                std::cout << "\n▲Tenant in space " << space << " has left the property!\n";
                tennantList[space]->willingToPay = false;
                hasTennant[space] = false;
            }
        }else{ // if there is a tennant but is refusing to pay, and rent is now less than budget
            std::cout << "\n▲Tenant in space " << space << " is beginning to pay rent again\n";
            tennantList[space]->willingToPay = true;
        }
    }
}

std::ostream &BusinessBuilding::operator<<(std::ostream &_stream) {
    _stream << "[BUS: " <<  dictateLocation() << ", mortgage: $" << mortgageMonthly << " for " << mortgageDuration << " months. Rent: " << rent << "]";
    return _stream;
}

BusinessBuilding::operator std::string() const {
    return "[BUS: " +  dictateLocation() + ":<" + std::to_string(propertyValueWithEvent)+"/"+std::to_string(propertyValue)+"> mortgage: $" + std::to_string(mortgageMonthly) + " for " + std::to_string(mortgageDuration) + " months. Rent: " + std::to_string(rent) + "]";
}

std::string BusinessBuilding::ts() {
    return "[BUS: " +  dictateLocation() + ":<" + std::to_string(propertyValueWithEvent)+"/"+std::to_string(propertyValue)+"> mortgage: $" + std::to_string(mortgageMonthly) + " for " + std::to_string(mortgageDuration) + " months. Rent: " + std::to_string(rent) + "]";
}







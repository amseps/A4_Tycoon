//
// Created by AM on 10/20/2020.
//

#include <iostream>
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
    for(int i = 0 ; i < 10; i++){
        if(&tennantList[i] != nullptr){
            Tennant * c = &tennantList[i];
            delete c;
            c = nullptr;
        }
    }
}


ApartmentBuilding &ApartmentBuilding::operator=(const ApartmentBuilding &in) {
    if(this == &in){
        return *this;
    }
    ApartmentBuilding * newApartmentBuilding = new ApartmentBuilding(in);
    return * newApartmentBuilding;
}

void ApartmentBuilding::adjustRentTo(const int &in, const int &space) {
    rent = in;
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
        }else{ // if there is a tenant but is refusing to pay, and rent is now less than budget
            std::cout << "\n▲Tenant in space " << space << " is beginning to pay rent again\n";
            tennantList[space].willingToPay = true;
        }
    }
}

std::ostream &ApartmentBuilding::operator<<(std::ostream &_stream) {
    _stream << "[APT" << dictateLocation() << ", mortgage: $" << mortgageMonthly << " for " << mortgageDuration << " months. Rent: " << rent;
    return _stream;
}

//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_TYCOON_H
#define A4_TYCOON_TYCOON_H

#include "Property.h"
#include "ResidentialBuilding.h"
#include "BusinessBuilding.h"
#include "ApartmentBuilding.h"

#include "Tennant.h"
#include "ResidentialTennant.h" // residential and apartment
#include "BusinessTennant.h"

class Tycoon {
private:

    int money;
    int turn;

    ResidentialBuilding residientialPropertyList[3];
    int sizeResidentialPropertyList; // set to 3

    BusinessBuilding businessPropertyList[3];
    int sizebusinessPropertyList;

    ApartmentBuilding apartmentPropertyList[3];
    int sizeapartmentPropertyList;

    ResidentialBuilding myResidentialProperties[20];
    int sizeMyResidentialProperties;

    BusinessBuilding myBusinessBuildingProperties[20];
    int sizeMyBusinessBuildingProperties;

    ApartmentBuilding myApartmentBuildingProperties[20];
    int sizeMyApartmentBuildingProperties;

    void generateNewPropertyList();
    void buyThisProperty(const Property & in);
    void sellThisProperty(const Property & in);
    Property selectARandomProperty();

    void optionBuyProperty();
    void optionSellProperty();
    void optionAdjustRent();

    void adjustRent(const Property & in, int newRent);

    void collectRents();

    void printGameInfo();

    void randomEvent();
    void event_hurricane();
    void event_tornado();
    void event_earthquake();
    void event_wildfire();
    void event_stockCrash();
    void event_gentrification();
    void event_setMonthValue(const double & percentToBe, const Property::location & loc);
    void event_setMonthValue(const double & percentToBe);


    void runTurn();

public:
    void runGame();

    Tycoon();
    Tycoon(const Tycoon & in);
    ~Tycoon();
    Tycoon & operator=(const Tycoon & in);
};


#endif //A4_TYCOON_TYCOON_H

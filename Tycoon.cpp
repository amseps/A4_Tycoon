//
// Created by AM on 10/20/2020.
//

#include <iostream>
#include "Tycoon.h"

using namespace std;

Tycoon::Tycoon() {
    money = 500000;
    turn = 0;
    sumPropertyValue = 0;
    sizeapartmentPropertyList = 3;
    sizebusinessPropertyList = 3;
    sizebusinessPropertyList = 3;
    sizeMyApartmentBuildingProperties = 0;
    sizeMyBusinessBuildingProperties = 0;
    sizeMyResidentialProperties = 0;
    generateNewPropertyList();
}

Tycoon::Tycoon(const Tycoon &in) {
    //TODO
}

Tycoon::~Tycoon() {
    //TODO
}

Tycoon &Tycoon::operator=(const Tycoon & in) {
    if(this == &in){
        return *this;
    }
    Tycoon newTycoon = * new Tycoon(in);
    return newTycoon;
}


void Tycoon::runGame() {
    cout << "[WELCOME to AM's EPIC Property Tycoon!]\n\t->You have a small loan of $500,000 and a dream...\n\t->Let's win big!\n";
    while(money < 1000000 && money > 0){
        turn_run();
    }
    if(money < 0){
        cout << "\n\n[Uh oh... You ran outta cash! Watch out for those loan sharks...\n\t->Turns Taken: " << turn << endl;
    }else {
        cout << "\n\n[Congratulations! You've become a millionaire!]\n\t->Turns Taken: " << turn << endl;
    }
    cout << "\n\t\t -GAME OVER-\n\n";
}

void Tycoon::generateNewPropertyList() {
    //better hope that propertyList.size = 9 :v
    for(int i = 0 ; i < 3; i++){
        if(&residientialPropertyList[i] != nullptr) delete & residientialPropertyList[i];
        ResidentialBuilding *thisProp = new ResidentialBuilding();
        residientialPropertyList[i] = *thisProp;

    }
    for(int i = 0 ; i < 3; i++){
        if(&apartmentPropertyList[i] != nullptr) delete & apartmentPropertyList[i];
        ApartmentBuilding *thisProp = new ApartmentBuilding();
        apartmentPropertyList[i] = *thisProp;

    }
    for(int i = 0 ; i < 3; i++){
        if(&businessPropertyList[i] != nullptr) delete & businessPropertyList[i];
        BusinessBuilding *thisProp = new BusinessBuilding();
        businessPropertyList[i] = *thisProp;
    }
}

Property Tycoon::selectARandomProperty() {
    if(sizeResidentialPropertyList + sizebusinessPropertyList + sizeapartmentPropertyList < 3){
        generateNewPropertyList();
    }
    while(true) { //yikes
        int pick = rand() % 9;
        if (pick < 3 && pick < sizeResidentialPropertyList) {
            return residientialPropertyList[pick];
        } else if (pick < 6 && (pick-3) < sizebusinessPropertyList) {
            return businessPropertyList[pick-3];
        } else if(pick < 9 && (pick-6) < sizeapartmentPropertyList){
            return apartmentPropertyList[pick-6];
        }
    }
}

void Tycoon::randomEvent() {
    switch(rand() % 6) {
        case 0: event_hurricane(); break;
        case 1: event_tornado(); break;
        case 2: event_earthquake(); break;
        case 3: event_wildfire(); break;
        case 4: event_stockCrash(); break;
        case 5: event_gentrification(); break;
    }
}

void Tycoon::event_hurricane() {
    cout << "\n\t▐ A Hurricane strikes the SE! Properties there lose 50% value ▐\n";
    event_setMonthValue(.5, Property::SE);
}

void Tycoon::event_tornado() {
    cout << "\n\t▐ A Tornado strikes the NE! Properties there lose 30% value ▐\n";
    event_setMonthValue(.7, Property::NE);
}

void Tycoon::event_earthquake() {
    cout << "\n\t▐ An Earthquake strikes the NW! Properties there lose 10% value ▐\n";
    event_setMonthValue(.9, Property::NW);
}

void Tycoon::event_wildfire() {
    cout << "\n\t▐ A Wildfire strikes the SW! Properties there lose 25% value ▐\n";
    event_setMonthValue(.75, Property::SW);
}

void Tycoon::event_stockCrash() {
    cout << "\n\t▐ The Bogdanovs crash the stock market! All properties lose 30% value ▐\n";
    event_setMonthValue(.7);
}

void Tycoon::event_gentrification() {
    int location = rand() % 4;
    Property::location thisLoc = (Property::location)location;
    cout << "\n\t▐ There is gentrification in the " << dictateLocationEnum(thisLoc) << ", property values there increased by 20% ▐\n";
    event_setMonthValue(1.2, thisLoc);
}

void Tycoon::event_setMonthValue(const double &percentToBe, const Property::location &loc) {
    for(int i = 0 ; i < sizeResidentialPropertyList; i++){
        if(residientialPropertyList[i].loc == loc) residientialPropertyList[i].propertyValueWithEvent = percentToBe * residientialPropertyList->propertyValue;
    }
    for(int i = 0 ; i < sizeapartmentPropertyList; i++){
        if(apartmentPropertyList[i].loc == loc) apartmentPropertyList[i].propertyValueWithEvent = percentToBe * apartmentPropertyList->propertyValue;
    }
    for(int i = 0 ; i < sizebusinessPropertyList; i++){
        if(businessPropertyList[i].loc == loc) businessPropertyList[i].propertyValueWithEvent = percentToBe * businessPropertyList->propertyValue;
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        if(myResidentialProperties[i].loc == loc) myResidentialProperties[i].propertyValueWithEvent = percentToBe * myResidentialProperties->propertyValue;
    }
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        if(myBusinessBuildingProperties[i].loc == loc) myBusinessBuildingProperties[i].propertyValueWithEvent = percentToBe * myBusinessBuildingProperties->propertyValue;
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        if(myApartmentBuildingProperties[i].loc == loc) myApartmentBuildingProperties[i].propertyValueWithEvent = percentToBe * myApartmentBuildingProperties->propertyValue;
    }
}

void Tycoon::event_setMonthValue(const double &percentToBe) {
    for(int i = 0 ; i < sizeResidentialPropertyList; i++){
        residientialPropertyList[i].propertyValueWithEvent = percentToBe * residientialPropertyList->propertyValue;
    }
    for(int i = 0 ; i < sizeapartmentPropertyList; i++){
        apartmentPropertyList[i].propertyValueWithEvent = percentToBe * apartmentPropertyList->propertyValue;
    }
    for(int i = 0 ; i < sizebusinessPropertyList; i++){
        businessPropertyList[i].propertyValueWithEvent = percentToBe * businessPropertyList->propertyValue;
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        myResidentialProperties[i].propertyValueWithEvent = percentToBe * myResidentialProperties->propertyValue;
    }
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        myBusinessBuildingProperties[i].propertyValueWithEvent = percentToBe * myBusinessBuildingProperties->propertyValue;
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        myApartmentBuildingProperties[i].propertyValueWithEvent = percentToBe * myApartmentBuildingProperties->propertyValue;
    }
}

std::string Tycoon::dictateLocationEnum(const Property::location &in) {
    switch(in){
        case Property::NE:
            return "NE";
        case Property::SE:
            return "SE";
        case Property::SW:
            return "SW";
        case Property::NW:
            return "NW";
    }
}

void Tycoon::printGameInfo() {
    cout << "♦[$" << money << "]\tcurrent bank balance\n♦[$"<<sumPropertyValue<<"]\ttotal property values\n♦["
    <<sizeMyResidentialProperties<<"/20]\tresidences owned\n♦[" << sizeMyApartmentBuildingProperties << "/20\tapartments owned\n♦["
    <<sizeMyBusinessBuildingProperties<<"/20]\tbusinesses owned\n\n";
}

void Tycoon::collectRents() {
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        for(int g = 0 ; g < 5; i++){ // five is the number of tennants in businesses
            if(myBusinessBuildingProperties[i].hasTennant[g] && myBusinessBuildingProperties[i].tennantList[g].willingToPay){
                money += myBusinessBuildingProperties[i].rent;
            }
        }
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        if(myResidentialProperties[i].hasTennant && myResidentialProperties[i].myTennant.willingToPay){
            money += myResidentialProperties[i].rent;
        }
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        for(int g = 0 ; g < 10; i++){ // five is the number of tennants in residences
            if(myApartmentBuildingProperties[i].hasTennant[g] && myApartmentBuildingProperties[i].tennantList[g].willingToPay){
                money += myApartmentBuildingProperties[i].rent;
            }
        }
    }
}

//https://stackoverflow.com/questions/307765/how-do-i-check-if-an-objects-type-is-a-particular-subclass-in-c
//next time I'mma do this wtf
void Tycoon::buyThisProperty(const ResidentialBuilding &in) {
    if(sizeMyResidentialProperties >= 20){
        cout << "Already have too many Residential Properties!\n";
    }else{
        if(money > in.propertyValue) {
            myResidentialProperties[sizeMyResidentialProperties++] = in;
            money -= in.propertyValueWithEvent;
            sumPropertyValue += in.propertyValue;
        }else{
            cout << "Sorry! You're too broke to buy this residence, some back when you're a little.... richer! \n";
        }
    }
}

void Tycoon::buyThisProperty(const BusinessBuilding &in) {
    if(sizeMyBusinessBuildingProperties >= 20){
        cout << "Already have too many Business Properties!\n";
    }else{
        if(money > in.propertyValue) {
            myBusinessBuildingProperties[sizeMyBusinessBuildingProperties++] = in;
            money -= in.propertyValueWithEvent;
            sumPropertyValue += in.propertyValue;
        }else{
            cout << "Sorry! You're too broke to buy this business, some back when you're a little.... richer! \n";
        }
    }
}

void Tycoon::buyThisProperty(const ApartmentBuilding &in) {
    if(sizeMyApartmentBuildingProperties >= 20){
        cout << "Already have too many Business Properties!\n";
    }else{
        if(money > in.propertyValue) {
            myApartmentBuildingProperties[sizeMyApartmentBuildingProperties++] = in;
            money -= in.propertyValueWithEvent;
            sumPropertyValue += in.propertyValue;
        }else{
            cout << "Sorry! You're too broke to buy this apartment, some back when you're a little.... richer! \n";
        }
    }
}

void Tycoon::sellResProperty(const int & index) {
    money += myResidentialProperties[index].propertyValueWithEvent;
    sumPropertyValue -= myResidentialProperties[index].propertyValue;
    swap(myResidentialProperties[index] , myResidentialProperties[sizeMyResidentialProperties-1]);
    delete  &myResidentialProperties[sizeMyResidentialProperties-1];
    sizeMyResidentialProperties--;
}

void Tycoon::sellBusProperty(const int &index) {
    money += myBusinessBuildingProperties[index].propertyValueWithEvent;
    sumPropertyValue -= myBusinessBuildingProperties[index].propertyValue;
    swap(myBusinessBuildingProperties[index] , myBusinessBuildingProperties[sizeMyBusinessBuildingProperties-1]);
    delete  &myBusinessBuildingProperties[sizeMyBusinessBuildingProperties-1];
    sizeMyBusinessBuildingProperties--;
}

void Tycoon::sellAptProperty(const int &index) {
    money += myApartmentBuildingProperties[index].propertyValueWithEvent;
    sumPropertyValue -= myApartmentBuildingProperties[index].propertyValue;
    swap(myApartmentBuildingProperties[index] , myApartmentBuildingProperties[sizeMyBusinessBuildingProperties-1]);
    delete  &myBusinessBuildingProperties[sizeMyBusinessBuildingProperties-1];
    sizeMyApartmentBuildingProperties--;
}


void Tycoon::turn_run() {

}

void Tycoon::collectMonthlyMortgage() {

}









































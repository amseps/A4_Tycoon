//
// Created by AM on 10/20/2020.
//

#include <iostream>
#include "Tycoon.h"

using namespace std;

int Property::propID = 0; // why? ? ? ? ? put this here ? ?? ? ?

Tycoon::Tycoon() {
    money = 500000;
    previous_money = money;
    turn = 1;
    sumMortgages = 0;
    sumPropertyValue = 0;
    sizeapartmentPropertyList = 3;
    sizebusinessPropertyList = 3;
    sizebusinessPropertyList = 3;
    sizeMyApartmentBuildingProperties = 0;
    sizeMyBusinessBuildingProperties = 0;
    sizeMyResidentialProperties = 0;
    init_generateNewPropertyList();

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
    Tycoon *newTycoon = new Tycoon(in);
    return *newTycoon;
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

void Tycoon::init_generateNewPropertyList() {
    for(int i = 0 ; i < 3; i++){
        ResidentialBuilding * r = new ResidentialBuilding();
        residientialPropertyList[i]  = r;
    }
    for(int i = 0 ; i < 3; i++){
        ApartmentBuilding * a = new ApartmentBuilding();
        apartmentPropertyList[i] = a;
    }
    for(int i = 0 ; i < 3; i++){
        BusinessBuilding * b = new BusinessBuilding();
        businessPropertyList[i] = b;
    }
    sizeResidentialPropertyList = 3;
    sizeapartmentPropertyList = 3;
    sizebusinessPropertyList = 3;
}

void Tycoon::generateNewPropertyList() {
    //better hope that propertyList.size = 9 :v
    for(int i = 0 ; i < 3; i++){
        if(&residientialPropertyList[i] != nullptr) {
            ResidentialBuilding * r = residientialPropertyList[i];
            //delete r; // whatever
        }
        residientialPropertyList[i]  = new  ResidentialBuilding();
    }
    for(int i = 0 ; i < 3; i++){
        if(&apartmentPropertyList[i] != nullptr){
            ApartmentBuilding * a = apartmentPropertyList[i];
            //delete a;
        }
        ApartmentBuilding * a = new ApartmentBuilding();
        apartmentPropertyList[i] = a;
    }
    for(int i = 0 ; i < 3; i++){
        if(&businessPropertyList[i] != nullptr){
            BusinessBuilding * b = businessPropertyList[i];
            //delete b;
        }
        businessPropertyList[i] = new BusinessBuilding();
    }
    sizeResidentialPropertyList = 3;
    sizeapartmentPropertyList = 3;
    sizebusinessPropertyList = 3;
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
    cout << "\n\t## A Hurricane strikes the SE! Properties there lose 50% value\n";
    event_setMonthValue(.5, Property::SE);
}

void Tycoon::event_tornado() {
    cout << "\n\t## A Tornado strikes the NE! Properties there lose 30% value\n";
    event_setMonthValue(.7, Property::NE);
}

void Tycoon::event_earthquake() {
    cout << "\n\t## An Earthquake strikes the NW! Properties there lose 10% value\n";
    event_setMonthValue(.9, Property::NW);
}

void Tycoon::event_wildfire() {
    cout << "\n\t##A Wildfire strikes the SW! Properties there lose 25% value\n";
    event_setMonthValue(.75, Property::SW);
}

void Tycoon::event_stockCrash() {
    cout << "\n\t## The Bogdanovs crash the stock market! All properties lose 30% value\n";
    event_setMonthValue(.7);
}

void Tycoon::event_gentrification() {
    int location = rand() % 4;
    Property::location thisLoc = (Property::location)location;
    cout << "\n\t## There is gentrification in the " << dictateLocationEnum(thisLoc) << ", property values there increased by 20%\n";
    event_setMonthValue(1.2, thisLoc);
}

void Tycoon::event_setMonthValue(const double &percentToBe, const Property::location &loc) {
    for(int i = 0 ; i < sizeResidentialPropertyList; i++){
        if(residientialPropertyList[i]->loc == loc) residientialPropertyList[i]->propertyValueWithEvent = percentToBe * residientialPropertyList[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeapartmentPropertyList; i++){
        if(apartmentPropertyList[i]->loc == loc) apartmentPropertyList[i]->propertyValueWithEvent = percentToBe * apartmentPropertyList[i]->propertyValue;
    }
    for(int i = 0 ; i < sizebusinessPropertyList; i++){
        if(businessPropertyList[i]->loc == loc) businessPropertyList[i]->propertyValueWithEvent = percentToBe * businessPropertyList[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        if(myResidentialProperties[i]->loc == loc) myResidentialProperties[i]->propertyValueWithEvent = percentToBe * myResidentialProperties[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        if(myBusinessBuildingProperties[i]->loc == loc) myBusinessBuildingProperties[i]->propertyValueWithEvent = percentToBe * myBusinessBuildingProperties[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        if(myApartmentBuildingProperties[i]->loc == loc) myApartmentBuildingProperties[i]->propertyValueWithEvent = percentToBe * myApartmentBuildingProperties[i]->propertyValue;
    }
}

void Tycoon::event_setMonthValue(const double &percentToBe) {
    for(int i = 0 ; i < sizeResidentialPropertyList; i++){
        residientialPropertyList[i]->propertyValueWithEvent = percentToBe * residientialPropertyList[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeapartmentPropertyList; i++){
        apartmentPropertyList[i]->propertyValueWithEvent = percentToBe * apartmentPropertyList[i]->propertyValue;
    }
    for(int i = 0 ; i < sizebusinessPropertyList; i++){
        businessPropertyList[i]->propertyValueWithEvent = percentToBe * businessPropertyList[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        myResidentialProperties[i]->propertyValueWithEvent = percentToBe * myResidentialProperties[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        myBusinessBuildingProperties[i]->propertyValueWithEvent = percentToBe * myBusinessBuildingProperties[i]->propertyValue;
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        myApartmentBuildingProperties[i]->propertyValueWithEvent = percentToBe * myApartmentBuildingProperties[i]->propertyValue;
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
    return "USA";
}

void Tycoon::printGameInfo() {
    cout << "\n~[$" << money-previous_money << "]\tnet change\n~[$" << money << "]\tcurrent bank balance\n~[$"
    <<sumPropertyValue<<"]\ttotal property values\n~[$" << sumMortgages << "]\ttotal money owed in mortgage\n";
    printMyProperties();
}

void Tycoon::collectRents() {
    cout << "\n\t->Collecting Rents...\n";
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        for(int g = 0 ; g < 5; g++){ // five is the number of tennants in businesses
            if(myBusinessBuildingProperties[i]->hasTennant[g]
            && myBusinessBuildingProperties[i]->tennantList[g]->willingToPay){
                money += myBusinessBuildingProperties[i]->roomRent[g];
                cout << " +$" << myBusinessBuildingProperties[i]->roomRent[g];
            }
        }
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        if(myResidentialProperties[i]->hasTennant && myResidentialProperties[i]->myTennant->willingToPay){
            money += myResidentialProperties[i]->rent;
            cout << " +$" << myResidentialProperties[i]->rent;
        }
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        for(int g = 0 ; g < 10; g++){ // five is the number of tennants in residences
            if(myApartmentBuildingProperties[i]->hasTennant[g] && myApartmentBuildingProperties[i]->tennantList[g]->willingToPay){
                money += myApartmentBuildingProperties[i]->rent;
                cout << " +$" << myApartmentBuildingProperties[i]->rent;
            }
        }
    }
}

//https://stackoverflow.com/questions/307765/how-do-i-check-if-an-objects-type-is-a-particular-subclass-in-c
//dumb but I'm not trynna rewrite
bool Tycoon::buyThisProperty(Property *in) {
    if(dynamic_cast<ResidentialBuilding*>(in) != nullptr){
        buyThisProperty(dynamic_cast<ResidentialBuilding*>(in));
    }else if(dynamic_cast<ApartmentBuilding*>(in) != nullptr){
        buyThisProperty(dynamic_cast<ApartmentBuilding*>(in));
    }else if(dynamic_cast<BusinessBuilding*>(in) != nullptr){
        buyThisProperty(dynamic_cast<BusinessBuilding*>(in));
    }else{
        cout << "{No Sub Prop}";
    }
    return false;
}

//https://stackoverflow.com/questions/307765/how-do-i-check-if-an-objects-type-is-a-particular-subclass-in-c
//next time I'mma do this wtf
bool Tycoon::buyThisProperty(ResidentialBuilding *in) {
    if(sizeMyResidentialProperties >= 20){
        cout << "Already have too many Residential Properties!\n";
        return false;
    }else{
        if(money > in->propertyValue) {
            myResidentialProperties[sizeMyResidentialProperties++] = in;
            money -= in->propertyValueWithEvent * in->propertyTax * 2;
            sumPropertyValue += in->propertyValue;
            sumMortgages += in->mortgageTotal;
            cout << "$$SOLD$$\t" << string(*in) << endl;
            cout << "-$" << in->propertyTax * in->propertyValueWithEvent * 2 << " in sales taxes\n";
        }else{
            return false;
            cout << "Sorry! You're too broke to buy this residence, some back when you're a little.... richer! \n";
        }
    }
    sizeResidentialPropertyList--;
    return true;
}

bool Tycoon::buyThisProperty(BusinessBuilding *in) {
    if(sizeMyBusinessBuildingProperties >= 20){
        cout << "Already have too many Business Properties!\n";
        return false;
    }else{
        if(money > in->propertyValue) {
            myBusinessBuildingProperties[sizeMyBusinessBuildingProperties++] = in;
            money -= in->propertyValueWithEvent * in->propertyTax * 2;
            sumPropertyValue += in->propertyValue;
            sumMortgages += in->mortgageTotal;
            cout << "$$SOLD$$\t" << string(*in) << endl;
            cout << "-$" << in->propertyTax * in->propertyValueWithEvent * 2 << " in sales taxes\n";
        }else{
            cout << "Sorry! You're too broke to buy this business, some back when you're a little.... richer! \n";
            return false;
        }
    }
    sizebusinessPropertyList--;
    return true;
}

bool Tycoon::buyThisProperty(ApartmentBuilding *in) {
    if(sizeMyApartmentBuildingProperties >= 20){
        cout << "Already have too many Business Properties!\n";
        return false;
    }else{
        if(money > in->propertyValue) {
            myApartmentBuildingProperties[sizeMyApartmentBuildingProperties++] = in;
            money -= in->propertyValueWithEvent * in->propertyTax * 2;
            sumPropertyValue += in->propertyValue;
            sumMortgages += in->mortgageTotal;
            cout << "$$SOLD$$\t" << string(*in) << endl;
            cout << "-$" << in->propertyTax * in->propertyValueWithEvent * 2 << " in sales taxes\n";
        }else{
            cout << "Sorry! You're too broke to buy this apartment, some back when you're a little.... richer! \n";
            return false;
        }
    }
    sizeapartmentPropertyList--;
    return true;
}

void Tycoon::sellResProperty(const int & index) {
    cout <<"$$SOLD$$\t" << string(*myResidentialProperties[index]) << "\n+$" << myResidentialProperties[index]->propertyValueWithEvent - myResidentialProperties[index]->mortgageTotal;
    money += (myResidentialProperties[index]->propertyValueWithEvent - myResidentialProperties[index]->propertyValueWithEvent);
    sumPropertyValue -= myResidentialProperties[index]->propertyValue;
    sumMortgages -= myResidentialProperties[index]->mortgageTotal;
    swap(myResidentialProperties[index] , myResidentialProperties[sizeMyResidentialProperties-1]);
    sizeMyResidentialProperties--;
}

void Tycoon::sellBusProperty(const int &index) {
    cout <<"$$SOLD$$\t" << string(*myBusinessBuildingProperties[index]) << "\n+$" << myBusinessBuildingProperties[index]->propertyValueWithEvent - myBusinessBuildingProperties[index]->mortgageTotal;
    money += (myBusinessBuildingProperties[index]->propertyValueWithEvent - myBusinessBuildingProperties[index]->propertyValueWithEvent);
    sumPropertyValue -= myBusinessBuildingProperties[index]->propertyValue;
    sumMortgages -= myBusinessBuildingProperties[index]->mortgageTotal;
    swap(myBusinessBuildingProperties[index] , myBusinessBuildingProperties[sizeMyBusinessBuildingProperties-1]);
    sizeMyBusinessBuildingProperties--;
}

void Tycoon::sellAptProperty(const int &index) {
    cout <<"$$SOLD$$\t" << string(*myApartmentBuildingProperties[index]) << "\n+$" << myApartmentBuildingProperties[index]->propertyValueWithEvent - myApartmentBuildingProperties[index]->mortgageTotal;
    money += (myApartmentBuildingProperties[index]->propertyValueWithEvent - myApartmentBuildingProperties[index]->propertyValueWithEvent );
    sumPropertyValue -= myApartmentBuildingProperties[index]->propertyValue;
    sumMortgages -= myApartmentBuildingProperties[index]->mortgageTotal;
    swap(myApartmentBuildingProperties[index] , myApartmentBuildingProperties[sizeMyApartmentBuildingProperties-1]);
    sizeMyApartmentBuildingProperties--;
}


void Tycoon::turn_run() {
    cout << "================================================================================" << endl;
    randomEvent();
    printGameInfo();
    previous_money = money;

    option_menu();

    collectRents();
    collectMonthlyMortgage();
    if(turn++ % 12 == 0) collectIncomeTax();
    cout << "\n...turn ends...\n";
    int sv = input_getLineInt();
}

void Tycoon::collectMonthlyMortgage() {
    cout << "\n\t->Paying All Mortgages...\n";
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        payMortgage(myApartmentBuildingProperties[i]);
    }
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        payMortgage(myBusinessBuildingProperties[i]);
    }
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        payMortgage(myResidentialProperties[i]);
    }
}

void Tycoon::payMortgage(Property * in) {
    cout << "-$" << in->mortgageMonthly << " ";
    in->mortgageTotal -= in->mortgageMonthly;
    money -= in->mortgageMonthly;
    sumMortgages -= in->mortgageMonthly;
    in->payMortgage();
}

void Tycoon::collectIncomeTax() {
    cout << "\n\t->Paying income tax...";
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        money -= myResidentialProperties[i]->getPropertyTax();
    }
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        money -= myBusinessBuildingProperties[i]->getPropertyTax();
    }
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        money -= myApartmentBuildingProperties[i]->getPropertyTax();
    }
}

void Tycoon::option_menu() {
    bool done = false;
    string s;
    char c;
    while(!done){
        cout << "\nTurn: [" << turn << "]\n\t>So what will you do this month?\n>\t\t[0] Buy a Property\n>\t\t[1] Sell a Property\n>\t\t[2] Adjust Rents\n";
        int c = input_getLineInt();
        switch(c){
            case 0:
                cout << "Buy a Property" << endl;
                done = option_BuyProperty();
                break;
            case 1:
                cout << "Sell a Property" << endl;
                done = option_SellProperty();
                break;
            case 2:
                cout << "Adjust Rent on a Property" << endl;
                done = option_AdjustRent();
                break;
            default:
                continue;
        }
    }
}



bool Tycoon::option_BuyProperty() {
    Property * someProps[3];
    int a[3];
    top:
    { // i couldn't make this into a function getThreeProperties()
        Property * someProp;
        if(sizebusinessPropertyList + sizeapartmentPropertyList + sizeResidentialPropertyList < 4) generateNewPropertyList();
        for(int i = 0 ; i < 3 ; i++) {
            int r = rand() % 9;
            if(i==0) a[0] = r; //actual chimp programming
            else if(i==1)a[1] = r;
            else if(i==2)a[2]= r;
            if (r < 3 && r < sizebusinessPropertyList && r >= 0){
                if(&businessPropertyList[r] == nullptr){
                    i--;
                    continue;
                }
                someProp = businessPropertyList[r];
            }
            else if (r < 6 && r - 3 < sizeapartmentPropertyList && r >= 3) {
                if(&apartmentPropertyList[r - 3] == nullptr){
                    i--;
                    continue;
                }
                someProp = apartmentPropertyList[r - 3];
            }
            else if (r < 9 && r - 6 < sizeResidentialPropertyList && r>=6) {
                if(&residientialPropertyList[r-6] == nullptr){
                    i--;
                    continue;
                }
                someProp = residientialPropertyList[r - 6];
            }
            else {
                i--;
                continue; //smart
            }
            bool alreadyExists = false;
            for (int g = 0; g < i; g++) { // genius
                if (someProps[g] == someProp) { //why ?? not compare poitner
                    alreadyExists = true; //compare pointer not worke :????
                    break;
                }
            }
            if (alreadyExists) {
                i--;
                continue;
            }
            if(someProp == nullptr || someProp == NULL || &someProp == nullptr || !someProp){// if it didn't get set somehow
                i--;
                continue; // i was honestly about to kill myself or use a goto right here
            }
            someProps[i] = someProp;
        }
    }
        cout << "Potential Properties to Purchase: \n[0]" << string(*someProps[0]) << "\n[1]" << string(*someProps[1])
             << "\n[2]" << string(*someProps[2]) << "\n[c] cancel\n";
    int c = input_getLineInt();
    Property * toBuy;
    bool sucessfulPurchase;
    while(true) {
        switch (c) {
            case 0:
            case 1:
            case 2:
                sucessfulPurchase = buyThisProperty(someProps[c]);
                if(dynamic_cast<BusinessBuilding*>(someProps[c]) != nullptr)
                    swap(businessPropertyList[a[c]], businessPropertyList[sizebusinessPropertyList]);
                else if(dynamic_cast<ApartmentBuilding*>(someProps[c]) != nullptr)
                    swap(apartmentPropertyList[a[c] - 3], apartmentPropertyList[sizeapartmentPropertyList]);
                else if(dynamic_cast<ResidentialBuilding*>(someProps[c]) != nullptr)
                    swap(residientialPropertyList[a[c] - 6], residientialPropertyList[sizeResidentialPropertyList]);
                break;
            default:
                cout << endl;
                return false;
        }
        break;
    }
    return sucessfulPurchase;
}

bool Tycoon::option_SellProperty() {
    printMyPropertiesEnumerate();
    cout << "\n\t->Sell which property?\n";
    int choice = input_getLineInt();
    if(choice < sizeMyResidentialProperties){
        sellResProperty(choice);
    }else if(choice < sizeMyApartmentBuildingProperties + sizeMyResidentialProperties){
        sellAptProperty(choice - sizeMyResidentialProperties);
    }else if(choice < sizeMyBusinessBuildingProperties + sizeMyApartmentBuildingProperties + sizeMyResidentialProperties){
        sellBusProperty(choice - sizeMyResidentialProperties - sizeMyApartmentBuildingProperties);
    }else{
        cout << "\nInvalid Property\n";
        return false;
    }
    return true;
}

bool Tycoon::option_AdjustRent() {
    printMyPropertiesEnumerate();
    cout << "\t->Adjust rent of which property?\n";
    int choice = input_getLineInt();
    cout << "\t->Change rent to what value?\n";
    int toThisRent = input_getLineInt();
    if(choice < sizeMyResidentialProperties){
        myResidentialProperties[choice]->adjustRentTo(toThisRent, 0);
    }else if(choice < sizeMyResidentialProperties + sizeMyApartmentBuildingProperties){
        myApartmentBuildingProperties[choice-sizeMyResidentialProperties]->adjustRentTo(toThisRent, 0);
    }else if(choice < sizeMyResidentialProperties + sizeMyApartmentBuildingProperties + sizeMyBusinessBuildingProperties){
        cout << "Rents here: \n";
        for(int i = 0 ; i < 5 ; i++) cout << ">[" << i << "]: " << myBusinessBuildingProperties[choice-sizeMyResidentialProperties-sizeMyApartmentBuildingProperties]->roomRent[i];
        int roomChoice = input_getLineInt();
        if(roomChoice > 4){
            cout <<"\ninvalid room\n";
            return false;
        }
        myBusinessBuildingProperties[choice-sizeMyResidentialProperties-sizeMyApartmentBuildingProperties]->adjustRentTo(toThisRent, roomChoice);
    }else{
        cout << "\nInvalid Property\n";
        return false;
    }
    return true;
}

void Tycoon::printMyProperties() {
    cout << "\n~[" <<sizeMyResidentialProperties<<"/20]\tresidences owned:";
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        ResidentialBuilding * r =  myResidentialProperties[i];
        cout << "\n>" <<  std::string(*r);
    }
    cout << "\n~[" << sizeMyApartmentBuildingProperties << "/20]\tapartments owned";
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        ApartmentBuilding * a = myApartmentBuildingProperties[i];
        cout << "\n>" << std::string(*a);
    }
    cout << "\n~[" << sizeMyBusinessBuildingProperties << "/20]\tbusinessesOwned";
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        BusinessBuilding * b = myBusinessBuildingProperties[i];
        cout << "\n>" << std::string(*b);
    }
}

void Tycoon::printMyPropertiesEnumerate(){
    int enumerate = 0;
    cout << "~[" <<sizeMyResidentialProperties<<"/20]\tresidences owned:";
    for(int i = 0 ; i < sizeMyResidentialProperties; i++){
        ResidentialBuilding * r =  myResidentialProperties[i];
        cout << "\n>[" << enumerate++ << "] " <<  std::string(*r);
    }
    cout << "\n~[" << sizeMyApartmentBuildingProperties << "/20]\tapartments owned";
    for(int i = 0 ; i < sizeMyApartmentBuildingProperties; i++){
        ApartmentBuilding * a = myApartmentBuildingProperties[i];
        cout << "\n>[" << enumerate++ << "] " << std::string(*a);
    }
    cout << "\n~[" << sizeMyBusinessBuildingProperties << "/20]\tbusinessesOwned";
    for(int i = 0 ; i < sizeMyBusinessBuildingProperties; i++){
        BusinessBuilding * b = myBusinessBuildingProperties[i];
        cout << "\n>[" << enumerate++ << "] " << std::string(*b);
    }
}

int Tycoon::input_getLineInt() {
    string s;
    cout << ">>>";
    getline(cin , s);
    string nums = "";
    for( int i = 0 ; i < s.length(); i++){
        if(isdigit(s[i])) nums += s[i];
    }
    if(nums.length() < 1) return -1;
    int toRet = stoi(nums);
    return toRet;
}










































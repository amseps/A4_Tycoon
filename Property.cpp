//
// Created by AM on 10/20/2020.
//

#include <iostream>
#include "Property.h"


Property::Property() {
    myID = propID++;
}

Property::Property(const Property &in) {

}

Property::~Property() {

}

Property &Property::operator=(const Property &in) {
    if(this == &in){
        return *this;
    }
    Property * newProp = new Property(in);
    return *newProp;
}

void Property::adjustRentTo(const int &in, const int &space) {
    std::cout << "{?adjustRentTo parent?}";
}

void Property::payMortgage() {
    if(mortgageDuration > 1){
        mortgageDuration--;
        mortgageTotal -= mortgageMonthly;

    }
    else if(mortgageDuration == 1){
        mortgageTotal = 0;
        mortgageDuration = -1;
        std::cout << "\t->Payed off Property!\n";
    }else{

    }
}

int Property::getPropertyTax() {
    return propertyTax * propertyValueWithEvent;
}

std::string Property::dictateLocation() const{
    switch(loc){
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

std::ostream &Property::operator<<(std::ostream &_stream) {
    _stream << "[PROP]";
    return _stream;
}

Property::operator std::string() const {
    return "[PROP]" + dictateLocation();
}

std::string Property::ts() {
    return "[PROP]";
}

bool Property::sameInstance(const Property &in) {
    return this == &in;
}



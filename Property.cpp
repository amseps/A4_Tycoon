//
// Created by AM on 10/20/2020.
//

#include <iostream>
#include "Property.h"

Property::Property() {

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



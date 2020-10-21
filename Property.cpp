//
// Created by AM on 10/20/2020.
//

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



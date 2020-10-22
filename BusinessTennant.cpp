//
// Created by AM on 10/20/2020.
//

#include "BusinessTennant.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

BusinessTennant::BusinessTennant(){
    srand (time(NULL));
    agreeability = rand() % 5 + 1;
    monthlyBudget = rand() % 4500 + 500;
    willingToPay = true;
}

BusinessTennant::BusinessTennant(const BusinessTennant & in){
    //TODO
}

BusinessTennant::~BusinessTennant(){

}

BusinessTennant &BusinessTennant::operator=(const BusinessTennant & in){
    if(&in == this) return *this;
    BusinessTennant *a = new BusinessTennant(in);
    return *a;
}
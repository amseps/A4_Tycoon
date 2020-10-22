//
// Created by AM on 10/20/2020.
//

#include "Tennant.h"


#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Tennant::Tennant(){
    Tennant::agreeability = rand() % 5 + 1;
    Tennant::monthlyBudget = rand() % 4500 + 500;
    Tennant::willingToPay = true;
}

Tennant::Tennant(const Tennant & in){
    this->monthlyBudget = in.monthlyBudget;
    this->agreeability = in.agreeability;
    this->willingToPay = in.willingToPay;
}

Tennant::~Tennant(){

}

Tennant & Tennant::operator=(Tennant & in){
    if(this == &in) return *this;
    return *new Tennant(in);
}
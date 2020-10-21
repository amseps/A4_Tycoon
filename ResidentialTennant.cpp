//
// Created by AM on 10/20/2020.
//

#include "ResidentialTennant.h"
#include "Tennant.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

ResidentialTennant::ResidentialTennant(){
    srand (time(NULL));
    agreeability = rand() % 5 + 1;
    monthlyBudget = rand() % 4500 + 500;
}

ResidentialTennant::ResidentialTennant(const ResidentialTennant & in){
    //TODO
}

ResidentialTennant::~ResidentialTennant(){
    //TODO
}

ResidentialTennant & ResidentialTennant::operator=(const ResidentialTennant & in){
    //TODO
}
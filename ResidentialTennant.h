//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_RESIDENTIALTENNANT_H
#define A4_TYCOON_RESIDENTIALTENNANT_H

#include "Tennant.h"

class ResidentialTennant : public Tennant {
public:
    ResidentialTennant();
    ResidentialTennant(const ResidentialTennant & in);
    ~ResidentialTennant();
    ResidentialTennant & operator=(const ResidentialTennant & in);
};


#endif //A4_TYCOON_RESIDENTIALTENNANT_H

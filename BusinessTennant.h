//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_BUSINESSTENNANT_H
#define A4_TYCOON_BUSINESSTENNANT_H

#include "Tennant.h"

class BusinessTennant : public Tennant {
public:
    BusinessTennant();
    BusinessTennant(const BusinessTennant & in);
    ~BusinessTennant();
    BusinessTennant & operator=(const BusinessTennant & in);
};


#endif //A4_TYCOON_BUSINESSTENNANT_H

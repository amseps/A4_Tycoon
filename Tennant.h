//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_TENNANT_H
#define A4_TYCOON_TENNANT_H


class Tennant {
public:
    int agreeability;
    int monthlyBudget;

    Tennant();
    Tennant(const Tennant & in);
    ~Tennant();
    Tennant & operator=(const Tennant & in);
};


#endif //A4_TYCOON_TENNANT_H

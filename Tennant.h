//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_TENNANT_H
#define A4_TYCOON_TENNANT_H


class Tennant {
public:
    int agreeability;
    int monthlyBudget;
    bool willingToPay;

    Tennant();
    Tennant(const Tennant & in);
    ~Tennant();
    Tennant & operator=(Tennant & in);
};


#endif //A4_TYCOON_TENNANT_H

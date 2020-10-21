//
// Created by AM on 10/20/2020.
//

#ifndef A4_TYCOON_TYCOON_H
#define A4_TYCOON_TYCOON_H


class Tycoon {
private:
    int money;
    int turn;



public:
    void runGame();

    Tycoon();
    Tycoon(Tycoon & in);
    ~Tycoon();
    Tycoon & operator=(const Tycoon right);
};


#endif //A4_TYCOON_TYCOON_H

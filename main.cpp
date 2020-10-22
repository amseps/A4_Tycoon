#include <iostream>
#include "Tycoon.h"
int main() {
    srand (time(NULL));
    Tycoon * game = new Tycoon();
    game->runGame();
    return 0;
}
//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_SDESTROYER_H
#define CPP_BATTLESHIP_GAME_SDESTROYER_H


#include <ostream>
#include "Ship.h"

class SDestroyer
        : public Ship {
public:
    SDestroyer() : Ship(
            "Destroyer",
            2,
            3
    ) {}

};


#endif //CPP_BATTLESHIP_GAME_SDESTROYER_H

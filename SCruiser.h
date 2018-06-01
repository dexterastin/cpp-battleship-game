//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_SCRUISER_H
#define CPP_BATTLESHIP_GAME_SCRUISER_H


#include "Ship.h"

class SCruiser
        : public Ship {
public:
    SCruiser() : Ship(
            "Cruiser",
            3,
            2
    ) {}
};


#endif //CPP_BATTLESHIP_GAME_SCRUISER_H

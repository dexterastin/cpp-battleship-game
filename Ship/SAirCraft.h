//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_SAIRCRAFT_H
#define CPP_BATTLESHIP_GAME_SAIRCRAFT_H


#include <ostream>
#include "Ship.h"

class SAirCraft
        : public Ship {
public:
    SAirCraft() : Ship(
            "Aircraft",
            5,
            0
    ) {}
};


#endif //CPP_BATTLESHIP_GAME_SAIRCRAFT_H

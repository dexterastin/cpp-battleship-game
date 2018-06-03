//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_SBATTLESHIP_H
#define CPP_BATTLESHIP_GAME_SBATTLESHIP_H


#include <ostream>
#include "Ship.h"

class SBattleShip
        : public Ship {
public:
    SBattleShip() : Ship(
            "BattleShip",
            4,
            1
    ) {}
};


#endif //CPP_BATTLESHIP_GAME_SBATTLESHIP_H

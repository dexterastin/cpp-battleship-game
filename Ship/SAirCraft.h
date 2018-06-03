//
// C++ BattleShip Project
// 작성 일자 : 2018.06.01
// 20171648 양기현
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

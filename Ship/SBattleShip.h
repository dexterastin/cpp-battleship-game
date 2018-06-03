//
// C++ BattleShip Project
// 작성 일자 : 2018.06.01
// 20171648 양기현
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

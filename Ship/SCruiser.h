//
// C++ BattleShip Project
// 작성 일자 : 2018.06.01
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_SCRUISER_H
#define CPP_BATTLESHIP_GAME_SCRUISER_H


#include <ostream>
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

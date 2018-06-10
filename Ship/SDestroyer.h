//
// C++ BattleShip Project
// 작성 일자 : 2018.06.01
// 20171648 양기현
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

    int getSize() const override {
        return this->size;
    }
};


#endif //CPP_BATTLESHIP_GAME_SDESTROYER_H

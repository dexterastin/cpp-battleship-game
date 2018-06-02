//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#ifndef CPP_BATTLESHIP_GAME_PLAYER_H
#define CPP_BATTLESHIP_GAME_PLAYER_H


#include "CBattleShipMap.h"

class Player {
protected:
    CBattleShipMap *map;

private:
    void setupShips();

public:
    Player();

    ~Player();

    virtual void init();

    void render();

};


#endif //CPP_BATTLESHIP_GAME_PLAYER_H

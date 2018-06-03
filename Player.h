//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#ifndef CPP_BATTLESHIP_GAME_PLAYER_H
#define CPP_BATTLESHIP_GAME_PLAYER_H


#include "CBattleShipMap.h"
#include "Ship/Ship.h"

class Player {
protected:
    CBattleShipMap *map;
    int type;

public:
    Player(int col);

    ~Player();

    virtual void init();

    void render();

    void setupShip(Ship *ship);

    void setHitResult(struct position pos, Ship *deadShip = nullptr);

    char at(struct position);

};


#endif //CPP_BATTLESHIP_GAME_PLAYER_H

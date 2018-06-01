//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H
#define CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H


#include "Pane.h"
#include "GameManager.h"

#define MAP_SIZE 8

class CBattleShipMap : Pane {
protected:
    char mapData[MAP_SIZE][MAP_SIZE];

public:
    CBattleShipMap();

    ~CBattleShipMap();

    void draw();


};


#endif //CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H

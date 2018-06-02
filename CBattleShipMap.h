//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H
#define CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H


#include "Pane.h"

#define MAP_SIZE 8

class CBattleShipMap : Pane {
protected:
    char mapData[MAP_SIZE][MAP_SIZE];

public:
    CBattleShipMap(int y);

    ~CBattleShipMap();

    void draw();

    void setMapData(int x, int y, char type);
};


#endif //CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H

//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H
#define CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H


#include "Pane.h"

#define MAP_SIZE 8

class CBattleShipMap : Pane {
public:
    char mapData[MAP_SIZE][MAP_SIZE];

public:
    CBattleShipMap(int y, const char *header);

    ~CBattleShipMap();

    void draw();

    void setMapData(struct position, char type);

};


#endif //CPP_BATTLESHIP_GAME_CBATTLESHIPMAP_H

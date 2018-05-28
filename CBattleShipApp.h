//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H
#define CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H


#include "CBattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"

class CBattleShipApp {
public:
    CBattleShipApp();

    ~CBattleShipApp();

    void play();

protected:
    CBattleShipMap *cBattleShipMap;
    StatPane *statPane;
    InputPane *inputPane;

    void init();

    void render();

    void destroy();
};


#endif //CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H

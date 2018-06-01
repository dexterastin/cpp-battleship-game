//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H
#define CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H


#include "CBattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"
#include "GameManager.h"

class CBattleShipApp {
protected:
    CBattleShipMap *cBattleShipMap;
    StatPane *statPane;
    InputPane *inputPane;

    void init(GameManager &gameManager);

    void render();

    void update();

    void destroy();

public:
    CBattleShipApp();

    ~CBattleShipApp();

    void play();
};


#endif //CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H

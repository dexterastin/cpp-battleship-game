//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H
#define CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H


#include "CBattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"
#include "GameManager.h"

class CBattleShipApp {
protected:
    GameManager *gameManager;
    StatPane *statPane;
    InputPane *inputPane;

    void init();

    void render();

    void update();

    void destroy();

public:
    CBattleShipApp();

    ~CBattleShipApp();

    int play();
};


#endif //CPP_BATTLESHIP_GAME_CBATTLESHIPAPP_H

//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_STATPANE_H
#define CPP_BATTLESHIP_GAME_STATPANE_H

#include "Pane.h"


class StatPane : Pane {
public:
    StatPane(int x, int y, int width, int height);

    ~StatPane();

    virtual void draw();

    void update(int turn);
};


#endif //CPP_BATTLESHIP_GAME_STATPANE_H

//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_PANE_H
#define CPP_BATTLESHIP_GAME_PANE_H


#include <curses.h>

class Pane {
protected:
    int width, height;
    int x, y;
    WINDOW *mpWindow;

public:
    Pane(int x, int y, int width, int height);

    virtual ~Pane();

    virtual void draw();
};


#endif //CPP_BATTLESHIP_GAME_PANE_H

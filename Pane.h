//
// Created by Gihyeon Yang on 2018. 5. 28..
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

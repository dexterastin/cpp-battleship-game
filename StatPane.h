//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_STATPANE_H
#define CPP_BATTLESHIP_GAME_STATPANE_H


#include "Pane.h"

class StatPane : Pane {
public:
    StatPane(int x, int y, int width, int height);

    ~StatPane();

    virtual void draw();
};


#endif //CPP_BATTLESHIP_GAME_STATPANE_H

//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#ifndef CPP_BATTLESHIP_GAME_INPUTPANE_H
#define CPP_BATTLESHIP_GAME_INPUTPANE_H


#include "Pane.h"

class InputPane :
        public Pane {
public:
    InputPane(int x, int y, int width, int height);

    ~InputPane();

    virtual void draw();

};


#endif //CPP_BATTLESHIP_GAME_INPUTPANE_H

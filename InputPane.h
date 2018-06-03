//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
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

    int input();

};


#endif //CPP_BATTLESHIP_GAME_INPUTPANE_H

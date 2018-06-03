//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#include "Pane.h"

Pane::Pane(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {
    this->mpWindow = newwin(height, width, y, x);
    box(this->mpWindow, 0, 0);
    wrefresh(this->mpWindow);
}

Pane::~Pane() {
    delwin(this->mpWindow);
}

void Pane::draw() {
    box(this->mpWindow, 0, 0);
    wrefresh(this->mpWindow);
}

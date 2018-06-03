//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#include <iostream>
#include "InputPane.h"

InputPane::InputPane(int x, int y, int width, int height)
        : Pane(x, y, width, height) {
    mvwprintw(this->mpWindow, 0, 3, "< INPUT >");
}

InputPane::~InputPane() = default;

void InputPane::draw() {
    wattroff(this->mpWindow, COLOR_PAIR(3));
    mvwprintw(this->mpWindow, 1, 2, "Input position...(ex A 3)");
    mvwprintw(this->mpWindow, 2, 2, "Input : ");
    wattroff(this->mpWindow, COLOR_PAIR(3));
    wrefresh(this->mpWindow);
}

int InputPane::input() {
    char str[10];
    mvprintw(this->y + 2, this->x + 10, "");
    getstr(str);

    int rInt = 0;

    rInt += (str[0] - 'A') * 10;
    rInt += (str[1] - '1');

    return rInt;
}

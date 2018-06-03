//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height)
        : Pane(x, y, width, height) {
    mvwprintw(this->mpWindow, 0, 3, "< STATUS >");
}

StatPane::~StatPane() = default;

void StatPane::draw() {
    wattroff(this->mpWindow, COLOR_PAIR(2));
    mvwprintw(this->mpWindow, 1, 2, "TURN : 0");
    mvwprintw(this->mpWindow, 2, 2, "AIRCRAFT : AAAAA");
    mvwprintw(this->mpWindow, 3, 2, "BATTLESHIP : BBBB");
    mvwprintw(this->mpWindow, 4, 2, "CRUISER : CCC");
    mvwprintw(this->mpWindow, 5, 2, "DESTROYER: DD DD");
    wattroff(this->mpWindow, COLOR_PAIR(2));
    wrefresh(this->mpWindow);
}


void StatPane::update(int turn) {
    wattroff(this->mpWindow, COLOR_PAIR(2));
    mvwprintw(this->mpWindow, 1, 2, "TURN : %d", turn);
    wattroff(this->mpWindow, COLOR_PAIR(2));
    wrefresh(this->mpWindow);
}
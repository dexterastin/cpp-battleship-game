//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height)
        : Pane(x, y, width, height) {
    mvwprintw(this->mpWindow, 0, 3, "< STATUS >");
}

StatPane::~StatPane() {

}

void StatPane::draw() {
    wattroff(this->mpWindow, COLOR_PAIR(2));
    mvwprintw(this->mpWindow, 1, 2, "AIRCRAFT : AAAAA");
    mvwprintw(this->mpWindow, 2, 2, "BATTLESHIP : BBBB");
    mvwprintw(this->mpWindow, 3, 2, "CRUISER : CCC");
    mvwprintw(this->mpWindow, 4, 2, "DESTROYER: DD DD");
    wattroff(this->mpWindow, COLOR_PAIR(2));
    wrefresh(this->mpWindow);
}

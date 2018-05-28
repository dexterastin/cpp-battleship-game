//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include "InputPane.h"

InputPane::InputPane(int x, int y, int width, int height)
        : Pane(x, y, width, height) {
    mvwprintw(this->mpWindow, 0, 3, "< INPUT >");
}

InputPane::~InputPane() {

}

void InputPane::draw() {
    wattroff(this->mpWindow, COLOR_PAIR(3));
    mvwprintw(this->mpWindow, 1, 2, "Input positioin...(ex A 3)");
    mvwprintw(this->mpWindow, 2, 2, "Input : ");
    wattroff(this->mpWindow, COLOR_PAIR(3));
    wrefresh(this->mpWindow);
}

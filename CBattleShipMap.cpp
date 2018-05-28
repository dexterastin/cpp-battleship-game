//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include "CBattleShipMap.h"

CBattleShipMap::CBattleShipMap()
        : Pane(4, 4, MAP_SIZE + 3, MAP_SIZE + 2) {
    for (auto &i : this->mapData) {
        for (char &j : i) {
            j = '0';
        }
    }

    for (int k = 0; k < MAP_SIZE; ++k) {
        mvprintw(k + 1 + this->y, this->x - 1, "%c", 'A' + k);
        mvprintw(this->y + this->height, this->x + 2 + k, "%d", 1 + k);
    }

    mvwprintw(this->mpWindow, 0, 3, "< MAP >");
}

CBattleShipMap::~CBattleShipMap() {

}

void CBattleShipMap::draw() {
    wattron(this->mpWindow, COLOR_PAIR(1));
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            mvwprintw(this->mpWindow, i + 1, j + 2, "%c", this->mapData[i][j]);
        }
    }
    wattroff(this->mpWindow, COLOR_PAIR(1));
    wrefresh(this->mpWindow);
}

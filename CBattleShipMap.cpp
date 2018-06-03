//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include <iostream>
#include "CBattleShipMap.h"
#include "ShipHeader.h"

CBattleShipMap::CBattleShipMap(int y, const char *header)
        : Pane(4, y, MAP_SIZE + 3, MAP_SIZE + 2) {

    for (auto &i : this->mapData) {
        for (char &j : i) {
            j = '_';
        }
    }

    for (int k = 0; k < MAP_SIZE; ++k) {
        mvprintw(k + 1 + this->y, this->x - 1, "%c", 'A' + k);
        mvprintw(this->y + this->height, this->x + 2 + k, "%d", 1 + k);
    }

    mvwprintw(this->mpWindow, 0, 2, header);
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

void CBattleShipMap::setMapData(struct position pos, char type) {
    this->mapData[pos.x][pos.y] = type;
}
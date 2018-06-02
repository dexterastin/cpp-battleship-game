//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include <iostream>
#include "CBattleShipMap.h"
#include "ShipHeader.h"

CBattleShipMap::CBattleShipMap(int y)
        : Pane(4, y, MAP_SIZE + 3, MAP_SIZE + 2) {

    for (auto &i : this->mapData) {
        for (char &j : i) {
            j = '_';
        }
    }


    srand((unsigned int) time(NULL));


    Ship **pShip = new Ship *[5];
    pShip[0] = new SAirCraft();
    pShip[1] = new SBattleShip();
    pShip[2] = new SCruiser();
    pShip[3] = new SDestroyer();
    pShip[4] = new SDestroyer();

    struct position dir;
    Ship *ship = nullptr;
    for (int m = 0; m < 5; ++m) {
        ship = pShip[m];

        ship->setPos(
                this->mapData
        );

        for (int range = 0; range < ship->getSize(); ++range) {
            dir = ship->getPos() + (ship->getDirection() * range);
            this->mapData[dir.x][dir.y]
                    = (char) ('A' + ship->getType());
        }

    }

    for (int k = 0; k < MAP_SIZE; ++k) {
        mvprintw(k + 1 + this->y, this->x - 1, "%c", 'A' + k);
        mvprintw(this->y + this->height, this->x + 2 + k, "%d", 1 + k);
    }

    for (int l = 0; l < 3; ++l) {
        delete pShip[l];
    }
    delete[] pShip;

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

void CBattleShipMap::setMapData(int x, int y, char type) {
    this->mapData[x][y] = type;
}


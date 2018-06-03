//
// Created by Gihyeon Yang on 2018. 6. 3..
//

#include <cstdlib>
#include "BattleShipRndBot.h"

BattleShipRndBot::BattleShipRndBot(int mapsize) : Bot(mapsize) {

}

int BattleShipRndBot::command() {
    int x, y;
    do {
        x = rand() % 8;
        y = rand() % 8;
    } while (this->isVisitedAt(x, y));

    this->setAt(x, y);

    return y * 10 + x;
}

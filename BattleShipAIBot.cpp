//
// C++ BattleShip Project
// 작성 일자 : 2018.06.03
// 20171648 양기현
//

#include <cstdlib>
#include "BattleShipAIBot.h"

BattleShipAIBot::BattleShipAIBot(int mapsize) : Bot(mapsize) {}

int BattleShipAIBot::command() {
    int rInt;
    do {
        rInt = rand() % 88;
    } while (this->isVisitedAt(rInt / 10, rInt % 10));

    this->setAt(rInt / 10, rInt % 10);

    return rInt;
}

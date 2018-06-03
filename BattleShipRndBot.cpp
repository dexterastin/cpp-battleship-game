//
// C++ BattleShip Project
// 작성 일자 : 2018.06.03
// 20171648 양기현
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

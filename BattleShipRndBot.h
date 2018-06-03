//
// C++ BattleShip Project
// 작성 일자 : 2018.06.03
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_BATTLESHIPRNDBOT_H
#define CPP_BATTLESHIP_GAME_BATTLESHIPRNDBOT_H


#include "Bot.h"

class BattleShipRndBot
        : public Bot {
public:
    BattleShipRndBot(int mapsize);

    int command();
};


#endif //CPP_BATTLESHIP_GAME_BATTLESHIPRNDBOT_H

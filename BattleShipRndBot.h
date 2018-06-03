//
// Created by Gihyeon Yang on 2018. 6. 3..
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

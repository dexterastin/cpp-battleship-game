//
// C++ BattleShip Project
// 작성 일자 : 2018.06.02
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_GAMEMANAGER_H

#include "ShipHeader.h"
#include "Player.h"
#include "InputPane.h"
#include "unistd.h"
#include "BotHeader.h"

#define AIRCRAFT 1
#define BATTLESHIP 1
#define CRUISER 1
#define DESTROYER 2
#define SHIP_TYPE 4

#define BOT 0 // 0: User, 1: Rnd, 2: AI

#define CPP_BATTLESHIP_GAME_GAMEMANAGER_H

class GameManager {
private:
    Ship ***ship;
    int turn;
    Player *attacker;
    int numOfShip[4];
    Player *defender;
    InputPane *inputPane;
    Bot *bot;

public:

    GameManager(Player *attacker, Player *defender, InputPane *inputPane);

    ~GameManager();

    void init();

    void addTurn();

    void generateShip();

    void render();

    int getTurn() const;

    void setAttacker(Player *attacker);

    void setDefender(Player *defender);

    bool isDeadAllShip();

    InputPane *getInputPane() const;

    void setInputPane(InputPane *inputPane);

    void attack();

    Ship *attackShip(struct position attackPos);
};


#endif //CPP_BATTLESHIP_GAME_GAMEMANAGER_H

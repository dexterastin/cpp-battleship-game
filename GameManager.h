//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#ifndef CPP_BATTLESHIP_GAME_GAMEMANAGER_H
#define CPP_BATTLESHIP_GAME_GAMEMANAGER_H

#include "ShipHeader.h"
#include "Player.h"
#include "InputPane.h"

#define AIRCRAFT 1
#define BATTLESHIP 1
#define CRUISER 1
#define DESTROYER 2
#define SHIP_TYPE 4

class GameManager {
private:
    Ship ***ship;
    int turn;
    int mode;
    Player *attacker;
    int numOfShip[4];
    Player *defender;
    InputPane *inputPane;

public:

    GameManager(Player *attacker, Player *defender, InputPane *inputPane);

    ~GameManager();

    void init();

    void addTurn();

    void generateShip();

    void render();

    Ship ***getShip() const;

    void setShip(Ship ***ship);

    int getTurn() const;

    void setTurn(int turn);

    int getMode() const;

    void setMode(int mode);

    Player *getAttacker() const;

    void setAttacker(Player *attacker);

    Player *getDefender() const;

    void setDefender(Player *defender);

    bool isDeadAllShip();

    InputPane *getInputPane() const;

    void setInputPane(InputPane *inputPane);

    void attack();

    Ship *attackShip(struct position attackPos);
};


#endif //CPP_BATTLESHIP_GAME_GAMEMANAGER_H

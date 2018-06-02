//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#ifndef CPP_BATTLESHIP_GAME_GAMEMANAGER_H
#define CPP_BATTLESHIP_GAME_GAMEMANAGER_H

#include "ShipHeader.h"
#include "Player.h"

#define AIRCRAFT 1
#define BATTLESHIP 1
#define CRUISER 1
#define DESTROYER 2

class GameManager {
private:
    Ship ***ship;
    int turn;
    int mode;
    Player *attacker;
    Player *defender;

public:
    GameManager();

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

    Ship **isDeadShip() const;
};


#endif //CPP_BATTLESHIP_GAME_GAMEMANAGER_H

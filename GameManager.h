//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_GAMEMANAGER_H
#define CPP_BATTLESHIP_GAME_GAMEMANAGER_H

#define AIRCRAFT 1
#define BATTLESHIP 1
#define CRUISER 1
#define DESTROYER 2

#include "Ship.h"

class GameManager {
protected:
    Ship ***ships;

    int mode;
    int turn;

private:
    void generateShip();

public:
    GameManager(int mode, int turn);

    ~GameManager();

    void init();

    Ship ***getShips() const;

};


#endif //CPP_BATTLESHIP_GAME_GAMEMANAGER_H

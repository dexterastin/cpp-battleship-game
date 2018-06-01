//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#include "GameManager.h"
#include "SAirCraft.h"
#include "SBattleShip.h"
#include "SCruiser.h"
#include "SDestroyer.h"

GameManager::GameManager(int mode, int turn)
        : mode(mode), turn(turn) {}

GameManager::~GameManager() {
    for (int i = 0; i < sizeof(this->ships) / sizeof(*this->ships); ++i) {
        for (int j = 0; j < sizeof(this->ships[i]) / sizeof(*this->ships[i]); ++j) {
            delete[] this->ships[i][j];
        }
        delete[] this->ships[i];
    }
    delete[] this->ships;
}

void GameManager::init() {
    this->generateShip();
}

void GameManager::generateShip() {
    int shipLength[] = {
            AIRCRAFT,
            BATTLESHIP,
            CRUISER,
            DESTROYER
    };

    int ships = sizeof(shipLength) / sizeof(*shipLength);

    this->ships = new Ship **[ships];
    for (int i = 0; i < ships; ++i) {
        this->ships[i] = new Ship *[i];
        for (int j = 0; j < shipLength[i]; ++j) {
            switch (i) {
                case 0:
                    this->ships[i][j] = new SAirCraft();
                    break;
                case 1:
                    this->ships[i][j] = new SBattleShip();
                    break;
                case 2:
                    this->ships[i][j] = new SCruiser();
                    break;
                case 3:
                    this->ships[i][j] = new SDestroyer();
                    break;
                default:
                    break;
            }
        }
    }
}

Ship ***GameManager::getShips() const {
    return ships;
}

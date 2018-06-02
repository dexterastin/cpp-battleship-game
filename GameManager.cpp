//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#include "GameManager.h"

GameManager::GameManager() {
}

GameManager::~GameManager() {
    int numOfShip[] = {
            AIRCRAFT, BATTLESHIP, CRUISER, DESTROYER
    };

    this->ship = new Ship **[sizeof(numOfShip) / sizeof(*numOfShip)];

    for (int type = 0; type < sizeof(numOfShip) / sizeof(*numOfShip); ++type) {

        this->ship[type] = new Ship *[numOfShip[type]];

        for (int n = 0; n < numOfShip[type]; ++n) {
            delete[](ship[type][n]);
        }
        delete[](ship[type]);
    }
    delete[](ship);
}


void GameManager::init() {
    this->generateShip();
}

void GameManager::addTurn() {
    this->turn += 1;
}


void GameManager::generateShip() {
    int numOfShip[] = {
            AIRCRAFT, BATTLESHIP, CRUISER, DESTROYER
    };

    this->ship = new Ship **[sizeof(numOfShip) / sizeof(*numOfShip)];

    for (int type = 0; type < sizeof(numOfShip) / sizeof(*numOfShip); ++type) {

        this->ship[type] = new Ship *[numOfShip[type]];

        for (int n = 0; n < numOfShip[type]; ++n) {
            switch (type) {
                case 0:
                    this->ship[type][n] = new SAirCraft();
                    break;
                case 1:
                    this->ship[type][n] = new SBattleShip();
                    break;
                case 2:
                    this->ship[type][n] = new SCruiser();
                    break;
                case 3:
                    this->ship[type][n] = new SDestroyer();
                    break;
                default:
                    break;
            }
        }
    }
}


Ship ***GameManager::getShip() const {
    return ship;
}

void GameManager::setShip(Ship ***ship) {
    GameManager::ship = ship;
}

int GameManager::getTurn() const {
    return turn;
}

void GameManager::setTurn(int turn) {
    GameManager::turn = turn;
}

int GameManager::getMode() const {
    return mode;
}

void GameManager::setMode(int mode) {
    GameManager::mode = mode;
}

Player *GameManager::getAttacker() const {
    return attacker;
}

void GameManager::setAttacker(Player *attacker) {
    GameManager::attacker = attacker;
}

Player *GameManager::getDefender() const {
    return defender;
}

void GameManager::setDefender(Player *defender) {
    GameManager::defender = defender;
}

void GameManager::render() {

}

Ship **GameManager::isDeadShip() const {
    return nullptr;
}

//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#include "Player.h"

#define ATTACKER 1
#define DEFENDER 0


Player::Player(int type) {
    this->type = type;
    this->map = new CBattleShipMap(
            this->type * 15 + 3,
            (type == DEFENDER) ? "DEFENDER" : "ATTACKER"
    );
}

Player::~Player() {
    delete this->map;
}

void Player::init() {
}

void Player::setupShip(Ship *ship) {
    if (this->type == DEFENDER)
        ship->setPos(this->map->mapData);

    struct position movePos{};
    for (int range = 0; range < ship->getSize(); ++range) {
        movePos = ship->getPos() + ship->getDirection() * range;
        this->map->setMapData(
                movePos,
                (char) ('A' + ship->getType())
        );
    }
}

void Player::render() {
    this->map->draw();
}

void Player::setHitResult(struct position pos, Ship *deadShip) {
    if (this->type == DEFENDER) {
        if (this->map->mapData[pos.x][pos.y] != '_') {
            this->map->setMapData(pos, 'X');
        }
        return;
    };

    if (deadShip == nullptr) {
        this->map->setMapData(pos, 'X');
    } else {
        this->setupShip(deadShip);
    }


}

char Player::at(struct position pos) {
    return this->map->mapData[pos.x][pos.y];
}



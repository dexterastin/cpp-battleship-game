//
// Created by Gihyeon Yang on 2018. 6. 2..
//

#include "Player.h"


Player::Player() {
    this->map = new CBattleShipMap(10);
    this->init();
}

Player::~Player() {
    delete this->map;
}

void Player::init() {
    this->render();
}

void Player::setupShips() {

}


void Player::render() {
    this->map->draw();
}


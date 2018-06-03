//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#include "Ship.h"
#include  <cstdlib>
#include <ctime>
#include <iostream>

Ship::Ship(const std::string &name, const int size, const int type)
        : hp(size), name(name), size(size), type(type) {
}

position Ship::getPos() {
    return pos;
}

const int Ship::getSize() const {
    return size;
}

const int Ship::getType() const {
    return type;
}


void Ship::setPos(char map[8][8]) {

    struct position rPosition{};
    struct position tmpPositoin{};

    bool found = false;
    struct position direction[] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    bool validDirectoin[4];

    do {
        rPosition = {
                std::rand() % 8, std::rand() % 8
        };

        if (map[rPosition.x][rPosition.y] != '_') continue;

        bool f = false;

        for (int i = 0; i < 4; ++i) {
            validDirectoin[i] = true;
            for (int range = 0; range < this->getSize(); ++range) {
                tmpPositoin = rPosition + direction[i] * range;
                if (
                        !(
                                0 <= tmpPositoin.x && tmpPositoin.x <= 7 &&
                                0 <= tmpPositoin.y && tmpPositoin.y <= 7
                        ) ||
                        map[tmpPositoin.x][tmpPositoin.y] != '_'
                        ) {
                    validDirectoin[i] = false;
                    break;
                }
            }
            f |= validDirectoin[i];
        }

        if (!f) continue;

        int rnd = 0;
        do {
            rnd = std::rand() % 4;
        } while (!validDirectoin[rnd]);

        this->direction = direction[rnd];

        found = true;

    } while (!found);

    Ship::pos = rPosition;
}

const position &Ship::getDirection() const {
    return direction;
}

bool position::operator==(const position &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool position::operator!=(const position &rhs) const {
    return x != rhs.x ||
           y != rhs.y;
}

struct position position::operator+(const position &rhs) const {
    return position{
            x + rhs.x,
            y + rhs.y
    };
}

struct position position::operator*(int r) const {
    return position{
            x * r,
            y * r
    };
}

bool position::operator<(const position &rhs) const {
    return x < rhs.x && y < rhs.y;
}

bool position::operator>(const position &rhs) const {
    return rhs < *this;
}

bool position::operator<=(const position &rhs) const {
    return !(rhs < *this);
}

bool position::operator>=(const position &rhs) const {
    return !(*this < rhs);
}

std::ostream &operator<<(std::ostream &os, const position &position1) {
    os << "x: " << position1.x << " y: " << position1.y;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    os << "hp: " << ship.hp << " name: " << ship.name << " pos: " << ship.pos << " direction: " << ship.direction
       << " size: " << ship.size << " type: " << ship.type;
    return os;
}

void Ship::attack() {
    this->hp -= 1;
}

bool Ship::isDead() {
    return this->hp <= 0;
}

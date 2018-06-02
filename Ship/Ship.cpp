//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#include "Ship.h"
#include  <cstdlib>
#include <ctime>
#include <iostream>

Ship::Ship(const std::string &name, const int size, const int type)
        : hp(size), name(name), size(size), type(type) {
    // this->setPos();
}

int Ship::getHp() const {
    return hp;
}

const std::string &Ship::getName() const {
    return name;
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

    struct position rPos{}, tmpPos{};
    bool found = false;
    int rnd;
    bool *dirCheck;
    struct position directoin[4] = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };


    do {
        rPos = position {
                std::rand() % 8,
                std::rand() % 8
        };

        if (map[rPos.x][rPos.y] != '_') continue;

        dirCheck = new bool[4]();
        bool f = false;

        for (int i = 0; i < 4; ++i) {
            dirCheck[i] = true;
        }

        for (int i = 0; i < 4; ++i) {
            for (int range = 0; range < this->getSize(); ++range) {
                tmpPos = rPos + (directoin[i] * range);
                if (
                        !(0 <= tmpPos.x && tmpPos.x <= 7 &&
                          0 <= tmpPos.y && tmpPos.y <= 7) ||
                        map[tmpPos.x][tmpPos.y] != '_'
                        ) {
                    dirCheck[i] = false;
                    break;
                }
            }
            f |= dirCheck[i];
        }

        if (!f) {
            continue;
        }

        do {
            rnd = std::rand() % 4;
        } while (!dirCheck[rnd]);

        this->direction = directoin[rnd];
        this->pos = rPos;
        found = true;


    } while (!found);

    delete dirCheck;

    Ship::pos = rPos;
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

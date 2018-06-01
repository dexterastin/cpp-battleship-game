//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#include "Ship.h"

Ship::Ship(const std::string &name, const int size, const int type)
        : hp(size), name(name), size(size), type(type) {
    this->setPos();
}

int Ship::getHp() const {
    return hp;
}

const std::string &Ship::getName() const {
    return name;
}

const position &Ship::getPos() const {
    return pos;
}

const int Ship::getSize() const {
    return size;
}

const int Ship::getType() const {
    return type;
}


void Ship::setPos() {
    Ship::pos = position{
            0, 0, 0
    };
}

bool position::operator==(const position &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool position::operator!=(const position &rhs) const {
    return x != rhs.x ||
           y != rhs.y;
}

struct position position::operator+=(const position &rhs) const {
    return position{
            x + rhs.x,
            y + rhs.y
    };
}

struct position position::operator*=(int r) const {
    return position{
            x * r,
            y * r
    };
}


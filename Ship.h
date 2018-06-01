//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_SHIP_H
#define CPP_BATTLESHIP_GAME_SHIP_H

#include <ostream>

struct position {
    int x;
    int y;
    int d;

    bool operator==(const position &rhs) const;

    bool operator!=(const position &rhs) const;

    struct position operator+=(const position &rhs) const;

    struct position operator*=(int r) const;
};

class Ship {
private:
    int hp;
    const std::string name;
    struct position pos;
    const int size;
    const int type;

public:

    Ship();

    Ship(const std::string &name, int size, int type);

    int getHp() const;

    const std::string &getName() const;

    const position &getPos() const;

    const int getSize() const;

    const int getType() const;

    void setPos();


};


#endif //CPP_BATTLESHIP_GAME_SHIP_H

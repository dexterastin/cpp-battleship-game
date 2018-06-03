//
// Created by Gihyeon Yang on 2018. 6. 1..
//

#ifndef CPP_BATTLESHIP_GAME_SHIP_H
#define CPP_BATTLESHIP_GAME_SHIP_H

#include <ostream>

struct position {
    int x;
    int y;

    bool operator==(const position &rhs) const;

    bool operator!=(const position &rhs) const;

    struct position operator+(const position &rhs) const;

    struct position operator*(int r) const;

    bool operator<(const position &rhs) const;

    bool operator>(const position &rhs) const;

    bool operator<=(const position &rhs) const;

    bool operator>=(const position &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const position &position1);
};

class Ship {
private:
    int hp;
    const std::string name;
    struct position pos;
    struct position direction;
    const int size;
    const int type;

public:

    Ship();

    Ship(const std::string &name, int size, int type);

    int getHp() const;

    void attack();
    bool isDead();
    const std::string &getName() const;

    position getPos();

    const int getSize() const;

    const position &getDirection() const;

    const int getType() const;

    void setPos(char map[8][8]);

    friend std::ostream &operator<<(std::ostream &os, const Ship &ship);


};


#endif //CPP_BATTLESHIP_GAME_SHIP_H

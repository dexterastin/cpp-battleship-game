//
// C++ BattleShip Project
// 작성 일자 : 2018.06.01
// 20171648 양기현
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
    std::string name;
    struct position pos;
    struct position direction;
    int type;
protected:
    int size;

public:

    Ship();

    Ship(const char *name, int size, int type);

    virtual ~Ship();

    void attack();

    bool isDead();

    position getPos();

    const position &getDirection() const;

    virtual int getSize() const = 0;

    int getType() const;

    void setPos(char map[8][8]);

    friend std::ostream &operator<<(std::ostream &os, const Ship &ship);

};


#endif //CPP_BATTLESHIP_GAME_SHIP_H

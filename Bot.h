//
// C++ BattleShip Project
// 작성 일자 : 2018.06.03
// 20171648 양기현
//

#ifndef CPP_BATTLESHIP_GAME_BOT_H
#define CPP_BATTLESHIP_GAME_BOT_H


class Bot {
private:
    bool **visited;
    int mapsize;

public:
    Bot(int mapsize);

    ~Bot();

    bool isVisitedAt(int x, int y);

    void setAt(int x, int y);

    virtual int command();
};


#endif //CPP_BATTLESHIP_GAME_BOT_H

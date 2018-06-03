//
// Created by Gihyeon Yang on 2018. 6. 3..
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

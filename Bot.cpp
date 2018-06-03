//
// C++ BattleShip Project
// 작성 일자 : 2018.06.03
// 20171648 양기현
//

#include <iostream>
#include "Bot.h"

Bot::Bot(int mapsize) {
    this->mapsize = mapsize;
    this->visited = new bool *[mapsize];
    for (int i = 0; i < mapsize; ++i) {
        this->visited[i] = new bool[mapsize]();
    }
}

Bot::~Bot() {
    for (int i = 0; i < this->mapsize; ++i) {
        delete[] this->visited[i];
    }
    delete[] this->visited;
}

bool Bot::isVisitedAt(int x, int y) {
    return this->visited[x][y];
}

void Bot::setAt(int x, int y) {
    this->visited[x][y] = true;
}

int Bot::command() {
    return 0;
}

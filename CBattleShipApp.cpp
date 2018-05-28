//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include "CBattleShipApp.h"

CBattleShipApp::CBattleShipApp() {

}

CBattleShipApp::~CBattleShipApp() {

}

void CBattleShipApp::play() {
    this->init();
    this->render();
    this->destroy();
}

void CBattleShipApp::init() {
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    this->cBattleShipMap = new CBattleShipMap();
    this->statPane = new StatPane(30, 3, 30, 6);
    this->inputPane = new InputPane(30, 15, 30, 4);
}

void CBattleShipApp::render() {
    mvprintw(1, 1, "<< Battle Ship Game >>");

    this->cBattleShipMap->draw();
    this->statPane->draw();
    this->inputPane->draw();

    refresh();
}

void CBattleShipApp::destroy() {
    getch();
    endwin();
    delete this->cBattleShipMap;
}

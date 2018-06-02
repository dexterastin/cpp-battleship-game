//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include <iostream>
#include "CBattleShipApp.h"
#include "GameManager.h"

CBattleShipApp::CBattleShipApp() {

}

CBattleShipApp::~CBattleShipApp() {
    delete this->cBattleShipMap;
    delete this->inputPane;
    delete this->statPane;
}

void CBattleShipApp::play() {
    this->init();
    this->render();
    this->destroy();

    GameManager gameManager;
    gameManager.init();

}

void CBattleShipApp::init() {
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    this->cBattleShipMap = new CBattleShipMap(10);
    this->statPane = new StatPane(30, 3, 30, 7);
    this->inputPane = new InputPane(30, 15, 30, 4);
}

void CBattleShipApp::render() {
    mvprintw(1, 1, "<< Battle Ship Game >>");

    this->cBattleShipMap->draw();
    this->statPane->draw();
    this->inputPane->draw();

    refresh();
}

void CBattleShipApp::update() {

}


void CBattleShipApp::destroy() {
    getch();
    endwin();
    delete this->cBattleShipMap;
}


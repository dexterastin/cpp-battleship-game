//
// Created by Gihyeon Yang on 2018. 5. 28..
//

#include "CBattleShipApp.h"

CBattleShipApp::CBattleShipApp() {

}

CBattleShipApp::~CBattleShipApp() {
    delete this->inputPane;
    delete this->statPane;
    delete this->gameManager;
}

int CBattleShipApp::play() {
    this->init();
    this->render();

    while (!gameManager->isDeadAllShip()) {
        gameManager->addTurn();
        gameManager->attack();
        this->update();
    }

    int rTurn = gameManager->getTurn();

    this->destroy();

    return rTurn;
}

void CBattleShipApp::init() {
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    this->gameManager = new GameManager(
            new Player(1),
            new Player(0),
            new InputPane(30, 15, 30, 4)
    );

    this->gameManager->init();

    this->statPane = new StatPane(30, 3, 30, 7);
    this->inputPane = this->gameManager->getInputPane();
}

void CBattleShipApp::render() {
    mvprintw(1, 1, "<< Battle Ship Game >>");

    this->gameManager->render();
    this->statPane->draw(
            this->gameManager->getTurn()
    );
    this->inputPane->draw();

    refresh();
}

void CBattleShipApp::update() {
    this->render();
}


void CBattleShipApp::destroy() {
    getch();
    endwin();
}


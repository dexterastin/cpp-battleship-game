//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#include <iostream>
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

    std::cout << "===== FINAL TURN : " << rTurn << "\t=====" << std::endl;
    std::cout << "Press Enter...\n";
    int i = getch();

    this->destroy();

    return rTurn;
}

void CBattleShipApp::init() {
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLUE);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);

    this->gameManager = new GameManager(
            new Player(1),
            new Player(0),
            new InputPane(30, 15, 30, 4)
    );

    this->gameManager->init();

    this->statPane = new StatPane(30, 3, 30, 7);
}

void CBattleShipApp::render() {
    mvprintw(1, 1, "<< Battle Ship Game >>");

    this->gameManager->render();
    this->statPane->draw();
    this->gameManager->getInputPane()->draw();

    refresh();
}

void CBattleShipApp::update() {
    this->gameManager->render();
    this->gameManager->getInputPane()->draw();
    this->statPane->update(
            gameManager->getTurn()
    );
    refresh();
}


void CBattleShipApp::destroy() {
    getch();
    endwin();
}


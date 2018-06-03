//
// C++ BattleShip Project
// 작성 일자 : 2018.06.02
// 20171648 양기현
//

#include "GameManager.h"

GameManager::GameManager(Player *attacker, Player *defender, InputPane *inputPane) {
    this->setAttacker(attacker);
    this->setDefender(defender);
    this->setInputPane(inputPane);

    this->numOfShip[0] = AIRCRAFT;
    this->numOfShip[1] = BATTLESHIP;
    this->numOfShip[2] = CRUISER;
    this->numOfShip[3] = DESTROYER;

    this->ship = nullptr;

    switch (BOT) {
        case 0:
            this->bot = nullptr;
            break;
        case 1:
            this->bot = new BattleShipRndBot(MAP_SIZE);
            break;
        case 2:
            this->bot = new BattleShipAIBot(MAP_SIZE);
            break;
        default:
            this->bot = nullptr;
            break;
    }

}

GameManager::~GameManager() {
    delete this->attacker;
    delete this->defender;
    delete this->inputPane;
    delete this->bot;

    this->ship = new Ship **[SHIP_TYPE];

    for (int type = 0; type < SHIP_TYPE; ++type) {
        this->ship[type] = new Ship *[this->numOfShip[type]];
        for (int n = 0; n < this->numOfShip[type]; ++n) {
            delete[] ship[type][n];
        }
        delete[] ship[type];
    }

    delete[] ship;
}


void GameManager::init() {
    this->generateShip();

    this->attacker->init();
    this->defender->init();

    for (int type = 0; type < SHIP_TYPE; ++type) {
        for (int i = 0; i < this->numOfShip[type]; ++i) {
            this->defender->setupShip(this->ship[type][i]);
        }
    }
}

void GameManager::addTurn() {
    this->turn += 1;
}


void GameManager::generateShip() {
    this->ship = new Ship **[sizeof(this->numOfShip) / sizeof(*this->numOfShip)];

    for (int type = 0; type < sizeof(this->numOfShip) / sizeof(*this->numOfShip); ++type) {

        this->ship[type] = new Ship *[this->numOfShip[type]];

        for (int n = 0; n < this->numOfShip[type]; ++n) {
            switch (type) {
                case 0:
                    this->ship[type][n] = new SAirCraft();
                    break;
                case 1:
                    this->ship[type][n] = new SBattleShip();
                    break;
                case 2:
                    this->ship[type][n] = new SCruiser();
                    break;
                case 3:
                    this->ship[type][n] = new SDestroyer();
                    break;
                default:
                    break;
            }
        }
    }
}


int GameManager::getTurn() const {
    return turn;
}


void GameManager::setAttacker(Player *attacker) {
    GameManager::attacker = attacker;
}

void GameManager::setDefender(Player *defender) {
    GameManager::defender = defender;
}

void GameManager::render() {
    this->attacker->render();
    this->defender->render();
}

bool GameManager::isDeadAllShip() {
    bool rBool = false;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < this->numOfShip[i]; ++j) {
            rBool |= !this->ship[i][j]->isDead();
        }
    }

    return !rBool;
}

InputPane *GameManager::getInputPane() const {
    return inputPane;
}

void GameManager::setInputPane(InputPane *inputPane) {
    GameManager::inputPane = inputPane;
}


void GameManager::attack() {
    int rowInput = ((BOT != 0) ? this->bot->command() : this->inputPane->input());
    struct position attackPos = {
            rowInput / 10,
            rowInput % 10
    };

    Ship *findShip = this->attackShip(attackPos);
    if (findShip != nullptr) {
        findShip->attack();

        this->attacker->setHitResult(
                attackPos,
                ((findShip->isDead()) ? findShip : nullptr)
        );

        this->defender->setHitResult(attackPos);
    }

}

Ship *GameManager::attackShip(struct position attackPos) {
    Ship *findShip = nullptr;

    struct position shipPos[2] = {
            position{},
    };

    if (this->defender->at(attackPos) == '_' || this->defender->at(attackPos) == 'X') {
        return nullptr;
    }

    for (int type = 0; type < SHIP_TYPE; ++type) {
        for (int i = 0; i < this->numOfShip[type]; ++i) {
            shipPos[0] = this->ship[type][i]->getPos();
            shipPos[1] = this->ship[type][i]->getPos() +
                         this->ship[type][i]->getDirection() * (this->ship[type][i]->getSize() - 1);
            if (
                    (shipPos[0].x <= attackPos.x && attackPos.x <= shipPos[1].x &&
                     shipPos[0].y <= attackPos.y && attackPos.y <= shipPos[1].y) ||

                    (shipPos[1].x <= attackPos.x && attackPos.x <= shipPos[0].x &&
                     shipPos[1].y <= attackPos.y && attackPos.y <= shipPos[0].y)
                    ) {
                findShip = this->ship[type][i];
                break;
            }
        }
    }

    return findShip;
}

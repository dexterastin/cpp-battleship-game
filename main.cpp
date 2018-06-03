#include <iostream>
#include <cstdlib>
#include <ctime>
#include "CBattleShipApp.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    CBattleShipApp *app;

    int total = 0;
    int size = 10;
    for (int i = 0; i < size; ++i) {
        app = new CBattleShipApp();
        total += app->play();
        delete app;
    }

    std::cout << total / size << std::endl;

    return 0;
}
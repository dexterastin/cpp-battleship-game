#include <iostream>
#include "CBattleShipApp.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    CBattleShipApp app;
    app.play();
    return 0;
}
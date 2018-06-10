//
// C++ BattleShip Project
// 작성 일자 : 2018.05.28
// 20171648 양기현
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "CBattleShipApp.h"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    CBattleShipApp app;
    int result = app.play();

//    std::cout << "===== FINAL TURN : " << result << "\t=====" << std::endl;

    return 0;
}

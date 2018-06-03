cmake_minimum_required(VERSION 3.9)
project(cpp_battleship_game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(
        cpp_battleship_game
        main.cpp
        Pane.cpp
        Pane.h
        CBattleShipMap.cpp
        CBattleShipMap.h
        StatPane.cpp
        StatPane.h
        InputPane.cpp
        InputPane.h
        CBattleShipApp.cpp
        CBattleShipApp.h
        Ship/Ship.cpp
        Ship/Ship.h
        Ship/SBattleShip.h
        Ship/SAirCraft.h
        Ship/SCruiser.h
        Ship/SDestroyer.h
        Player.cpp
        Player.h
        ShipHeader.h
        GameManager.cpp
        GameManager.h
        BattleShipAIBot.h
        BattleShipAIBot.cpp
        BattleShipRndBot.h
        BattleShipRndBot.cpp
        Bot.cpp
        Bot.h
        BotHeader.h
)
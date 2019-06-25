cmake_minimum_required(VERSION 3.14)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BattleShip
        AiPlayer.cpp
        AiPlayer.h
        BattleShip.cpp
        BattleShip.h
        Board.cpp
        Board.h
        CheatingAI.cpp
        CheatingAI.h
        GameAttributes.cpp
        GameAttributes.h
        HumanPlayer.cpp
        HumanPlayer.h
        HuntAndDestroyAI.cpp
        HuntAndDestroyAI.h
        main.cpp
        Player.cpp
        Player.h
        RandomAI.cpp
        RandomAI.h
        Ship.cpp
        Ship.h
        ShipPlacement.cpp
        ShipPlacement.h
        Utility.cpp
        Utility.h
        )

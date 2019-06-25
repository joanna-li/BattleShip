//
// Created by Joanna on 2019-06-04.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H

#include <vector>
#include <string>
#include <random>
#include "Ship.h"
#include "ShipPlacement.h"

namespace BattleShip {
    class Board{
      public:
        using iterator = std::vector<std::string>::iterator;
        using const_iterator = std::vector<std::string>::const_iterator;

        Board (int row, int col, char blankSpace);
//        virtual ~Board() = default;
        int getRowSize() const;
        int getColSize() const;
        char getAttackChar() const;
        void display();

        bool inBounds(int row, int col) const;
        bool isBlankSpace(int row, int col) const;
        void set(int row, int col, char val);
        bool canPlaceShipAt(ShipPlacement placement) const;
        void AddShip(Ship ship, ShipPlacement placement);
        bool isSpaceAttacked(int row, int col) const;
        bool isSpaceMissed(int row, int col) const;
        std::vector<char> addAttack(int row, int col);
        std::vector<int> getFirstTargetPoint();
//        std::vector<int> getFirstTopDownPoint();
//        std::vector<int> getNearbyPoint(int row, int col);
        void displayHiddenShipBoard();

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        const char& at(int row, int col) const;
        static bool isBetween(int val, int lower, int upper);

      private:
        std::vector<std::string> boardState;
        const char blankSpace;
        const char attackedSpace = 'X';
        const char missedSpace = 'O';
//        static std::mt19937 randomNumberGenerator;

    };
}
#endif //BATTLESHIP_BOARD_H

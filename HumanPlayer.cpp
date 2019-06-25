//
// Created by Joanna on 2019-06-05.
//
#include <iostream>
#include <sstream>
#include <string>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Ship.h"

using namespace std;

int BattleShip::HumanPlayer::nextHumanId = 1;

BattleShip::HumanPlayer::HumanPlayer(BattleShip::GameAttributes& gameAttributes, BattleShip::Board& board,
    std::vector<BattleShip::Ship>& ships, std::string playerTyp) :
    Player(gameAttributes, board, ships, playerTyp), humanId(HumanPlayer::nextHumanId) {
  nextHumanId++;
}

void BattleShip::HumanPlayer::placeShips() {
  std::vector<char> orientation_choice{'h', 'v'};

  ShipPlacement placement;
  std::vector<Ship> shipHealths = gameAttributes.getShips();
  int numShip = gameAttributes.getNumShips();

  for(auto& ship : shipHealths) { // shipHealths, second == size ?
    do {
      char orientation;
      do {
        std::cout << name << ", do you want to place " << ship.getSymbol()
                  << " horizontally or vertically?" << endl;
        std::cout << "Enter h for horizontal or v for vertical" << endl;
        std::cin >> orientation;
        std::string extra;
        std::getline(std::cin, extra);
      } while (!BattleShip::HumanPlayer::validOrientation(orientation));

      do {
        std::cout << "Your choice: " << name << ", enter the row and column you want to place "
                  << ship.getSymbol() << ", which is " << ship.getSize()
                  << " long, at with a space in between row and col: ";
        std::cin >> placement.rowStart >> placement.colStart;
        std::string extra;
        std::getline(std::cin, extra);
      } while (!BattleShip::HumanPlayer::validRowCol(placement.rowStart, placement.colStart));

      if (orientation == 'h') {
        placement.rowEnd = placement.rowStart;
        placement.colEnd = placement.colStart + ship.getSize()- 1;
      } else {
        placement.rowEnd = placement.rowStart + ship.getSize() - 1;
        placement.colEnd = placement.colStart;
      }
    } while(!board.canPlaceShipAt(placement));

    board.AddShip(ship, placement);
    board.display();

    numShip--;
    if (numShip == 0){
      break;
    }
  }

}

std::vector<char> BattleShip::HumanPlayer::addAttack(std::vector<int> point) {
  return board.addAttack(point[0], point[1]);
}

void BattleShip::HumanPlayer::initializeName() {
    do {
      std::cout << (humanId % 2 == 1 ? "Your choice: " : "")  << "Player " << humanId
                << " please enter your name: ";
      std::cin >> name;
      std::string extra;
      std::getline(std::cin, extra);
    } while (!BattleShip::HumanPlayer::validName(name));

    previousName = name;
}

bool BattleShip::HumanPlayer::validOrientation(char orientation) {
  return orientation == 'v' || orientation == 'h';
}

bool BattleShip::HumanPlayer::validRowCol(int row, int col) {
  return board.inBounds(row, col);
}


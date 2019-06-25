//
// Created by mfbut on 3/9/2019.
//
#include <sstream>
#include <ctime>
#include "Utility.h"
#include "AiPlayer.h"
#include "ShipPlacement.h"
#include "Ship.h"

int BattleShip::AiPlayer::nextAiId = 1;
//std::mt19937 BattleShip::AiPlayer::randomNumberGenerator((time(nullptr)));


BattleShip::AiPlayer::AiPlayer(BattleShip::GameAttributes& gameAttributes, BattleShip::Board& board,
    std::vector<BattleShip::Ship>& ships, std::string playerType) :
    Player(gameAttributes, board, ships, playerType), aiId(AiPlayer::nextAiId) {

      nextAiId++;

}

void BattleShip::AiPlayer::placeShips() {
  std::vector<char> orientation_choice{'h', 'v'};
  const int numRows = board.getRowSize();
  const int numCols = board.getColSize();
  int count = 0;

  ShipPlacement placement;
  for(auto& ship : gameAttributes.getShips()) {

    do {
      char orientation = *chooseRandom(orientation_choice, randomNumberGenerator);
      if (orientation == 'h') {
        placement.rowStart = getRandInt(0, numRows - 1, randomNumberGenerator);
        placement.colStart = getRandInt(0, numCols - ship.getSize(), randomNumberGenerator);
        placement.rowEnd = placement.rowStart;
        placement.colEnd = placement.colStart + ship.getSize()- 1;
      } else {
        placement.rowStart = getRandInt(0, numRows - ship.getSize(), randomNumberGenerator);
        placement.colStart = getRandInt(0, numCols - 1, randomNumberGenerator);
        placement.rowEnd = placement.rowStart + ship.getSize() - 1;
        placement.colEnd = placement.colStart;
      }
    }while(!board.canPlaceShipAt(placement));

    board.AddShip(ship, placement);

    std::cout << (count == 0? "Your choice: " : "") << getName() << "'s Board" << std::endl;
    board.display();
    std::cout << std::endl;
    count++;
  }
}

void BattleShip::AiPlayer::initializeName() {
  std::stringstream name;
  name << "AI " << aiId;
  setName(name.str());
}

//void BattleShip::AiPlayer::seed_random_number_generator(int seed) {
//  BattleShip::AiPlayer::randomNumberGenerator.seed(seed);
//}

void BattleShip::AiPlayer::setName(std::string playerName) {
  name = playerName;
}




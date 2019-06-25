//
// Created by Joanna on 2019-06-05.
//

#include "RandomAI.h"
#include <random>
#include <sstream>
#include <ctime>
#include "Utility.h"
#include "AiPlayer.h"
#include "Player.h"
#include "ShipPlacement.h"
#include "Ship.h"

BattleShip::RandomAI::RandomAI(BattleShip::GameAttributes& gameAttributes, BattleShip::Board& board,
    std::vector<BattleShip::Ship>& ships, std::string playerTyp) :
    AiPlayer(gameAttributes, board, ships, playerTyp) {

}

std::vector<std::vector<int>> BattleShip::RandomAI::getFiringLocations(Player& opponentPlayer) {
//  int rows = opponentPlayer.getGameAttributes().getRow();
//  int cols = opponentPlayer.getGameAttributes().getCol();
//
//  // start from 0 0 till m n
//  for (int i=0; i<rows; ++i) {
//
//      for (int j=0; j<cols; ++j) {
//        firingLocations.push_back({i, j});
//      }
//
//  }

  return firingLocations;
}
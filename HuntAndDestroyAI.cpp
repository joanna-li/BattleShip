//
// Created by Joanna on 2019-06-05.
//

#include "HuntAndDestroyAI.h"
#include <sstream>
#include <ctime>
#include "Utility.h"
#include "AiPlayer.h"
#include "ShipPlacement.h"
#include "Ship.h"

BattleShip::HuntAndDestroyAI::HuntAndDestroyAI(BattleShip::GameAttributes& gameAttributes,
    BattleShip::Board& board, std::vector<BattleShip::Ship>& ships, std::string playerTyp) :
    AiPlayer(gameAttributes, board, ships, playerTyp) {

}

// enum nextShot { LEFT, RIGHT, UP, DOWN };
std::vector<int> BattleShip::HuntAndDestroyAI::getNearbyPoint(int row, int col) {
  int row2=0, col2=0;
  int left=0, up=0, right=0, down=0;

//  if (left == 0) { // left
//    col2 = col - 1;
//    col2 = col;
//    left += 1;
//    if (!inBounds(row, col2) || isSpaceMissed(row, col2) || isSpaceAttacked(row, col2)) {
//      if (up == 0) {
//        row2 = row -1;
//        col2 = col;
//        up += 1;
//        if (!inBounds(row2, col) || isSpaceMissed(row2, col) || isSpaceAttacked(row2, col)) {
//          if (right == 0) {
//            col2 = col + 1;
//            row2 =row;
//            right += 1;
//            if (!inBounds(row, col2) || isSpaceMissed(row, col2) || isSpaceAttacked(row, col2)) {
//              if (down == 0) {
//                row2 = row + 1;
//                col2 = col;
//                down += 1;
//                if (!inBounds(row2, col) || isSpaceMissed(row2, col) || isSpaceAttacked(row2, col)) {
//                  return {-1, -1};
//                }
//              } // down
//            }
//          } // right
//        }
//      } // up
//    }
//  } // left

  return {row2, col2};
}

std::vector<std::vector<int>> BattleShip::HuntAndDestroyAI::getFiringLocations(Player& opponentPlayer) {
//  int rows = opponentPlayer.getGameAttributes().getRow();
//  int cols = opponentPlayer.getGameAttributes().getCol();
//
//  // start from 0 0 till m n
//  for (int i=0; i<rows; ++i) {
//
//    for (int j=0; j<cols; ++j) {
//      firingLocations.push_back({i, j});
//    }
//
//  }

  return firingLocations;
}
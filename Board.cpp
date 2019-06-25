//
// Created by Joanna on 2019-06-04.
//

#include <iostream>
#include <ctime>
#include "Utility.h"
#include "Board.h"
#include "Ship.h"
#include "ShipPlacement.h"

//std::mt19937 BattleShip::Board::randomNumberGenerator((time(nullptr)));

BattleShip::Board::Board(int row, int col, char blankSpace) :
    boardState(row, std::string(col, blankSpace)),
    blankSpace(blankSpace) {

}

int BattleShip::Board::getRowSize() const {
  // find length of vector
  return boardState.size();
}

int BattleShip::Board::getColSize() const {
  // find length of string inside vector
  return boardState.at(0).length();
}

char BattleShip::Board::getAttackChar() const {
  return attackedSpace;
}

void BattleShip::Board::display() {
  //print column headers
  int colSize = getColSize();
  std::cout << "  ";
  for (int i = 0; i < colSize; ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  // change to top down for rows
  int rowIndex = 0;
  for (const auto& row : boardState) {
    std::cout << rowIndex << ' ';
    for(const auto& elem : row){
      std::cout << elem << ' ';
    }
    rowIndex++;
    std::cout << std::endl;
  }
}

void BattleShip::Board::displayHiddenShipBoard() {
  int colSize = getColSize();

  std::cout << "  ";
  for (int i = 0; i < colSize; ++i) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;

  // change to top down for rows
  int rowIndex = 0;
  for (const auto& row : boardState) {
    std::cout << rowIndex << ' ';
    for(const auto& elem : row){
      if(elem == attackedSpace || elem == missedSpace || elem == blankSpace) {
        std::cout << elem << ' ';
      } else {
        std::cout << blankSpace << ' ';
      }
    }
    rowIndex++;
    std::cout << std::endl;
  }

}

// checking for valid column number from user input
bool BattleShip::Board::inBounds(int row, int col) const {
  return isBetween(row, 0, getRowSize() - 1) &&
      isBetween(col, 0, getColSize() - 1);
}

bool BattleShip::Board::isBetween(int val, int lower, int upper) {
  return val >= lower && val <= upper;
}

bool BattleShip::Board::isBlankSpace(int row, int col) const {
  return boardState.at(row).at(col) == blankSpace;
}

bool BattleShip::Board::isSpaceAttacked(int row, int col) const {
  return boardState.at(row).at(col) == attackedSpace;
}

bool BattleShip::Board::isSpaceMissed(int row, int col) const {
  return boardState.at(row).at(col) == missedSpace;
}

void BattleShip::Board::set(int row, int col, char val) {
  boardState.at(row).at(col) = val;
}

bool BattleShip::Board::canPlaceShipAt(ShipPlacement placement) const {
  bool isInBounds = inBounds(placement.rowStart, placement.rowEnd) &&
          inBounds(placement.colStart, placement.colEnd);

  if (!isInBounds){
    return false;
  }

  bool isSpaceAvailable = true;

  if (placement.rowStart == placement.rowEnd) { // h
    for (int i = placement.colStart; i < placement.colEnd; ++i) {
      if (!isBlankSpace(placement.rowStart, i)) {
        isSpaceAvailable = false;
      }
    }
  } else { // v
    for (int i = placement.rowStart; i < placement.rowEnd; ++i) {
      if (!isBlankSpace(i, placement.colStart)) {
        isSpaceAvailable = false;
      }
    }
  }

  return isInBounds && isSpaceAvailable;
}

void BattleShip::Board::AddShip(Ship ship, ShipPlacement placement) {
  char mySymbol = ship.getSymbol();
  int myShipSize = ship.getSize();
  for (int i = 0; i < myShipSize; ++i) {
    if (placement.rowStart == placement.rowEnd) { // h
      set(placement.rowStart, placement.colStart + i, mySymbol);
    } else { // v
      set(placement.rowStart + i, placement.colStart, mySymbol);
    }
  }
}

std::vector<char> BattleShip::Board::addAttack(int row, int col) {
  char isHit;
  char shipChar = at(row, col);
  if (!isBlankSpace(row, col) && !isSpaceMissed(row, col)) {
    set(row, col, attackedSpace);
    isHit = '+';
  } else { // mark to missedSpace
    set(row, col, missedSpace);
    isHit = '-';
  }
  return {isHit, shipChar};
}

std::vector<int> BattleShip::Board::getFirstTargetPoint() { // for cheating AI
  int rows = getRowSize();
  int cols = getColSize();

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if(!isBlankSpace(row, col) && !isSpaceAttacked(row, col) && !isSpaceMissed(row, col)){
        return {row, col};
      }
    }
  }

  return {-1, -1};
}

//std::vector<int> BattleShip::Board::getFirstTopDownPoint() { // random pick
//  int rows = getRowSize();
//  int cols = getColSize();
//  int row, col;
//
//  do {
//    row = getRandInt(0, rows - 1, randomNumberGenerator);
//    col = getRandInt(0, cols - 1, randomNumberGenerator);
//  } while (isSpaceMissed(row, col) || isSpaceAttacked(row, col));
//
//  return {row, col};
//}

// enum nextShot { LEFT, RIGHT, UP, DOWN };
//std::vector<int> BattleShip::Board::getNearbyPoint(int row, int col) { // for HD AI
//  int row2=0, col2=0;
//  int left=0, up=0, right=0, down=0;
//  return {row2, col2};
//}

BattleShip::Board::iterator BattleShip::Board::begin() {
  return boardState.begin();
}

BattleShip::Board::iterator BattleShip::Board::end() {
  return boardState.end();
}

BattleShip::Board::const_iterator BattleShip::Board::cbegin() const {
  return boardState.cbegin();
}

BattleShip::Board::const_iterator BattleShip::Board::cend() const {
  return  boardState.cend();
}

const char& BattleShip::Board::at(int row, int col) const {
  return boardState.at(row).at(col);
}

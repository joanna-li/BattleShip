//
// Created by Joanna on 2019-06-05.
//

#include <string>
#include "Ship.h"
#include "ShipPlacement.h"

BattleShip::Ship::Ship (char symbol, int size) :
  symbol(symbol),  size(size) {

}

char BattleShip::Ship::getSymbol() const {
  return symbol;
}
int BattleShip::Ship::getSize() const {
  return size;
}

int BattleShip::Ship::getHits() {
  return hits;
}

void BattleShip::Ship::updateHits() {
  hits += 1;
}

BattleShip::ShipPlacement BattleShip::Ship::getPlacement() {
  return placement;
}

void BattleShip::Ship::updatePlacement(int rowStart, int colStart, int rowEnd, int colEnd) {
  placement.rowStart = rowStart;
  placement.colStart = colStart;
  placement.rowEnd = rowEnd;
  placement.colEnd = colEnd;
}
//
// Created by Joanna on 2019-06-06.
//

#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes (std::vector<std::string> configAttributes) {
  struct {
    bool operator()(Ship& a, Ship& b) const {
      return a.getSymbol() < b.getSymbol();
    }
  } customLess;

  int len = configAttributes.size();
  row = stoi(configAttributes[0]);
  col = stoi(configAttributes[1]);
  numShips = stoi(configAttributes[2]);
  seed = stoi(configAttributes[len-1]);

  for (int i = 3; i< len - 1; i++){ // ship's symbol and size B 5
    std::vector<std::string> results;  // {B, 5}
    std::stringstream s(configAttributes[i]);
    while(!s.eof()) {
      std::string tmp;
      s >> tmp;
      results.push_back(tmp);
    }
    char symbol = results[0].at(0);
    int size = stoi(results[1]);
    std::vector<int> positions(size, 0);
    Ship myShip(symbol, size);
    ships.push_back(myShip);
  }

  std::sort(ships.begin(), ships.end(), customLess);

}

int BattleShip::GameAttributes::getRow() {
  return row;
}

int BattleShip::GameAttributes::getCol() {
  return col;
}

int BattleShip::GameAttributes::getNumShips() {
  return numShips;
}

std::vector<BattleShip::Ship> BattleShip::GameAttributes::getShips() {
  return ships;
}

int BattleShip::GameAttributes::getSeed() {
  return seed;
}
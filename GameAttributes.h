//
// Created by Joanna on 2019-06-06.
//

#ifndef BATTLESHIP_GAMEATTRIBUTES_H
#define BATTLESHIP_GAMEATTRIBUTES_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Ship.h"

namespace BattleShip {

  class GameAttributes {
    public:
      explicit GameAttributes(std::vector<std::string> configAttributes);
      virtual ~GameAttributes() = default;

      int getRow();
      int getCol();
      int getNumShips();
      std::vector<Ship> getShips();
      int getSeed();

    private:
      int row;
      int col;
      int numShips;
      std::vector<Ship> ships;
      int seed;

  };

}

#endif //BATTLESHIP_GAMEATTRIBUTES_H

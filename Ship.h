//
// Created by Joanna on 2019-06-05.
//

#ifndef BATTLESHIP_SHIPS_H
#define BATTLESHIP_SHIPS_H

#include <string>
#include <vector>
#include "ShipPlacement.h"

namespace BattleShip {

  class Ship {
    public:
      Ship(char symbol, int size);
      virtual ~Ship() = default;
      char getSymbol() const;
      int getSize() const;
      int getHits();
      void updateHits();
      ShipPlacement getPlacement();
      void updatePlacement(int rowStart, int colStart, int rowEnd, int colEnd);

    private:
      char symbol;
      int size;
      int hits = 0;
      ShipPlacement placement;

  };

}

#endif //BATTLESHIP_SHIPS_H

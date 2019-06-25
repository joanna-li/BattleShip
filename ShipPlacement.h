//
// Created by Joanna on 2019-06-08.
//

#ifndef BATTLESHIP_SHIPPLACEMENT_H
#define BATTLESHIP_SHIPPLACEMENT_H

namespace BattleShip {

  class ShipPlacement {
    public:
      ShipPlacement(int rowStart=0, int colStart=0, int rowEnd=0, int colEnd=0);
      int rowStart;
      int colStart;
      int rowEnd;
      int colEnd;

  };

}

#endif //BATTLESHIP_SHIPPLACEMENT_H

//
// Created by Joanna on 2019-06-05.
//

#ifndef BATTLESHIP_HUNTANDDESTROYAI_H
#define BATTLESHIP_HUNTANDDESTROYAI_H

#include <random>
#include <string>
#include <vector>
#include "AiPlayer.h"
#include "GameAttributes.h"
#include "Ship.h"

namespace BattleShip {

  class Move;

  class HuntAndDestroyAI : public AiPlayer {

  public:
    HuntAndDestroyAI(GameAttributes& gameAttributes, Board& board,
        std::vector<Ship>& ships, std::string playerType);
    virtual std::vector<std::vector<int>> getFiringLocations(Player& opponentPlayer) override;

    std::vector<int> getNearbyPoint(int row, int col);

  private:
    int hdMode;

  };
}

#endif //BATTLESHIP_HUNTANDDESTROYAI_H

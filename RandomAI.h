//
// Created by Joanna on 2019-06-05.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H

#include <random>
#include <string>
#include <vector>
#include "AiPlayer.h"
#include "Player.h"
#include "GameAttributes.h"
#include "Ship.h"

namespace BattleShip {

    class Move;

    class RandomAI : public AiPlayer {

      public:
        RandomAI(GameAttributes& gameAttributes, Board& board,
                 std::vector<Ship>& ships, std::string playerType);
        virtual std::vector<std::vector<int>> getFiringLocations(Player& opponentPlayer) override;

      private:

    };
}

#endif //BATTLESHIP_RANDOMAI_H

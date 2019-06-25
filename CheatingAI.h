//
// Created by Joanna on 2019-06-05.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H

#include <random>
#include <string>
#include <vector>
#include "GameAttributes.h"
#include "AiPlayer.h"
#include "Ship.h"

namespace BattleShip {

    class Move;

    class CheatingAI : public AiPlayer {

      public:
        CheatingAI(GameAttributes& gameAttributes, Board& board,
            std::vector<Ship>& ships, std::string playerType);
        virtual std::vector<std::vector<int>> getFiringLocations(Player& opponentPlayer) override;

      private:
         //std::vector<std::vector<int>> firingLocations;

    };
}

#endif //BATTLESHIP_CHEATINGAI_H

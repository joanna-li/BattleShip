//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_AIPLAYER_H
#define BATTLESHIP_AIPLAYER_H
#include <random>
#include <string>
#include "Player.h"
#include "GameAttributes.h"
#include "Board.h"
#include "Ship.h"

namespace BattleShip {

    class Move;

    class AiPlayer : public Player {
         public:
          AiPlayer(GameAttributes& gameAttributes, Board& board,
              std::vector<Ship>& ships, std::string playerType);
//          static void seed_random_number_generator(int seed);
          virtual void placeShips() override;
          virtual void initializeName() override;
          virtual void setName(std::string playerName) override;

//        protected:
//          static std::mt19937 randomNumberGenerator;

        private:
          static int nextAiId;
          const int aiId;
  };

}
#endif //BATTLESHIP_AIPLAYER_H

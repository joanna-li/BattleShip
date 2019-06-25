//
// Created by Joanna on 2019-06-05.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H

#include <string>
#include <vector>
#include "Board.h"
#include "Player.h"
#include "GameAttributes.h"
#include "Ship.h"

namespace BattleShip {

    class Move;

    class HumanPlayer : public Player {

      public:
          HumanPlayer(GameAttributes& gameAttributes, Board& board,
              std::vector<Ship>& ships, std::string playerType);
          virtual void placeShips() override;
          virtual std::vector<char> addAttack(std::vector<int> point) override;
          virtual void initializeName() override;
          virtual bool validOrientation(char orientation);
          virtual bool validRowCol(int row, int col);

      private:
          static int nextHumanId;
          const int humanId;

    };
}

#endif //BATTLESHIP_HUMANPLAYER_H

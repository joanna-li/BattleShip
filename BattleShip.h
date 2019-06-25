//
// Created by Joanna on 2019-06-04.
//

#ifndef BATTLESHIP_BATTLESHIP_H
#define BATTLESHIP_BATTLESHIP_H
#include <string>
#include <vector>
#include "Board.h"
#include "GameAttributes.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntAndDestroyAI.h"
#include "Ship.h"

using namespace std;

namespace BattleShip {

  class GameAttributes;
  class Player;

  class BattleShip {
    public:
      BattleShip(GameAttributes& gameAttributes);
      virtual ~BattleShip() = default;

      void play(Player& p1, Player& p2, Board& b1, Board& b2, std::vector<Ship>& ships1, std::vector<Ship>& ships2);

      Player& getCurrentPlayer();

      void showBoards(Player& curPlayer, Player& oppPlayer);
      void showHitResult(char sHit, char sSymbol, std::string curPName, std::string oppPName);
      void shipDestroyedMsg(std::string curPName, std::string oppPName, char sHit, char sSymbol,
          std::vector<Ship>& ships2);

      bool isGameOver(Player& opponentPlayer);
      void changeTurn();
      void declareResults();

    private:
      std::vector<Player> players;
      GameAttributes gameAttributes;
      int playerTurn;
      std::vector<char> isHit;

  };
}

#endif //BATTLESHIP_BATTLESHIP_H

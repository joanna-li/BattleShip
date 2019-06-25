//
// Created by Joanna on 2019-06-04.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <string>
#include <vector>
#include <random>
#include "Board.h"
#include "GameAttributes.h"
#include "Ship.h"

namespace BattleShip {

  class Player {

    public:
      Player(GameAttributes& gameAttributes, Board& board,
          std::vector<Ship>& ships, std::string playerType);
      virtual ~Player() = default;
      virtual const std::string& getName() const;
      virtual void setName(std::string playerName);
      virtual bool validName(std::string name);
      virtual const std::string& getPlayerType() const;

      virtual Board getBoard();
      virtual const GameAttributes getGameAttributes() const;
      virtual void placeShips();
      virtual void initializeName();
      virtual std::vector<char>  addAttack(std::vector<int> point);
      virtual std::vector<int> getAttackPoint();
      virtual std::vector<int> getFirstTargetPoint();
//      virtual std::vector<int> getFirstTopDownPoint();
      virtual std::vector<int> getFirstTopDownPoint(Player& oppPlayer);

//      virtual std::vector<int> getNearbyPoint(int row, int col);
      virtual std::vector<Ship> getShips();
      virtual int getHits(Ship& ship);
      void updateHits(Ship& ship);
      char getSymbol(Ship& ship);
      int getSize(Ship& ship);

      virtual std::vector<std::vector<int>> getLocationsFired(Player& opponentPlayer);
      virtual void setLocationsFired(int row, int col);

      virtual std::vector<std::vector<int>> getFiringLocations(Player& opponentPlayer);
      virtual void setFiringLocations(int row, int col);

      static void seed_random_number_generator(int seed);

      static std::string previousName;

    protected:
      std::string name;
      std::string playerType;
      GameAttributes gameAttributes;
      Board board;
      std::vector<std::vector<int>> locationsFired;
      std::vector<std::vector<int>> firingLocations;
      int row;
      int col;
      std::vector<Ship> ships;

      static std::mt19937 randomNumberGenerator;

  };


}

#endif //BATTLESHIP_PLAYER_H

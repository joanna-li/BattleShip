//
// Created by Joanna on 2019-06-05.
//

#include "CheatingAI.h"
#include <string>
#include <sstream>
#include <ctime>
#include "Utility.h"
#include "GameAttributes.h"
#include "ShipPlacement.h"
#include "AiPlayer.h"
#include "Ship.h"


BattleShip::CheatingAI::CheatingAI(BattleShip::GameAttributes& gameAttributes, BattleShip::Board& board,
    std::vector<BattleShip::Ship>& ships, std::string playerType) :
    AiPlayer(gameAttributes, board, ships, playerType) {

}

std::vector<std::vector<int>> BattleShip::CheatingAI::getFiringLocations(Player& opponentPlayer) {

  return firingLocations;
}
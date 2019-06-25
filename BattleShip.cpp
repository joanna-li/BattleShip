//
// Created by Joanna on 2019-06-04.
//
#include "BattleShip.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "Board.h"
#include "GameAttributes.h"
#include "Ship.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntAndDestroyAI.h"

using namespace std;

BattleShip::BattleShip::BattleShip(GameAttributes& gameAttributes) :
    gameAttributes(gameAttributes), playerTurn(-1) {

}

void BattleShip::BattleShip::play(Player& p1, Player& p2, Board& b1, Board& b2,
    std::vector<Ship>& ships1, std::vector<Ship>& ships2) {
  playerTurn = 0;
  std::string curPName = "";
  std::string oppPName = "";
  std::vector<int> point;
  players.push_back(p1);
  players.push_back(p2);

  while (true) {
    point.clear();

    if (playerTurn == 0) { // check current player and board
      curPName = p1.getName();
      oppPName = p2.getName();

      if (p1.getPlayerType() == "Human") { // current player is human
        showBoards(p1, p2);
        std::cout << curPName << ", where would you like to fire?" << endl;
        point = p2.getAttackPoint();
        isHit = p2.addAttack(point);
        showBoards(p1, p2);
      } else if (p1.getPlayerType() == "CheatingAI") {
        point = p2.getFirstTargetPoint();  // get first available target from opponent
        if (point[0] != -1) {
          isHit = p2.addAttack(point);
        }
        showBoards(p1, p2);
      } else if (p1.getPlayerType() == "RandomAI") {
        // point = p2.getFirstTopDownPoint();  // random
        point = p1.getFirstTopDownPoint(p2);
        isHit = p2.addAttack(point);
        showBoards(p1, p2);
      } else if (p1.getPlayerType() == "HuntAndDestroyAI") {
        point = p1.getFirstTopDownPoint(p2);  // random, then target
        isHit = p2.addAttack(point);
        showBoards(p1, p2);
      }

      showHitResult(isHit[0], isHit[1], curPName, oppPName);
      shipDestroyedMsg(curPName, oppPName, isHit[0], isHit[1], ships2);
      std::cout << std::endl;

      if (isGameOver(p2)) {
        break;
      }

    } else if (playerTurn == 1) { // p2 == current player
      curPName = p2.getName();
      oppPName = p1.getName();

      if (p2.getPlayerType() == "Human") {
        showBoards(p2, p1);
        std::cout << p2.getName() << ", where would you like to fire?" << endl;
        point = p1.getAttackPoint();
        isHit = p1.addAttack(point);
        showBoards(p2, p1);
      } else if (p2.getPlayerType() == "CheatingAI") {
        point = p1.getFirstTargetPoint();  // get first available target from opponent
        if (point[0] != -1) {
          isHit = p1.addAttack(point);
        }
        showBoards(p2, p1);
      } else if (p2.getPlayerType() == "RandomAI") {
        point = p2.getFirstTopDownPoint(p1);
        isHit = p1.addAttack(point);
        showBoards(p2, p1);
      } else if (p2.getPlayerType() == "HuntAndDestroyAI") {
        point = p2.getFirstTopDownPoint(p1);
        isHit = p1.addAttack(point);
        showBoards(p2, p1);
      }

      showHitResult(isHit[0], isHit[1], curPName, oppPName);
      shipDestroyedMsg(curPName, oppPName, isHit[0], isHit[1], ships1);
      std::cout << std::endl;

      if (isGameOver(p1)) {
        break;
      }
    }

    changeTurn();
  }

  declareResults();
}

void BattleShip::BattleShip::changeTurn() { // 0 or 1
  playerTurn = (playerTurn + 1) % players.size();
}

BattleShip::Player& BattleShip::BattleShip::getCurrentPlayer() {
  return players.at(playerTurn);
}

bool BattleShip::BattleShip::isGameOver(Player& opponentPlayer) { // opponent
  std::vector<Ship> ships = opponentPlayer.getShips();
  Board board = opponentPlayer.getBoard();
  int numShips = opponentPlayer.getShips().size();
  int rows = opponentPlayer.getBoard().getRowSize();
  int cols = opponentPlayer.getBoard().getColSize();
  bool isWin = false;
  int totalShipLocations = 0;
  int attackedCount = 0;

  for (int k = 0; k < numShips; k++) {
    totalShipLocations += ships[k].getSize();
  }

  ///Loops through rows and columns of the board
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      // check all attached (X) ship locations
      if(board.isSpaceAttacked(i, j)){
        attackedCount++;
      }
    }
  }

  if (attackedCount == totalShipLocations) {
    isWin = true;
  }

  return isWin;
}

void BattleShip::BattleShip::declareResults() {
  std::cout << getCurrentPlayer().getName() << " won the game!" << std::endl;
}

void BattleShip::BattleShip::showBoards(Player& curPlayer, Player& oppPlayer) {
  cout << curPlayer.getName() << "'s Firing Board" << endl;
  oppPlayer.getBoard().displayHiddenShipBoard();
  std::cout << std::endl;
  std::cout << std::endl;
  cout << curPlayer.getName() << "'s Placement Board" << endl;
  curPlayer.getBoard().display();
}

void BattleShip::BattleShip::showHitResult(char sHit, char sSymbol, std::string curPName, std::string oppPName) {
  if (sHit == '+') {
    std::cout << curPName << " hit " << oppPName << "'s " << sSymbol << "!" << std::endl;
  } else {
    std::cout << "Missed." << std::endl;
  }
}

void BattleShip::BattleShip::shipDestroyedMsg(std::string curPName, std::string oppPName,
    char sHit, char sSymbol, std::vector<Ship>& oppShips) {

  bool isDestroyed = false;

  if (sHit == '+') {
    int len = oppShips.size();
    for (int i = 0; i < len; i++) {
      if (oppShips[i].getSymbol() == sSymbol) { // a hit
        oppShips[i].updateHits();
        if (oppShips[i].getHits() >= oppShips[i].getSize()) { // a ship is destroyed
          isDestroyed =  true;
        }
      }
    }
  }

  if (isDestroyed) {
    std::cout << curPName << " destroyed " << oppPName << "'s " << sSymbol << "!" << std::endl;
  }

}





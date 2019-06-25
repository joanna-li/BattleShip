//
// Created by Joanna on 2019-06-04.
//

#include <iostream>
#include <sstream>
#include <random>
#include <ctime>
#include "Utility.h"
#include "Player.h"
#include "ShipPlacement.h"
#include "Ship.h"

std::string BattleShip::Player::Player::previousName = "";
std::mt19937 BattleShip::Player::randomNumberGenerator((time(nullptr)));


BattleShip::Player::Player(BattleShip::GameAttributes& gameAttributes, BattleShip::Board& board,
    std::vector<BattleShip::Ship>& ships, std::string playerType) :
    gameAttributes(gameAttributes), board(board), ships(ships), playerType(playerType) {

}

const std::string& BattleShip::Player::getName() const {
  return name;
}

void BattleShip::Player::setName(std::string playerName) {
  name = playerName;
}

const std::string& BattleShip::Player::getPlayerType() const {
  return playerType;
}

BattleShip::Board BattleShip::Player::getBoard() {
  return board;
}

const BattleShip::GameAttributes BattleShip::Player::getGameAttributes() const {
  return gameAttributes;
}

std::vector<std::vector<int>> BattleShip::Player::getLocationsFired(Player& opponentPlayer) {
  return locationsFired;
}
void BattleShip::Player::setLocationsFired(int row, int col) { // adding
  locationsFired.push_back({row, col});
}

std::vector<std::vector<int>> BattleShip::Player::getFiringLocations(Player& opponentPlayer) {
  return firingLocations;
}
void BattleShip::Player::setFiringLocations(int row, int col) { // deleting fired
  for (int i = 0; i<firingLocations.size(); ++i) {
    if (firingLocations[i][0] == row && firingLocations[i][1] == col) {
      firingLocations.erase(firingLocations.begin() + i);
    }
  }
}

void BattleShip::Player::initializeName() {
  name = "Joanna";
}

bool BattleShip::Player::validName(std::string name) {
  bool isSame = true;
  if (name.empty() || previousName == name)
    isSame = false;
//  for (int i = 0; i < name.length(); i++)
//    if (isalpha(name[i]) == false)
//      isSame = false;
  return isSame;
}

void BattleShip::Player::placeShips() {

}

std::vector<char> BattleShip::Player::addAttack(std::vector<int> point) {
  return board.addAttack(point[0], point[1]);
}

std::vector<int> BattleShip::Player::getAttackPoint() {
  do {
    std::cout << "Enter your attack coordinate in the form row col: ";
    std::cin >> row >> col;
    std::string extra1;
    std::getline(std::cin, extra1);
  } while (!board.inBounds(row, col));
  return {row, col};
}

std::vector<int> BattleShip::Player::getFirstTargetPoint() {
  return board.getFirstTargetPoint();
}

//std::vector<int> BattleShip::Player::getFirstTopDownPoint() {
//  // return board.getFirstTopDownPoint();
//}

std::vector<int> BattleShip::Player::getFirstTopDownPoint(BattleShip::Player &oppPlayer) {
  int rows = oppPlayer.getBoard().getRowSize();
  int cols = oppPlayer.getBoard().getColSize();
  int row, col;

  do {
    row = getRandInt(0, rows - 1, randomNumberGenerator);
    col = getRandInt(0, cols - 1, randomNumberGenerator);
  } while (oppPlayer.getBoard().isSpaceMissed(row, col) || oppPlayer.getBoard().isSpaceAttacked(row, col));

  return {row, col};
}

//std::vector<int> BattleShip::Player::getNearbyPoint(int row, int col) {
//  return board.getNearbyPoint(row, col);
//}

std::vector<BattleShip::Ship> BattleShip::Player::getShips() {
  return ships;
}

int BattleShip::Player::getHits(Ship& ship) {
  return ship.getHits();
}

void BattleShip::Player::updateHits(Ship& ship) {
  ship.updateHits();
}

char BattleShip::Player::getSymbol(Ship& ship) {
  return ship.getSymbol();
}

int BattleShip::Player::getSize(Ship& ship) {
  return ship.getSize();
}

void BattleShip::Player::seed_random_number_generator(int seed) {
  BattleShip::Player::randomNumberGenerator.seed(seed);
}
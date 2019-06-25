//
// Created by Joanna on 2019-06-04.
//
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <random>
#include "GameAttributes.h"
#include "Board.h"
#include "BattleShip.h"
#include "Ship.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntAndDestroyAI.h"

using namespace std;

int main(int argc, char* argv[]) {
  // try process config file here
  std::vector<string> configAttributes;
  std::string path =  argv[1];
  std::string filePath = path;
  ifstream inFile;
  inFile.open(filePath);
  if (inFile.fail()) {
    cerr << "Error opening the configure file" << endl;
    inFile.close();
    exit(1);
  }
  std::string line;
  while (getline(inFile, line)) {
    configAttributes.push_back(line);
  }
  inFile.close();

  if (argc > 2) {
    configAttributes.push_back(argv[2]);
  } else {
    configAttributes.push_back("0");
  }

  // getMode
  int mode;
  string input;
  string oneAiPlayer;
  string firstAiPlayer;
  string secondAiPlayer;

  do {
    std::cout << "What type of game do you want to play?" << endl;
    std::cout << "1. Human vs Human" << endl;
    std::cout << "2. Human vs AI" << endl;
    std::cout << "3. AI vs AI" << endl;
    getline(cin, input);
  } while (!(input[0] == '1' || input[0] == '2' || input[0] == '3'));

  mode = input[0];

  // init game
  BattleShip::GameAttributes gameAttributes(configAttributes);
  BattleShip::BattleShip myGame(gameAttributes);
  BattleShip::Board board1(gameAttributes.getRow(), gameAttributes.getCol(), '*');
  BattleShip::Board board2(gameAttributes.getRow(), gameAttributes.getCol(), '*');
  std::vector<BattleShip::Ship> ships1 = gameAttributes.getShips();
  std::vector<BattleShip::Ship> ships2 = gameAttributes.getShips();

  if (mode == '1') {  // two human players

    BattleShip::HumanPlayer hPlayer1(gameAttributes, board1, ships1, "Human");
    hPlayer1.initializeName();
    hPlayer1.getBoard().display();
    hPlayer1.placeShips();

    BattleShip::HumanPlayer hPlayer2(gameAttributes, board2, ships2, "Human");
    hPlayer2.initializeName();
    hPlayer2.getBoard().display();
    hPlayer2.placeShips();

    myGame.play(hPlayer1, hPlayer2, board1, board2, ships1, ships2);

  } else if (mode == '2') { // human vs ai

    BattleShip::HumanPlayer hPlayer(gameAttributes, board1, ships1, "Human");
    hPlayer.initializeName();
    hPlayer.getBoard().display();
    hPlayer.placeShips();

    do {
      std::cout << "What AI do you want?" << endl;
      std::cout << "1. Cheating AI" << endl;
      std::cout << "2. Random AI" << endl;
      std::cout << "3. Hunt Destroy AI" << endl;
      std::cin >> oneAiPlayer;
    } while (!(oneAiPlayer[0] == '1' || oneAiPlayer[0] == '2' || oneAiPlayer[0] == '3'));

    if (oneAiPlayer[0] == '1') { // cheating ai
      BattleShip::CheatingAI cAI(gameAttributes, board2, ships2, "CheatingAI");
      cAI.initializeName();
      if (argc > 2) {
        cAI.seed_random_number_generator(stoi(argv[2]));
      }
      cAI.placeShips();
      myGame.play(hPlayer, cAI, board1, board2, ships1, ships2);
    } else if (oneAiPlayer[0] == '2') { // random IA
      BattleShip::RandomAI rAI(gameAttributes, board2, ships2, "RandomAI");
      rAI.initializeName();
      if (argc > 2) {
        rAI.seed_random_number_generator(stoi(argv[2]));
      }
      rAI.placeShips();
      myGame.play(hPlayer, rAI, board1, board2, ships1, ships2);
    } else if (oneAiPlayer[0] == '3') { //hdAI
      BattleShip::HuntAndDestroyAI hdAI(gameAttributes, board2, ships2, "HuntAndDestroyAI");
      hdAI.initializeName();
      if (argc > 2) {
        hdAI.seed_random_number_generator(stoi(argv[2]));
      }
      hdAI.placeShips();
      myGame.play(hPlayer, hdAI, board1, board2, ships1, ships2);
    }

  } else if (mode == '3') { // ai vs ai

    do {
      std::cout << "Your choice: What AI do you want?" << endl;
      std::cout << "1. Cheating AI" << endl;
      std::cout << "2. Random AI" << endl;
      std::cout << "3. Hunt Destroy AI" << endl;
      std::cin >> firstAiPlayer;
    } while (!(firstAiPlayer[0] == '1' || firstAiPlayer[0] == '2' || firstAiPlayer[0] == '3'));

    if (firstAiPlayer[0] == '1') { // cAI

      BattleShip::CheatingAI cAI1(gameAttributes, board1, ships1, "CheatingAI");
      cAI1.initializeName();
      if (argc > 2) {
        cAI1.seed_random_number_generator(stoi(argv[2]));
      }
      cAI1.placeShips();

      do {
        std::cout << "What AI do you want?" << endl;
        std::cout << "1. Cheating AI" << endl;
        std::cout << "2. Random AI" << endl;
        std::cout << "3. Hunt Destroy AI" << endl;
        std::cin >> secondAiPlayer;
      } while (!(secondAiPlayer[0] == '1' || secondAiPlayer[0] == '2' || secondAiPlayer[0] == '3'));

      if (secondAiPlayer[0] == '1') {
        BattleShip::CheatingAI cAI2(gameAttributes, board2, ships2, "CheatingAI");
        cAI2.initializeName();
        cAI2.placeShips();
        myGame.play(cAI1, cAI2, board1, board2, ships1, ships2);
      } else if (secondAiPlayer[0] == '2') {
        BattleShip::RandomAI rAI2(gameAttributes, board2, ships2, "RandomAI");
        rAI2.initializeName();
        rAI2.placeShips();
        myGame.play(cAI1, rAI2, board1, board2, ships1, ships2);
      } else if (secondAiPlayer[0] == '3') {
        BattleShip::HuntAndDestroyAI hdAI2(gameAttributes, board2, ships2, "HuntAndDestroyAI");
        hdAI2.initializeName();
        hdAI2.placeShips();
        myGame.play(cAI1, hdAI2, board1, board2, ships1, ships2);
      }

    } else if (firstAiPlayer[0] == '2') { // rAI

      BattleShip::RandomAI rAI1(gameAttributes, board1, ships1, "RandomAI");
      rAI1.initializeName();
      if (argc > 2) {
        rAI1.seed_random_number_generator(stoi(argv[2]));
      }
      rAI1.placeShips();

      do {
        std::cout << "What AI do you want?" << endl;
        std::cout << "1. Cheating AI" << endl;
        std::cout << "2. Random AI" << endl;
        std::cout << "3. Hunt Destroy AI" << endl;
        std::cin >> secondAiPlayer;
      } while (!(secondAiPlayer[0] == '1' || secondAiPlayer[0] == '2' || secondAiPlayer[0] == '3'));

      if (secondAiPlayer[0] == '1') {
        BattleShip::CheatingAI cAI2(gameAttributes, board2, ships2, "CheatingAI");
        cAI2.initializeName();
        cAI2.placeShips();
        myGame.play(rAI1, cAI2, board1, board2, ships1, ships2);
      } else if (secondAiPlayer[0] == '2') {
        BattleShip::RandomAI rAI2(gameAttributes, board2, ships2, "RandomAI");
        rAI2.initializeName();
        rAI2.placeShips();
        myGame.play(rAI1, rAI2, board1, board2, ships1, ships2);
      } else if (secondAiPlayer[0] == '3') {
        BattleShip::HuntAndDestroyAI hdAI2(gameAttributes, board2, ships2, "HuntAndDestroyAI");
        hdAI2.initializeName();
        hdAI2.placeShips();
        myGame.play(rAI1, hdAI2, board1, board2, ships1, ships2);
      }
    } else if (firstAiPlayer[0] == '3') { // hdAI

      BattleShip::HuntAndDestroyAI hdAI1(gameAttributes, board1, ships1, "HuntAndDestroyAI");
      hdAI1.initializeName();
      if (argc > 2) {
        hdAI1.seed_random_number_generator(stoi(argv[2]));
      }
      hdAI1.placeShips();

      do {
        std::cout << "What AI do you want?" << endl;
        std::cout << "1. Cheating AI" << endl;
        std::cout << "2. Random AI" << endl;
        std::cout << "3. Hunt Destroy AI" << endl;
        std::cin >> secondAiPlayer;
      } while (!(secondAiPlayer[0] == '1' || secondAiPlayer[0] == '2' || secondAiPlayer[0] == '3'));

      if (secondAiPlayer[0] == '1') {
        BattleShip::CheatingAI cAI2(gameAttributes, board2, ships2, "CheatingAI");
        cAI2.initializeName();
        cAI2.placeShips();
        myGame.play(hdAI1, cAI2, board1, board2, ships1, ships2);
      } else if (secondAiPlayer[0] == '2') {
        BattleShip::RandomAI rAI2(gameAttributes, board2, ships2, "RandomAI");
        rAI2.initializeName();
        rAI2.placeShips();
        myGame.play(hdAI1, rAI2, board1, board2, ships1, ships2);
      } else if (secondAiPlayer[0] == '3') {
        BattleShip::HuntAndDestroyAI hdAI2(gameAttributes, board2, ships2, "HuntAndDestroyAI");
        hdAI2.initializeName();
        hdAI2.placeShips();
        myGame.play(hdAI1, hdAI2, board1, board2, ships1, ships2);
      }
    }

  }




  return 0;
}
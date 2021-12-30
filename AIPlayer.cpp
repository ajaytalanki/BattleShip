//
// Created by Ajay Talanki and Andy Lam on 5/20/2021.
//

#include "AIPlayer.h"
#include <iostream>

namespace BattleShip{
std::mt19937 AIPlayer::generator;  //  initializes randon number generator
    AIPlayer::AIPlayer(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int& aiNumber) : Player(rows, cols, mapOfShips) {
      Name = "AI ";
      Name += std:: to_string(aiNumber);  //  gets AI's name
    }

    void BattleShip::AIPlayer::seedGenerator(int seed) {
        generator.seed(seed);
    }

    //  places ships, same FOR EVERY AI
    void AIPlayer::place_ships(Board &board) {
        int num, rowInput, colInput = 0;
        int rows = board.getRows(); int cols = board.getCols();
        char orientation;
        for (const auto &ship : ShipsMap) {  //  for every ship
            do {
                num = getRandomInt(0, 1);  //  chooses orientation
                if (num == 0) {  //  generates ship's position and make's sure its in a valid location
                    rowInput = getRandomInt(0, rows - 1);
                    colInput = getRandomInt(0, cols - ship.second);
                    orientation = 'H';
                } else {
                    rowInput = getRandomInt(0, rows - ship.second);
                    colInput = getRandomInt(0, cols - 1);
                    orientation = 'V';
                }
            } while(!board.isAvailable(rowInput, colInput, ship.second, orientation));
            this->placement_board.place_ship(ship.first, rowInput, colInput, ship.second, orientation);  //  places 1 ship
            std::cout << this->getName() + "'s Board" << std::endl;
            board.print();
            std::cout << std::endl;
        }
    }

    int AIPlayer::getRandomInt(int min, int max) {  //  generates random num
        std::uniform_int_distribution<int> dist(min, max);
        int random_num = dist(generator);
        return random_num;
    }

}


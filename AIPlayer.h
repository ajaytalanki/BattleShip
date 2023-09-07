#ifndef BATTLESHIP_AIPLAYER_H
#define BATTLESHIP_AIPLAYER_H
#include "Player.h"
#include <random>

namespace BattleShip {
    class AIPlayer : public Player {
    public:
        AIPlayer(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int& aiNumber);
        virtual ~AIPlayer() = default;
        static void seedGenerator(int seed);
        virtual void getSpaces(Board &player2PlacementBoard) = 0;
        virtual void place_ships(Board &board) override;
        static int getRandomInt(int min, int max);
        static std::mt19937 generator; //  generates all the random numbers in the program for AI's
    };
}
#endif //BATTLESHIP_AIPLAYER_H


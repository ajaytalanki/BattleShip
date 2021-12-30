//
// Created by Ajay Talanki and Andy Lam on 5/20/2021.
//

#include "RandomAI.h"

namespace BattleShip{
    // Constructor to create a RandomAI class object
    RandomAI::RandomAI(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int& aiNumber) : AIPlayer(rows, cols,
                                                                                                         mapOfShips, aiNumber) {}
    //  generates a vector of pairs of all locations on the board
    void RandomAI::getSpaces(Board &player2PlacementBoard) {
        int rows = player2PlacementBoard.getRows();
        int cols = player2PlacementBoard.getRows();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                randomMoves.emplace_back(std::make_pair(i, j));
            }
        }
    }

    //  generates a random location from the vector of locations and removes the location from vector
    void RandomAI::getMove(int &rowInput, int &colInput, Board &player2PlacementBoard) {
        int index;
        if (randomMoves.empty()) {
            getSpaces(this->getPlacementBoard());
        }
        index = getRandomInt(0, randomMoves.size() - 1);
        rowInput = randomMoves.at(index).first;
        colInput = randomMoves.at(index).second;
        randomMoves.erase(randomMoves.begin() + index);
        Board copy = player2PlacementBoard;
    }

}
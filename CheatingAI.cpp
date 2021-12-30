//
// Created by Ajay Talanki and Andy Lam on 5/20/2021.
//

#include "CheatingAI.h"

namespace BattleShip{
// Constructor for creating a CheatingAI class object
    CheatingAI::CheatingAI(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int& aiNumber) : AIPlayer(rows, cols,
                                                                                                                                    mapOfShips, aiNumber) {}
    //  gets all the positions of the ships
    void BattleShip::CheatingAI::getSpaces(Board &player2PlacementBoard) {
        int rows = player2PlacementBoard.getRows();
        int cols = player2PlacementBoard.getRows();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (player2PlacementBoard.getChar(i, j) != '*') {
                    moves.emplace_back(std::make_pair(i, j));
                }
            }
        }
    }

    //  gets the next closest ship's postition and removes it from vector
    void CheatingAI::getMove(int &rowInput, int &colInput, Board &player2PlacementBoard) {
        getSpaces(player2PlacementBoard);
        rowInput = moves.at(0).first;
        colInput = moves.at(0).second;
        moves.erase(moves.begin());
    }
}


#include "SearchAndDestroyAI.h"
#include <algorithm>

namespace BattleShip {
    // Constructor to create a SearchAndDestroyAI class object
    SearchAndDestroyAI::SearchAndDestroyAI(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int& aiNumber)
            : RandomAI(rows, cols, mapOfShips, aiNumber) {

    }

    // Function that gets a SearchAndDestroy AI's move
    void SearchAndDestroyAI::getMove(int &rowInput, int &colInput, Board &player2PlacementBoard) {
        if (surrounding.empty()) { // Checks to see if the vector for Destroy Mode is empty
            RandomAI::getMove(rowInput, colInput, player2PlacementBoard);  //  gets random location
            if (player2PlacementBoard.getChar(rowInput, colInput) != '*') {  //  if its a hit, get all the surrounding locations
                getSurroundingSpace(rowInput, colInput, player2PlacementBoard); // Fills up the Destroy mode's vector
            }
        } else {
            destroyMode(rowInput, colInput, player2PlacementBoard);  //  returns the next surrounding spot
        }
    }

    //  gets the left, top, right, and bottom spaces around a location
    void
    SearchAndDestroyAI::getSurroundingSpace(const int &rowInput, const int &colInput, Board &player2PlacementBoard) {
        int rows = player2PlacementBoard.getRows();
        int cols = player2PlacementBoard.getRows();
        if (colInput - 1 >= 0 && player2PlacementBoard.validAction(rowInput, colInput - 1)) {  // checks bounds
            if(!isIn(rowInput, colInput - 1)) {  // checks to see if pair is already in the surrounding spots vector
                surrounding.push_back({rowInput, colInput - 1});  //  adds location to the surrounding spots vector
                removeFromRandom(rowInput, colInput - 1);  // erases the spot from the randomMoves vector
            }
        }
        if (rowInput - 1 >= 0 && player2PlacementBoard.validAction(rowInput - 1, colInput)) {
            if(!isIn(rowInput - 1, colInput)) {
                surrounding.push_back({rowInput - 1, colInput});
                removeFromRandom(rowInput - 1, colInput);
            }
        }
        if (colInput + 1 < cols && player2PlacementBoard.validAction(rowInput, colInput + 1)) {
            if(!isIn(rowInput, colInput + 1)) {
                surrounding.push_back({rowInput, colInput + 1});
                removeFromRandom(rowInput, colInput + 1);
            }
        }
        if (rowInput + 1 < rows && player2PlacementBoard.validAction(rowInput + 1, colInput)) {
            if(!isIn(rowInput + 1, colInput)) {
                surrounding.push_back({rowInput + 1, colInput});
                removeFromRandom(rowInput + 1, colInput);
            }
        }
    }

    //  returns the next destroy spot to shoot at, and gets that position's surrounding spots
    void SearchAndDestroyAI::destroyMode(int &rowInput, int &colInput, Board &player2PlacementBoard) {

        rowInput = surrounding.at(0).first;
        colInput = surrounding.at(0).second;
        if (player2PlacementBoard.getChar(rowInput, colInput) != '*') {
            getSurroundingSpace(rowInput, colInput, player2PlacementBoard);
        }
        surrounding.erase(surrounding.begin());
    }

    //  removes the pair from randomMoves so it doesn't shoot there again
    void SearchAndDestroyAI::removeFromRandom(const int& rowInput, const int& colInput) {
        auto pair = std:: make_pair(rowInput, colInput);
        if (std:: find(randomMoves.begin(), randomMoves.end(), pair) != randomMoves.end()) {
            auto itr = std::find(randomMoves.begin(), randomMoves.end(), pair);
            if (itr != randomMoves.end()) {
                randomMoves.erase(randomMoves.begin() + (itr - randomMoves.begin()));
            }
        }
    }

    //  checks if a pair is already in the surround spots vector
    bool SearchAndDestroyAI::isIn(const int& rowInput, const int& colInput) {
        auto pair = std:: make_pair(rowInput, colInput);
        if(std::find(surrounding.begin(), surrounding.end(), pair) != surrounding.end()) {
            return true;
        }
        return false;
    }
}
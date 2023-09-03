#include "HumanPlayer.h"
#include "inputValidation.h"
#include <iostream>

namespace BattleShip {
    // Constructor to create a HumanPlayer class object
    HumanPlayer::HumanPlayer(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips, const int& playerNumber) : Player(rows, cols, mapOfShips) {
        std::string name;  //  gets valid name for human player
        do {
            std::cout << "Player " << playerNumber << " please enter your name: ";
            std::getline(std::cin, name);
        } while (check_empty_string(name));
        trim_string(name);
        Name = name;
    }

    //  gets valid input and places the ships on the board
    void HumanPlayer::place_ships(Board &board) {
        board.print();
        char orientation, shipName;
        int rowInput, colInput, shipSize;
        int rows = board.getRows(); int cols = board.getCols();
        bool gotValidInt;
        for (const auto &ship : ShipsMap) {
            do {
                shipSize = ship.second; shipName = ship.first;
                orientation = getValidChar(this->getName(), shipName);
                gotValidInt = getValidInts(
                        (this->getName() + ", enter the row and column you want to place " + shipName + ", which is " +
                         std::to_string(shipSize) + " long, at with a space in between row and col: "), rowInput,
                        colInput);
            } while (!gotValidInt || !checkBounds(orientation, rowInput, colInput, rows, cols, shipSize) ||
                     !board.isAvailable(rowInput, colInput, shipSize, orientation));
            this->placement_board.place_ship(shipName, rowInput, colInput, shipSize, orientation);  // places one ship
        }
        board.print();
    }

    //  gets valid attack in bounds and new firing spots
    void HumanPlayer::getMove(int &rowInput, int &colInput, Board& player2PlacementBoard) {
        std::cout << this->getName() << "'s Firing Board" << std::endl;
        this->getFiringBoard().print(); // Display's the first player's boards
        std::cout << std::endl << std::endl << this->getName() << "'s Placement Board" << std::endl;
        this->getPlacementBoard().print();
        bool gotValidInt;
        Board copy = player2PlacementBoard;
        do {  // Ask the player for their move
            gotValidInt = getValidInts((this->getName() + ", where would you like to fire?\n" +
                                        "Enter your attack coordinate in the form row col: "), rowInput, colInput);
            if (gotValidInt && !firing_board.validAction(rowInput, colInput)) { // If they enter in 2 numbers, check if they are in bounds
                std::cout << this->getName() << "'s Firing Board" << std::endl;
                firing_board.print();
                std::cout << std::endl << std::endl << this->getName() << "'s Placement Board" << std::endl;
                placement_board.print();
                gotValidInt = false;
            }
        } while (!gotValidInt ); // keep asking if user doesn't enter 2
    }
}


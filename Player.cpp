#include <iostream>
#include "Player.h"
#include "Board.h"

namespace BattleShip {
    // Constructor to make a Player class object
    BattleShip::Player::Player(const int &rows, const int &cols, const std::map<char, int> &mapOfShips) : ShipsMap(
            mapOfShips), firing_board(rows, cols), placement_board(rows, cols) {

        this->firing_board.make_board();
        this->placement_board.make_board();
    }

    // Function to get a player's name
    const std::string &BattleShip::Player::getName() const {
        return this->Name;
    }

    // Function to get a player's ship map
    const BattleShip::Ships &BattleShip::Player::getShipsMap() const {
        return this->ShipsMap;
    }

//  decrements the ship's health by one every hit
    void BattleShip::Player::updateShipsMap(const Player &player1, const Player &player2, const char &shipName) {
        std::map<char, int>::iterator itr;
        itr = ShipsMap.find(shipName);
        itr->second -= 1;
        std::cout << player1.getName() << " hit " << player2.getName() << "'s " << shipName << "!" << std::endl;
        if (itr->second == 0) {
            std::cout << player1.getName() << " destroyed " << player2.getName() << "'s " << shipName << "!"
                      << std::endl << std::endl;
            ShipsMap.erase(itr);
        } else {
            std::cout << std::endl;
        }
    }

    // Function to get a player's firing board
    Board &Player::getFiringBoard() {
        return this->firing_board;
    }

    // Function to get a player's placement board
    Board &Player::getPlacementBoard() {
        return this->placement_board;
    }

    // Function to fire at an opponent's board
    void Player::fire(const char &shipName, Player& player2, const int& rowInput, const int& colInput) {
        if (shipName != '1') { // If shipName is not equal to '1', it is a hit
            this->getFiringBoard().update('X', rowInput, colInput); // Update the area on the player's target board with an X
            player2.getPlacementBoard().update('X', rowInput,
                                    colInput); // Update the area on the player's placement board with an X
            std::cout << this->getName() << "'s Firing Board" << std::endl;
            this->getFiringBoard().print();
            std::cout << std::endl << std::endl << this->getName() << "'s Placement Board" << std::endl;
            this->getPlacementBoard().print();
            player2.updateShipsMap(*this, player2, shipName); // Update the value of the ship in player's ship map.
        } else { // If it was a miss
            this->getFiringBoard().update('O', rowInput, colInput); // Update the area on the player's placement board with an O
            player2.getPlacementBoard().update('O', rowInput,
                                    colInput); // Update the area on the player's placement board with an O
            std::cout << this->getName() << "'s Firing Board" << std::endl;
            this->getFiringBoard().print();
            std::cout << std::endl << std::endl << this->getName() << "'s Placement Board" << std::endl;
            this->getPlacementBoard().print();
            std::cout << "Missed." << std::endl << std::endl;
        }
    }
}
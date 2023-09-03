#ifndef BATTLESHIP__PLAYER_H_
#define BATTLESHIP__PLAYER_H_

#include <string>
#include <map>
#include "Board.h"

namespace BattleShip {

    using Ships = std::map<char, int>;

    class Player {
    public:
        Player(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips);  //  allows for compiler automatic initialization for at
        virtual ~Player() = default;
        const std::string &getName() const;
        const Ships &getShipsMap() const;
        void updateShipsMap(const Player& player1, const Player& player2, const char &shipName);  //  decrements the ship's health
        Board& getFiringBoard();
        Board& getPlacementBoard();
        virtual void place_ships(Board &board) = 0;
        virtual void getMove(int &rowInput, int &colInput, Board &player2PlacementBoard) = 0;
        void fire(const char& shipName, Player& player2, const int& rowInput, const int& colInput);

    protected:
        std::string Name;
        Ships ShipsMap;  //  each player gets a map of ships
        Board firing_board;
        Board placement_board;
    };
}

#endif //BATTLESHIP__PLAYER_H_

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
namespace BattleShip {
    class HumanPlayer : public Player {
    public:
        HumanPlayer(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips, const int& playerNumber);
        virtual ~HumanPlayer() = default;
        virtual void place_ships(Board &board) override;
        virtual void getMove(int &rowInput, int &colInput, Board& player2PlacementBoard) override;

    };
}

#endif //BATTLESHIP_HUMANPLAYER_H

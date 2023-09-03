#ifndef BATTLESHIP_SEARCHANDDESTROYAI_H
#define BATTLESHIP_SEARCHANDDESTROYAI_H

#include "RandomAI.h"

namespace BattleShip {
    class SearchAndDestroyAI : public RandomAI {
    public:
        SearchAndDestroyAI(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips, const int& aiNumber);
        virtual ~SearchAndDestroyAI() = default;
        virtual void getMove(int &rowInput, int &colInput, Board &player2PlacementBoard) override;
        void getSurroundingSpace(const int &rowInput, const int &colInput, Board &player2PlacementBoard);
        void destroyMode(int &rowInput, int &colInput, Board &player2PlacementBoard);
        void removeFromRandom(const int& rowInput, const int& colInput);
        bool isIn(const int& rowInput, const int& colInput);
    protected:
        std:: vector<std:: pair<int, int>> surrounding;
    };
}

#endif //BATTLESHIP_SEARCHANDDESTROYAI_H

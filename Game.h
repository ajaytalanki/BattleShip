#ifndef BATTLESHIP__GAME_H_
#define BATTLESHIP__GAME_H_
#include <map>
#include <memory>
#include <vector>
#include "Player.h"
#include "Board.h"

namespace BattleShip {
   class Game{
    public:
        Game(const int &rows, const int &cols, const std::map<char, int> &shipMap, const int& seed);
        void playGame();
        void pickGame();
        static int pickAI();
        void addPlayers(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips, const int& gameNumber);
        static void setupRound(Player& player, Board& board);
        static void playRound(Player &player1, Player &player2);
        void makePlayer(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips, const int& playerNumber);
        void makeAIPlayer(const int&rows, const int&cols, const std:: map <char, int>& mapOfShips, const int& playerNumber, int aiNum);

    protected:
     int Seed;
    private:
        bool game_over() const; // make a private function to check for game over so that both parties don't know the next outcome
        std:: unique_ptr<Player> player1;
        std:: unique_ptr<Player> player2;
        int Rows;
        int Cols;
        std::map<char, int> ShipsMap;
    };
}

#endif //BATTLESHIP__GAME_H_


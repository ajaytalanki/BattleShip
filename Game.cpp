#include <iostream>
#include <map>
#include "Player.h"
#include "inputValidation.h"
#include "Game.h"
#include "HumanPlayer.h"
#include "RandomAI.h"
#include "CheatingAI.h"
#include "SearchAndDestroyAI.h"

namespace BattleShip {
    // Game constructor that will build players, their placement and target boards, dimensions of each board, and a ship map
    BattleShip::Game::Game(const int &rows, const int &cols, const std::map<char, int> &shipMap, const int &seed) : Seed(seed), player1(), player2(), Rows(rows), Cols(cols), ShipsMap(shipMap) {}

    // Function to check whether the game is over
    bool BattleShip::Game::game_over() const {
        // Checks both player's ship maps to see if they are empty
        if (player1->getShipsMap().empty() || player2->getShipsMap().empty()) {
            return true; // If empty, then this signifies the game is over
        } else {
            return false; // otherwise, game is not over
        }
    }

    // Function that asks player where to put all their ships
    void BattleShip::Game::setupRound(Player &player, Board &board) {
        player.place_ships(board);
    }

    // Function to make human players
    void Game::makePlayer(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int &PlayerNumber) {
        // Check to see which playerNumber
        switch(PlayerNumber) {
            case 1:  // For playerNumber 1
                player1 = std::make_unique<HumanPlayer>(rows, cols, mapOfShips, PlayerNumber); // Create a unique pointer of Human type
                setupRound(*player1, player1->getPlacementBoard()); // Call to set up player's board
                break;
            default:// For playerNumber 2
                player2 = std::make_unique<HumanPlayer>(rows, cols, mapOfShips, PlayerNumber); // Create a unique pointer of Human type
                setupRound(*player2, player2->getPlacementBoard()); // Call to set up player's board
                break;
        }
    }

    // Function to make ai players
    void Game::makeAIPlayer(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int &playerNumber, int aiNum) {
        switch(aiNum) {
            case 1: // cheating AI
                if (playerNumber == 1) { // For playerNumber 1
                    player1 = std::make_unique<CheatingAI>(rows, cols, mapOfShips, playerNumber); // Create a unique pointer of CheatingAI type
                    setupRound(*player1, player1->getPlacementBoard()); // Call to set up player's board
                } else { // For playerNumber 2
                    player2 = std::make_unique<CheatingAI>(rows, cols, mapOfShips, playerNumber); // Create a unique pointer of CheatingAI type
                    setupRound(*player2, player2->getPlacementBoard()); // Call to set up player's board
                }
                break;
            case 2: // Random AI
                if (playerNumber == 1) { // For playerNumber 1
                    player1 = std::make_unique<RandomAI>(rows, cols, mapOfShips, playerNumber); // Create a unique pointer of RandomAI type
                    setupRound(*player1, player1->getPlacementBoard()); // Call to set up player's board
                } else { // For random AI's
                    player2 = std::make_unique<RandomAI>(rows, cols, mapOfShips, playerNumber); // Create a unique pointer of RandomAI type
                    setupRound(*player2, player2->getPlacementBoard()); // Call to set up player's board
                }
                break;
            default: // Search and Destroy AI
                if (playerNumber == 1) { // For playerNumber 1
                    player1 = std::make_unique<SearchAndDestroyAI>(rows, cols, mapOfShips, playerNumber); // Create a unique pointer of SearchAndDestroyAI type
                    setupRound(*player1, player1->getPlacementBoard()); // Call to set up player's board
                } else {
                    player2 = std::make_unique<SearchAndDestroyAI>(rows, cols, mapOfShips, playerNumber); // Create a unique pointer of SearchAndDestroyAI type
                    setupRound(*player2, player2->getPlacementBoard()); // Call to set up player's board
                }
                break;
        }
    }

    // Function to addPlayers
    void Game::addPlayers(const int &rows, const int &cols, const std::map<char, int> &mapOfShips, const int &gameNumber) {
        int playerNumber = 1; //playerNumber set to 1
        int ai; // ai variable to hold which ai number user picks
        BattleShip::AIPlayer::seedGenerator(Seed);  // initialize seed
        switch(gameNumber) {
            case 1: // For human vs human, call makePlayer twice to make 2 human players
                makePlayer(rows, cols, mapOfShips, playerNumber); // Make human player
                playerNumber++; // increment playerNumber to 2
                makePlayer(rows,cols, mapOfShips, playerNumber); // Make human player
                break;
            case 2: // Human v AI, call makePlayer for a human Player 1 and makeAIPlayer for AI player2
                makePlayer(rows, cols, mapOfShips, playerNumber); // Make human player
                ai = pickAI(); // Call to user for which ai they want
                playerNumber++;
                makeAIPlayer(rows, cols, mapOfShips, playerNumber, ai); // Make ai player
                break;
            default: // AI v AI, call makeAIPlayer twice to choose two AIPlayers.
                ai = pickAI(); // Call to user for which ai they want
                makeAIPlayer(rows, cols, mapOfShips, playerNumber, ai); // Make ai player
                playerNumber++; // Increment playerNumber
                ai = pickAI(); // Call to user for which ai they want
                makeAIPlayer(rows, cols, mapOfShips, playerNumber, ai); // Make ai player
                break;
        }
    }

    // Function definition to allow user to pick which game to play, only accepting valid input
    void BattleShip::Game::pickGame() {
        int gameNumber;
        bool gotValidInt;
        std::string line;
        do {
            std::cout << "What type of game do you want to play?" << std::endl;
            std::cout << "1. Human vs Human" << std::endl << "2. Human vs AI" << std::endl << "3. AI vs AI"
            << std::endl;
            std::cout << "Your choice: ";
            std::getline(std::cin, line);
            gotValidInt = getValidInt(line, gameNumber);
        } while (!gotValidInt || (gameNumber < 1 || gameNumber > 3));
        addPlayers(Rows, Cols, ShipsMap, gameNumber); // Function call to addPlayers to user's game
    }

    // Function definition to allow user to pick which AI are a part of their game
    int BattleShip::Game::pickAI() {
        int aiNumber;
        bool gotValidInt;
        std::string line;
        do {
            std::cout << "What AI do you want?" << std::endl;
            std::cout << "1. Cheating AI" << std::endl << "2. Random AI" << std::endl << "3. Hunt Destroy AI"
            << std::endl;
            std::cout << "Your choice: ";
            std::getline(std::cin, line);
            gotValidInt = getValidInt(line, aiNumber);
            std::cout << std::endl;
        } while (!gotValidInt || (aiNumber < 1 || aiNumber > 3));
        return aiNumber;  // returns an ai number that will correspond to an AI
    }

    // Function for playing a round
    void BattleShip::Game::playRound(Player &player1, Player &player2) {
        int rowInput, colInput; // Create two variables to hold rows and cols
        char shipName = '1'; // Create and declare an error variable
        player1.getMove(rowInput, colInput, player2.getPlacementBoard()); // Ask for player's move
        shipName = player2.getPlacementBoard().getShipName(shipName, rowInput, colInput); // locate the area on the board
        player1.fire(shipName, player2, rowInput, colInput); // Fire using player's input
    }

    // Function that plays the game
    void BattleShip::Game::playGame() {
        pickGame();
        while (!game_over()) {  // While the game is not over
            // player 1 plays a round
            playRound(*player1, *player2);
            if (game_over()) {
                std::cout << player1->getName() << " won the game!" << std::endl;
                return;
            }
            // player 2 plays a round
            playRound(*player2, *player1);
            if (game_over()) {
                std::cout << player2->getName() << " won the game!" << std::endl;
                return;
            }
        }
    }
}
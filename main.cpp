#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "readFile.h"
#include "Game.h"

int main(int argc, char **argv) {
    int rows, cols = 0; // initializes variables for game object
    int seed = time(nullptr);
    std::map<char, int> shipInfo;
    std::ifstream myFile;
    myFile.open(argv[1]);
    if(!myFile.is_open()) {
        std::cout << "Invalid configuration file or configuration file not found" << std::endl;
        return 0;
    }
    if(argc == 3) {
        seed = atoi(argv[2]);
    }
    BattleShip::extractInfo(myFile, rows, cols, shipInfo);  //  grabs info from file
    BattleShip::Game game(rows, cols, shipInfo, seed);  //  constructs game object from input
    game.playGame();  //  runs the game
    return 0;
}

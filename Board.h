//
// Created by Ajay Talanki and Andy Lam on 5/5/2021.
//

#ifndef BATTLESHIP__BOARD_H_
#define BATTLESHIP__BOARD_H_

#include <string>
#include <vector>

using multivector = std::vector<std::vector<char>>;
namespace BattleShip {
    class Player;
    class Board {
    public:
        explicit Board(const int &rows, const int &cols);
        void print() const;
        void make_board();
        void place_ship(const char& c, const int &row, const int& col, const int& shipSize, const char& orientation);
        void update(const char &c, const int &row, const int &col);
        bool isAvailable(const int& rowInput, const int& columnInput, const int& shipSize, const char& orientation);
        bool validAction(const int &row, const int &col);
        char getShipName(char& shipName, const int &row, const int &col);
        char getChar(const int &row, const int &col);
        int getRows() const;
        int getCols() const;

    private:
        int Rows;
        int Cols;
        multivector board;

    };
}

#endif //BATTLESHIP__BOARD_H_


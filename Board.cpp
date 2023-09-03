#include "Board.h"
#include <iostream>
namespace BattleShip {
// Board constructor that takes in the rows and columns found in file
    BattleShip::Board::Board(const int &rows, const int &cols) : Rows(rows), Cols(cols) {}

// Function that prints a board
    void BattleShip::Board::print() const {
        std::cout << "  ";
        for (int i = 0; i < Cols; ++i) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
        int numRow = 0;
        for (const auto &row: board) {
            std::cout << numRow << " ";
            for (const auto &index: row) {
                std::cout << index << " ";
            }
            std::cout << std::endl;
            ++numRow;
        }
    }

// Function that makes a board
    void BattleShip::Board::make_board() {
        board.resize(Rows);
        for (int i = 0; i < Rows; ++i) {
            for (int j = 0; j < Cols; ++j) {
                board.at(i).push_back('*');
            }
        }
    }

// Function that updates a board with the given character at specified row and column
    void BattleShip::Board::update(const char &c, const int &row, const int &col) {
        board.at(row).at(col) = c;
    }

// Function that places ships onto a board
    void BattleShip::Board::place_ship(const char &c, const int &row, const int &col, const int &shipSize,
                                        const char &orientation) {
        if (orientation == 'H' || orientation == 'h') {
            for (int i = col; i < col + shipSize; ++i) {
                board.at(row).at(i) = c;
            }
        } else if (orientation == 'V' || orientation == 'v') {
            for (int i = row; i < row + shipSize; ++i) {
                board.at(i).at(col) = c;
            }
        }
    }

// Function to check whether the given row and column input already has a ship on it
    bool BattleShip::Board::isAvailable(const int &rowInput, const int &columnInput, const int &shipSize,
                                        const char &orientation) {
        if (orientation == 'H' || orientation == 'h') {
            for (int i = columnInput; i < columnInput + shipSize; ++i) {
                if (board.at(rowInput).at(i) != '*') {
                    return false;
                }
            }
            return true;
        } else if (orientation == 'V' || orientation == 'v') {
            for (int i = rowInput; i < rowInput + shipSize; ++i) {
                if (board.at(i).at(columnInput) != '*') {
                    return false;
                }
            }
            return true;
        }
        return true;
    }

//  checks to see if the firing input was in bounds, and to see if the user has not already fired there
    bool BattleShip::Board::validAction(const int &row, const int &col) {
        if ((row < 0 || col < 0) || (row >= getRows() || col >= getCols())) {
            return false;
        } else {
            if (board.at(row).at(col) == 'X' || board.at(row).at(col) == 'O') {
                return false;
            }
        }
        return true;
    }

// Function that checks what ship is on the specified row and column input
    char BattleShip::Board::getShipName(char &shipName, const int &row, const int &col) {
        if (board.at(row).at(col) != '*') {
            shipName = board.at(row).at(col);
            return shipName;
        } else {
            return shipName;
        }
    }

    // Function that obtains the character at row, col input
    char BattleShip::Board::getChar(const int &row, const int &col) {
        return board.at(row).at(col);
    }

    int Board::getRows() const {
        return Rows;
    }

    int Board::getCols() const {
        return Cols;
    }
}
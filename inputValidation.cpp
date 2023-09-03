#include <sstream>
#include <iostream>
#include <string>
#include "inputValidation.h"
namespace BattleShip {
//  returns a valid character for the orientation
    char getValidChar(const std::string &nameOfPlayer, const char &nameOfShip) {
        char orientation;
        bool valid = false;
        do {
            std::string line;
            std::cout << nameOfPlayer << ", do you want to place " << nameOfShip << " horizontally or vertically?"
                      << std::endl << "Enter h for horizontal or v for vertical" << std::endl << "Your choice: ";
            std::getline(std::cin, line);
            std::stringstream lineParse(line);
            lineParse >> orientation;
            if (lineParse) {
                std::string leftover;
                lineParse >> leftover;
                if (not lineParse) {
                    valid = true;
                } else {
                    valid = false;
                }
            }
        } while (!valid || !checkHorizontalOrVertical(orientation));
        return orientation;
    }

//  returns true if orientation is valid (vertical or horizontal)
    bool checkHorizontalOrVertical(const char &characterInput) {
        if (characterInput == 'H' || characterInput == 'h' || characterInput == 'V' || characterInput == 'v') {
            return true;
        } else {
            return false;
        }
    }

//  returns true if user entered two valid integers
    bool getValidInts(const std::string &prompt, int &rowNumber, int &columnNumber) {
        std::string line;
        std::cout << prompt;
        std::getline(std::cin, line);
        std::stringstream parse(line);
        parse >> rowNumber >> columnNumber;
        if (parse) {
            std::string leftover;
            parse >> leftover;
            if (not parse) {
                return true;
            }
        }
        return false;
    }

//  checks to see if the ship fits on the board
    bool checkBounds(const char &c, const int &rowInput, const int &colInput, const int &rowSize, const int &colSize,
                     const int &size) {
        if ((rowInput < 0 || colInput < 0) ||
            (rowInput > rowSize || colInput > colSize)) {  //  returns false if the user enters out of bounds number
            return false;
        } else {
            if (c == 'H' || c == 'h') {  //  returns true or false depending on if ship is horizontal
                if ((colInput + (size - 1)) > colSize - 1) {
                    return false;
                } else {
                    return true;
                }
            } else if (c == 'v' || c == 'V') {  //  returns true or false depending on if ship vertical
                if ((rowInput + (size - 1)) > rowSize - 1) {
                    return false;
                } else {
                    return true;
                }
            } else {
                return true;
            }
        }
    }

    // Function that checks to see if the string is empty
    bool check_empty_string(std:: string& playerName) {
        std:: string:: iterator itr;
        for (itr = playerName.begin(); itr != playerName.end(); ++itr) {
            if (!isblank(*itr)) {
                return false;
            }
        }
        return true;
    }

    // Function to trim the string from leading and trailing spaces
    void trim_string(std::string &str) {

        size_t firstNonSpace = str.find_first_not_of(' ');
        size_t lastNonSpace = str.find_last_not_of(' ');
        str = str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
    }

    // Function to get one valid integer from user input
    bool getValidInt(const std:: string& line, int&num) {
        std::stringstream parse(line);
        parse >> num;
        if (parse) {
            std::string leftover;
            parse >> leftover;
            if (not parse) {
                return true;
            }
        }
        return false;
    }

}






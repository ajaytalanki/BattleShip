#ifndef BATTLESHIP__INPUTVALIDATION_H_
#define BATTLESHIP__INPUTVALIDATION_H_
namespace BattleShip {
    char getValidChar(const std:: string& nameOfPlayer, const char& nameOfShip);
    bool checkHorizontalOrVertical(const char &characterInput);
    bool getValidInts(const std:: string& prompt, int &rowNumber, int &columnNumber);
    bool getValidInt(const std::string& line, int&num);
    bool checkBounds(const char &c, const int &rowInput, const int &colInput, const int &row, const int &col, const int& size);
    bool check_empty_string(std:: string& playerName);
    void trim_string(std::string& str);
}

#endif //BATTLESHIP__INPUTVALIDATION_H_

//
// Created by Ajay Talanki and Andy Lam on 5/5/2021.
//
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "readFile.h"
namespace BattleShip {
    // Function that extracts information from a file line by line
    void extractInfo(std::istream &aFile, int &rows, int &columns, std::map<char, int> &shipInfo) {
        std::string str;
        std::getline(aFile, str);
        rows = stoi(str);
        std::getline(aFile, str);
        columns = stoi(str);
        std::getline(aFile, str);
        while (std::getline(aFile,
                            str)) {  //  gets the ships from file and creates a map of ships paired by name and size
            std::stringstream parse_line(str);
            char c;
            int num;
            parse_line >> c >> num;
            shipInfo.insert({c, num});
        }
    }
}
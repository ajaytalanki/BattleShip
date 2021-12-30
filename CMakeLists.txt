cmake_minimum_required(VERSION 3.15)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Player.cpp Player.h Board.cpp Board.h inputValidation.cpp readFile.cpp readFile.h Game.cpp Game.h inputValidation.h HumanPlayer.cpp HumanPlayer.h AIPlayer.cpp AIPlayer.h CheatingAI.cpp CheatingAI.h RandomAI.cpp RandomAI.h SearchAndDestroyAI.cpp SearchAndDestroyAI.h)
target_compile_options(BattleShip PRIVATE -Wall -Werror -Wextra)
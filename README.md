# BattleShip

## Configuration  
The Configuration.txt file is the first and only command line argument of this program with the following layout:  
Number of rows in the board
Number of columns in the board  
Number of Ships    
Ship name, ship size  
Ship name, ship size  
(List all the ships) ...  

This is a BattleShip game with AIs that I coded using Object Oriented Programming and Inheritance in C++.
The program recieves a configuration file form the user that lists the number of rows and columns of the board, number of ships, and the name and size of each ship for the game. The program also accepts a seed for the random number generator for the AIs.
The game allows for three modes, Human vs Human, Human vs AI, and AI vs AI.
The AI's consist of Random AIs which randomly select positions to shoot at, Cheating AIs which automatically shoot at ships on your board, and SearchAndDestroy AIs that randomly shoot until they find a ship on your board, and then shoot at all positions around the first hit.
This project uses many foundational Object Oriented Programming principles as well as Inheritence and Polymorphism used for the AIs. This game involved the use of unique pointers as well as the use of different containers and modifying said containers using the algorithm library.


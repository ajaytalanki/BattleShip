# BattleShip

This is a BattleShip game with AIs that I coded using Object Oriented Programming and Inheritance in C++.
The program recieves a configuration file form the user that lists the number of rows and columns of the board, number of ships, and the name and size of each ship for the game. The program also accepts a seed for the random number generator for the AIs.
The game allows for three modes, Human vs Human, Human vs AI, and AI vs AI.
The AI's consist of Random AIs which randomly select positions to shoot at, Cheating AIs which automatically shoot at ships on your board, and SearchAndDestroy AIs that randomly shoot until they find a ship on your board, and then shoot at all positions around the first hit.
This project uses many foundational Object Oriented Programming principles as well as Inheritence and Polymorphism used for the AIs. This game involved the use of unique pointers as well as the use of different containers and modifying said containers using the algorithm library.

The configuration.txt passed into the command line arguments of this program is in this layout:
Rows of board \n
Columns of board \n
Number of Ships \n
Ship name, ship size \n
Ship name, ship size ... (List all the ships)

# BattleShip

## Configuration  
The Configuration.txt file is the first and only command line argument of this program with the following layout:  
Number of rows in the board
Number of columns in the board  
Number of Ships    
Ship name, ship size  
Ship name, ship size  
(List all the ships) ...  

## Game Modes  
There are 3 available game modes:  
1. Player vs Player - This game mode is played between two human players.  
2. Player vs AI - This game mode is played between the user and an AI.
3. AI vs AI - This game mode is played between two AI's.

## Different types of AI
1. Random AI - This bot randomly chooses a spot to shoot at on the board. This AI keeps track of previously fired shots and always fires at a new location.
2. SearchAndDestroy AI - This AI starts by randomly shooting at the board until the AI first hits a ship. Once a ship is hit, the AI shoots at the left, top, right, and bottom spaces around the ship respectively. This process repeats recursively.
3. Cheating AI - This AI always fires at a spot that is taken by a ship.

## Game Setup
1. Player vs Player mode - Player 1 is first asked to enter their username. Then, they are asked what coordinate and orientation each ship should be placed on their board. This process is repeated for Player 2.
2. Player vs AI mode - Only player 1 is asked for a username and board setup. The AI randomly places the ships on their board.
3. AI vs AI mode - Both AI bots randomly place the ships on their respective boards.

## Gameplay 
Each player takes turns firing shots at the other player's board. If the fire misses, a '0' is placed on the board at the specified coordinate. If the fire hits, a 'X' is placed on the coordinate. This process
is repeated until one player sinks all the other player's ships. 





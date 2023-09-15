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

## Gameplay  




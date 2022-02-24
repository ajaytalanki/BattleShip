OBJS	= main.o AIPlayer.o Board.o CheatingAI.o Game.o HumanPlayer.o Player.o RandomAI.o SearchAndDestroyAI.o inputValidation.o readFile.o
SOURCE	= main.cpp AIPlayer.cpp Board.cpp CheatingAI.cpp Game.cpp HumanPlayer.cpp Player.cpp RandomAI.cpp SearchAndDestroyAI.cpp inputValidation.cpp readFile.cpp
HEADER	= AIPlayer.h Board.h CheatingAI.h Game.h HumanPlayer.h Player.h RandomAI.h SearchAndDestroyAI.h inputValidation.h readFile.h
OUT	= BattleShip
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

AIPlayer.o: AIPlayer.cpp
	$(CC) $(FLAGS) AIPlayer.cpp

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp

CheatingAI.o: CheatingAI.cpp
	$(CC) $(FLAGS) CheatingAI.cpp

Game.o: Game.cpp
	$(CC) $(FLAGS) Game.cpp

HumanPlayer.o: HumanPlayer.cpp
	$(CC) $(FLAGS) HumanPlayer.cpp

Player.o: Player.cpp
	$(CC) $(FLAGS) Player.cpp

RandomAI.o: RandomAI.cpp
	$(CC) $(FLAGS) RandomAI.cpp

SearchAndDestroyAI.o: SearchAndDestroyAI.cpp
	$(CC) $(FLAGS) SearchAndDestroyAI.cpp

inputValidation.o: inputValidation.cpp
	$(CC) $(FLAGS) inputValidation.cpp

readFile.o: readFile.cpp
	$(CC) $(FLAGS) readFile.cpp


clean:
	rm *.o BattleShip
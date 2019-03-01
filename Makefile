CC=g++

main: main.cpp
	${CC} -std=c++11 main.cpp gameLogic.cpp player.cpp drawBoard.cpp gameDriver.cpp saveState.cpp inputValidation.cpp -o scrmWord 

clean:
	rm scrmWord

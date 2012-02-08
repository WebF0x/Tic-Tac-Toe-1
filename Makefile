CXX=g++
CXXFLAGS=-Wall

all: TicTacToe

TicTacToe: Best.o TicTacToeGame.o Tui.o
		$(CXX) $(CXXFLAGS) Best.o TicTacToeGame.o Tui.o -o TicTacToe

Best.o: Best.cpp Best.h
		$(CXX) $(CXXFLAGS) -c Best.cpp

TicTacToeGame.o: TicTacToeGame.cpp TicTacToeGame.h
		$(CXX) $(CXXFLAGS) -c TicTacToeGame.cpp

Tui.o: Tui.cpp Tui.h
		$(CXX) $(CXXFLAGS) -c Tui.cpp




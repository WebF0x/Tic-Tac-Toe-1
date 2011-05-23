/*
 * Tui.cpp
 *
 *  Created on: May 22, 2011
 *      Author: Jurre
 *
 *      Simple textual user interface to play the game
 */

#include "Tui.h"


Tui::Tui()
{
	do{
		TicTacToeGame t;
		std::cout << "***New Game***\n";
		t.toString(); //hack because otherwise board isn't printed correctly for the first move

		if(t.computerPlays()) 	std::cout << "I start:\n";
		else					std::cout << "You start:\n";
		while(!t.gameOver()){
			if(t.computerPlays()){
				int computerMove = t.chooseMove();
					t.playMove(computerMove);
					std::cout << "Computer move: " << computerMove << "\n";
				}
				else{
					int humanMove;
					do
					{
						std::cout << "Human move (0 to 8, you are "<< t.humanChar <<"):";
						std::cin >> humanMove;
					}
					while(!t.moveOk(humanMove));
					t.playMove(humanMove);
					}
			std::cout << t.toString();
		}
		std::cout << "Game over. " << t.winner() << " wins\n";
	}while (nextGame());
}

int main(){
	new Tui();
}

bool Tui::nextGame(){
        char yn;
        do
        {
            std::cout <<"Next Game? enter Y/N: ";
            std::cin >> yn;
            std::cout << "" << yn;
        }
        while  (!(yn=='Y' || yn=='y' || yn=='N' || yn=='n'));
        return yn=='Y'|| yn=='y';
}


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
	while (nextGame()) {
		TicTacToeGame * game = new TicTacToeGame(false);
		std::cout << "***New Game***\n";
		game->toString(); //hack because otherwise board isn't printed correctly for the first move

		if (game->computerPlays()) {
		    std::cout << "I start:\n";
	    }
		else {
		    std::cout << "You start:\n";
	    }
	    
		while(!game->gameOver()){
			if(game->computerPlays()){
				int computerMove = game->chooseMove();
					game->playMove(computerMove);
					std::cout << "Computer move: " << computerMove << "\n";
				}
				else{
					int humanMove;
                    do
					{
						std::cout << "Human move (0 to 8, you are "<< game->getHumanChar() <<"):";
						std::cin >> humanMove;
					}
					while(!game->moveOk(humanMove));
					game->playMove(humanMove);
				}
			std::cout << game->toString();
		}
		std::cout << "Game over. " << game->winner() << " wins\n";
		delete game;
	}
}

int main() {
	new Tui();
}

bool Tui::nextGame() {
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


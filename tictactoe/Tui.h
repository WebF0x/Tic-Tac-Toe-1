/*
 * Tui.h
 *
 *  Created on: May 22, 2011
 *      Author: Jurre
 */

#ifndef TUI_H_
#define TUI_H_
#include <iostream>
#include <string>
#include "TicTacToeGame.h"

class Tui {
public:
	Tui();
	int move();
	bool nextGame();
	TicTacToeGame t;
};

#endif /* TUI_H_ */

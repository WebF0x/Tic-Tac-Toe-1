/*
 * TicTacToeGame.h
 *
 *  Created on: May 21, 2011
 *      Author: Jurre
 */

#ifndef TICTACTOEGAME_H_
#define TICTACTOEGAME_H_

#include <iostream>
#include <string.h>
#include "Best.h"

class TicTacToeGame {

    public:
        enum Side { HUMAN, COMPUTER, EMPTY };
        enum PositionVal { HUMAN_WIN, DRAW, UNCLEAR, COMPUTER_WIN };
        TicTacToeGame(bool computerStarts);
        void setComputerPlays();
        void setHumanPlays();
        bool computerPlays();
        int chooseMove();
        bool moveOk(int move);
        void playMove(int move);
        std::string toString();
        bool gameOver();
        std::string winner();
        std::string getHumanChar();
        std::string getComputerChar();        
        int positionValue();
        void move();
        int side;
        int position;

    private:
        bool computerStarts;
        int board[3][3];
        Best chooseMove(int side);
        bool boardIsFull();
        bool isAWin(int side);
        void place(int row, int column, int piece);
        bool squareIsEmpty(int row, int column);
        void clearBoard();
        int piece;
};

#endif /* TICTACTOEGAME_H_ */

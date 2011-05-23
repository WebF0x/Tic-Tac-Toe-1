/*
 * TicTacToeGame.cpp
 *
 *  Created on: May 21, 2011
 *      Author: Jurre
 */

#include "TicTacToeGame.h"
#include <sstream>

TicTacToeGame::TicTacToeGame(bool computerStarts)
{
	clearBoard();
	this->computerStarts = computerStarts;
	side = computerStarts ? COMPUTER : HUMAN;
	
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
            board[row][col] = EMPTY;
	    }	
	}
}

std::string TicTacToeGame::getHumanChar() {
    return computerStarts ? "X" : "0" ;
}

std::string TicTacToeGame::getComputerChar() {
    return computerStarts ? "0" : "X" ;
}

bool TicTacToeGame::computerPlays(){
	return side == COMPUTER;
}

int TicTacToeGame::chooseMove(){
	Best best=chooseMove(COMPUTER);
	return best.row*3+best.column;
}

// minimax algorithm
Best TicTacToeGame::chooseMove(int s){
	int opp;              // Opponent
	Best reply(0);        // Opponent's best reply
	int simpleEval;       // Result of an immediate evaluation
	int value = -1;
	int bestRow = 0;
	int bestColumn = 0;

	if( s == COMPUTER )
	{
		opp = HUMAN;
		value = HUMAN_WIN;
	}
	else
	{
		opp = COMPUTER;
		value = COMPUTER_WIN;
	}

	//if current gamestate is a win or loss for the player (base case)
	if( ( simpleEval = positionValue() ) != UNCLEAR )
		return Best(simpleEval);

	for(int row = 0; row < 3 ; row++){
		for(int column = 0; column < 3; column ++){
			if( squareIsEmpty( row, column ) )
			{
				place( row, column, s );
				reply = chooseMove(opp);
				place( row, column, EMPTY );
				if( s == (COMPUTER && reply.value > value) || (s == HUMAN && reply.value < value) )
				{
					value = reply.value; bestRow = row; bestColumn = column;
				}
			}
		}
	}
	return Best(value, bestRow, bestColumn);
}

//check if the move is a valid move
bool TicTacToeGame::moveOk(int move){
	if(move>=0 && move<=8 && board[(int)move/3][move%3]==EMPTY){
		return true;
	}
	else{
		return false;
	}
}

void TicTacToeGame::playMove(int move){
	board[move/3][move%3] = side;
	if (side == COMPUTER) {
		side = HUMAN;
	}
	else {
		side = COMPUTER;
	}
}

void TicTacToeGame::clearBoard(){
    for( int row = 0; row < 3; row++ )
        for( int column = 0; column < 3; column++ )
            board[ row ][ column ] = EMPTY;
}

bool TicTacToeGame::boardIsFull(){
	for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (board[row][column] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

//check if the current side has won in the situation the board is in now
//could be implemented with two loops for rows and columns but removed it during debugging
bool TicTacToeGame::isAWin(int side){
	if(board[0][0] == side && board[0][1] == side && board[0][2] == side){
		return true;
	}
	if(board[1][0] == side && board[1][1] == side && board[1][2] == side){
		return true;
	}
	if(board[2][0] == side && board[2][1] == side && board[2][2] == side){
		return true;
	}
	if(board[0][0] == side && board[1][0] == side && board[2][0] == side){
		return true;
	}
	if(board[0][1] == side && board[1][1] == side && board[2][1] == side){
		return true;
	}
	if(board[0][2] == side && board[1][2] == side && board[2][2] == side){
		return true;
	}
	if( board[ 1 ][ 1 ] == side && board[ 2 ][ 2 ] == side && board[ 0 ][ 0 ] == side ){
		return true;
	}
	if( board[ 0 ][ 2 ] == side && board[ 1 ][ 1 ] == side && board[ 2 ][ 0 ] == side ){
		return true;
	}
	return false;
}

//places a piece on the board without checking
void TicTacToeGame::place(int row, int col, int piece){
	board[row][col] = piece;
}

bool TicTacToeGame::squareIsEmpty(int row, int col){
	return board[row][col] == EMPTY;
}

//returns a value for the current game state
int TicTacToeGame::positionValue(){
	return 	isAWin(COMPUTER)	? 	COMPUTER_WIN 	:
			isAWin(HUMAN)		?	HUMAN_WIN 		:
			boardIsFull()		? 	DRAW			: UNCLEAR;
}

//prints the board, seems to have a bug because i have to call this function once before printing it
//otherwise it doesn't display the first chosen move
std::string TicTacToeGame::toString(){
	std::string str;
	for(int row = 0; row < 3; row++){
			for(int col = 0; col < 3; col++){
				if(board[row][col]==EMPTY){
					str.append("---");
				}
				else if(board[row][col]==HUMAN){
					str.append("-");
					str.append(getHumanChar());
					str.append("-");
				}
				else if(board[row][col]==COMPUTER){
					str.append("-");
					str.append(getComputerChar());
					str.append("-");
				}
				if(col != 2){
					str.append("|");
				}
				else if(row != 2){
					str.append("\n---+---+---\n");
				}
			}
	}
	str.append("\n");
	return str;
}

bool TicTacToeGame::gameOver(){
	position=positionValue();
	return position!=UNCLEAR;
}

std::string TicTacToeGame::winner(){
    switch (position) {
        case COMPUTER_WIN:
            return "computer";
        case HUMAN_WIN:
            return "human";
        default:
            return "nobody";
    }
}

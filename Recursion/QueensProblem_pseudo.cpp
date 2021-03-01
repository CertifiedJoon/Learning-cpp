#include <iostream>
#include "simple.h"
#include "lexicon.h"

bool Solve(Grid<bool> &board, int col){
	if (col > board.numcols()) return true;
	
	for (int rowToTry = 0; rowToTry < board.numRows(); rowToTry++) {
		if (IsSafe(board, RowToTry, col)){
			PlaceQueen(board, rowToTry, col);
			if (Solve(board, col + 1)) return true;
			RemoveQueen(board, rowToTry,col);
		}
	}
	return false;
}

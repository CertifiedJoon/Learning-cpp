bool SolveSudoku(grid<int> & grid)
{
	int row, col;
	
	if(FindUnassignedLocation(grid, row, col))
		return true; //all slots assigned;
	
	for (int num = 1; nums <= 9; num++){
		if (NoConflicts(grid, row, col, num)){
			grid(row, col) = num;
			if(SolveSudoku(grid)) return true;
			grid(row, col) = UNASSIGNED;
		}
	}
	return false;
}

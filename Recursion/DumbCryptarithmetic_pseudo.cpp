bool Dumb_Cryptarithmetic(puzzleT puzzle, string lettersToAssign)
{
	if(lettersToAssign == "")
		return puzzleSolved(puzzle);
	
	for (int digit = 0; digit <= 9; digit++){
		if (AssignLetter(lettersToAssign[0], digit)){
			if (Dumb_Cryptarithmetic(puzzle, lettersToAssign.substr(1))) return true;
			UnassignLetter(lettersToAssign[0], digit);
		}
	}
	
	return false
}

/*
To make it smarter, 
dont wasate time on ridiculous choices, 
Assign S then assgine U now consider N --> will dramatically shorten the asymtotics

  CS
+YOU
----
 FUN

*/

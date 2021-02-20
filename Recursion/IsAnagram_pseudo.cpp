#include <iostream>
#include "simple.h"
#include "lexicon.h"

bool Is_Anagram(string SoFar, string rest, lexicon &lex)
{
	if (rest =="") return lex.containsWord(SoFar);
	
	else {
		for (int i = 0; i < rest.length(); ++i){
			string next = SoFar +rest [i];
			string remaining = rest.substr(0, i) + rest.substr(i + 1);
			if (IsAnagram(next, remaining, lex)) return true;
		}
	}
}

void IsAnagramWord(string s, lexicon &lex){
	return Is_Anagram("", x, lex);
}

int main(){
	lexicon lex("lexicon.dat");
	while (true){
		cout << "?";
		string s = getline();
		IsAnagramWord(s,lex);
	}
	return true;
}

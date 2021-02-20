#include <iostream>
#include <string>
using namespace std;

void RecSubsets(string, string);
void ListSubsets(string);


int main(int argc, char* argv[]) {
	
	string s = "abc";
	
	ListSubsets(s);
	return 0;
}

void RecSubsets(string SoFar, string rest){
	if (rest == "") 
		cout << SoFar << endl;
	else {
		//add to subset , remove from rest, recut.
		RecSubsets(SoFar + rest[0], rest.substr(1));
		//dont add to subset, remove from rest, rcur.
		RecSubsets(SoFar, rest.substr(1));
	}
}

void ListSubsets(string str){
	RecSubsets("", str);
}

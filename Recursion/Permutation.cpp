#include <iostream>
#include <string>
using namespace std;

void RecPermute(string, string);
void ListPermutations(string);

int main(int argc, char* argv[]) {
	
	string s = "abcd";
	
	ListPermutations(s);
	cout << endl;
	
	return 0;
}

void RecPermute(string SoFar, string rest)
{ 
	if (rest == "") {
		cout << SoFar << endl;
	} else {
		for (int i = 0; i < rest.length(); ++i){
			string next = SoFar + rest[i];
			string remaining = rest.substr(0,i) + rest.substr(i+1);
			RecPermute(next, remaining);
		}
	}
}

//wrapper
void ListPermutations(string s)
{
	RecPermute("", s);
}

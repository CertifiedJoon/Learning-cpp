#include <iostream>

using namespace std;

int bobProblem(int, int);

int main(int argc, int argv[]){
	cout << bobProblem(40, 5) << endl;
}

int bobProblem (int n, int k){
	if (k ==0 || k ==n)
		return 1;
	else return bobProblem(n-1,k) + bobProblem(n-1,k-1);
}

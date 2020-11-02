#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo{
    string name;
    vector<string> numbers;
}

int main(){
    string line, word;
    vector<PersonInfo> people;

    while(getline(cin, line)){
        PersonInfo person;
        istringstream iss(line);
        
        iss >> person.name;
        while(iss >> word)
            person.numbers.push_back(word);
        
        people.push_back(person);
    }
}
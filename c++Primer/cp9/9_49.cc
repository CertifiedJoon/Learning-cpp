#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    string word;
    string ascender("tiplkhfdb");
    string descender("qyjg");
    string maxWord;
    
    while(fin >> word)
    {
        if(word.find_first_of(ascender) == string::npos &&
           word.find_first_of(descender) == string::npos)
        {
            if (word.size() > maxWord.size())
                maxWord = word;
        }
    }

    fin.close();   
    cout << maxWord << endl;
}
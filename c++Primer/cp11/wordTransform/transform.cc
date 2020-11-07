#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

int main()
{
    map<string, string> badWords;
    ifstream fin("rule.txt");
    string bad, censored;

    while (fin >> bad && fin >> censored){
        badWords[bad] = censored;
    }
    fin.close();

    fin.open("input.txt");
    ofstream fout("output.txt");
    string line;
    ostream_iterator<string> fit(fout, " ");

    while (getline(fin, line)){
        istringstream stream(line);
        string word;
        while (stream >> word){
            if (badWords.find(word) != badWords.end())
                fit = badWords[word];
            else
                fit = word;
        }
        fout << endl;
    }
    fin.close();
}
#include <iostream>
#include <string>
using namespace std;
int main(){
    unsigned vCnt = 0, sCnt = 0, flCnt = 0, ffCnt = 0, fiCnt = 0;
    char c;
    constexpr char f = 'f';
    string line;

    while (getline(cin, line)){
        for (const auto &c : line){
            switch(c) {
                case 'a': case 'A':
                case 'i': case 'I':
                case 'e': case 'E':
                case 'u': case 'U':
                case 'o': case 'O':
                    ++vCnt;
                    break;
                case '\n': case ' ':
                case '\t':
                    ++sCnt;
                    break;
                case f:
                    {
                        char c2;
                        cin >> c2;
                        switch(c2){
                            case 'f':
                                ++ffCnt;
                                break;
                            case 'l':
                                ++flCnt;
                                break;
                            case 'i':
                                ++fiCnt;
                                break;
                        }
                    }
                default:
                    ;
            }
        }
    }

    cout << "vCount:  " << vCnt << endl
         << "sCount:  " << sCnt << endl
         << "ffCount: " << ffCnt << endl
         << "flCount: " << flCnt << endl
         << "fiCount: " << fiCnt << endl;
}

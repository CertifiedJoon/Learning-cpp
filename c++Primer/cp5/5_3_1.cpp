#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    vector<string> letter_grade = {"F", "D", "C", "B", "A", "A*", "A*"};
    int grade;
    string final_grade;

    cin >> grade;

    if (grade < 60){
        final_grade = letter_grade[0];
    } else if (grade == 100){
        final_grade = letter_grade[6];
    } else {
        final_grade = letter_grade[(grade - 50) / 10];
        if (grade % 10 < 4)
            final_grade += "-";
        else if (grade % 10 > 6)
            final_grade += "+";
    }

    cout << final_grade << endl;

    i

    return 0;
}

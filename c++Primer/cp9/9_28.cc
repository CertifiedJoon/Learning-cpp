#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

void find_n_insert(forward_list<string> &fs, const string &find, const string &ins){
    auto curr = fs.begin();
    auto prev = fs.before_begin();
    while (curr != fs.end()){
        if (*curr == find){
            fs.insert_after(curr, ins);
            return;
        }
        ++curr, ++prev;
    }

    fs.insert_after(prev, ins);
}


int main(){
    forward_list<string> flist {"string", "whatsya", "hayia"};

    find_n_insert(flist, "whatsya", "hello");
    find_n_insert(flist, "whatsa", "yes hell0");

    for (auto s : flist){
        cout << s<< endl;
    }
}
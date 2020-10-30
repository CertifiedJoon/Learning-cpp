#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> ivec(10);

    using v_size = vector<int>::size_type;

    v_size cnt = ivec.size();

    for(v_size ix = 0; ix != ivec.size(); ix++, cnt--){
        ivec[ix] = cnt;
    }

    for (const auto &i : ivec)
        cout << i << endl;
}

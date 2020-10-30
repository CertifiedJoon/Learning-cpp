#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> nums1 = {1,2,3,4,5,7};
    vector<int> nums2 = {1,2,3,4,5,6,7,85,4,3};

    using vit = vector<int>::iterator;

    vit b1 = nums1.begin(), b2 = nums2.begin();
    while (b1 != nums1.end() && b2 != nums2.end()){
        if (*b1 != *b2)
            break;
        ++b1, ++b2;
    }

    if (b1 != nums1.end() || b2 != nums2.end())
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

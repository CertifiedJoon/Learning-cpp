#include <iostream>
#include "blobptr.h"
#include "blob.h"

int main()
{
    Blob<int> vs{1,2,3,4,5,6,7,8,9,3,3,2,4};

    for(size_t i = 0; i != vs.size(); ++i)
        std::cout << vs[i] << std::endl;
}
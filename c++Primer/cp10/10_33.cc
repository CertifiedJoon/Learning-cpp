#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream fin(argv[1]);
    istream_iterator<int> in(fin), eof;

    ofstream oddOut(argv[2]);
    ofstream evenOut(argv[3]);
    ostream_iterator<int> odd(oddOut, " ");
    ostream_iterator<int> even(evenOut, "\n");

    while (in != eof){
        if (*in & 1)
            odd = *in++;
        else
            even = *in++;
    }
}
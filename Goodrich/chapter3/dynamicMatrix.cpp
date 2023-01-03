#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

int** dynamic_matrix(int n , int m) {
  int **M = new int*[n];
  for (int i = 0; i < n; i++)
    M[i] = new int[m];

  return M;
}

int destroy_matrix(int **M, int n) {
  for (int i = 0; i < n; i++)
    delete[] M[i];
  delete[] M;
  return EXIT_SUCCESS;
}

vector< vector<int> > vector_matrix(int n, int m) {
  vector< vector<int> > M(n, vector<int>(m));

  return M;
}

int main() {
  int n = 3, m = 3;
  int **M = dynamic_matrix(n, m);
  destroy_matrix(M, n);
  
  return EXIT_SUCCESS;
}
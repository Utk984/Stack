#include <iostream>
using namespace std;
#define N 4

bool M[N][N] = {{0, 1, 1, 1}, {0, 0, 1, 1}, {0, 0, 0, 0}, {0, 0, 1, 0}};

bool knows(int a, int b) { return M[a][b]; }

int celebrity(int n) {
  int i = 0, j = n - 1;
  while (i < j) {
    if (M[j][i] == 1)
      j--;
    else
      i++;
  }
  int candidate = i;

  for (i = 0; i < n; i++) {
    if (i != candidate) {
      if (M[i][candidate] == 0 || M[candidate][i] == 1)
        return -1;
    }
  }
  return candidate;
}

int main() {
  int n = 4;
  int id = celebrity(n);
  id == -1 ? cout << "No celebrity found" : cout << "Celebrity ID: " << id;
  cout << endl;
  return 0;
}

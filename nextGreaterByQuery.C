#include <iostream>
#include <stack>
using namespace std;

void next_greatest(int next[], int a[], int n) {
  stack<int> s;
  s.push(0);

  for (int i = 1; i < n; i++) {
    while (!s.empty()) {
      int cur = s.top();
      if (a[cur] < a[i]) {
        next[cur] = i;
        s.pop();
      } else
        break;
    }
    s.push(i);
  }

  while (!s.empty()) {
    int cur = s.top();
    next[cur] = -1;
    s.pop();
  }
}

int answer_query(int a[], int next[], int n, int index) {
  int position = next[index];

  if (position == -1)
    return -1;
  else
    return a[position];
}

int main() {

  int a[] = {3, 4, 2, 7, 5, 8, 10, 6};
  int n = sizeof(a) / sizeof(a[0]);
  int *next = new int[n];

  next_greatest(next, a, n);

  cout << answer_query(a, next, n, 3) << " ";

  cout << answer_query(a, next, n, 6) << " ";

  cout << answer_query(a, next, n, 1) << " " << endl;
}

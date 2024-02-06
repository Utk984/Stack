#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool findRedundant(string str) {
  stack<char> st;

  for (auto &ch : str) {
    if (ch == ')') {
      char top = st.top();
      st.pop();
      bool flag = true;

      while (!st.empty() and top != '(') {
        if (top == '+' || top == '-' || top == '*' || top == '/')
          flag = false;
        top = st.top();
        st.pop();
      }
      if (flag == true)
        return true;
    } else
      st.push(ch);
  }
  return false;
}

int main() {
  string str = "((a+b))";
  if (findRedundant(str))
    cout << str << " : Yes" << endl;
  else
    cout << str << " : No" << endl;
  return 0;
}

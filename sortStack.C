#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> tmpStack)
{
  cout << "Sorted numbers are:\n";
 
  while (!tmpStack.empty())
  {
    cout << tmpStack.top()<< " ";
    tmpStack.pop();
  }
  cout << endl;
}

stack<int> sortStack(stack<int> s)
{
  stack<int> temp;
  while(!s.empty())
  {
      int x = s.top();
      s.pop();
      while(!temp.empty() && x > temp.top())
      {
        s.push(temp.top());
        temp.pop();
      }
      temp.push(x);
    }
  return temp;
}

int main()
{
  stack<int> s;
  s.push(34);
  s.push(3);
  s.push(31);
  s.push(98);
  s.push(5);

  stack<int> tmpStack = sortStack(s);
  print(tmpStack);
}

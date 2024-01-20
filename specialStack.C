#include <iostream>
#include <stack>

using namespace std;

class specialStack {
  stack<int> s1,s2;
  public:
  void push(int);
  void pop();
  void top();
  void min();
};

void specialStack::push(int data)
{
  if(s1.empty()){
    s1.push(data);
    s2.push(data);
    return;
  }
  if(data>s2.top())
    s2.push(s2.top());
  else
    s2.push(data);
  s1.push(data);
}

void specialStack::pop()
{
  cout << "Element Popped: " << s1.top() << endl;
  s1.pop();
  s2.pop();
}

void specialStack::top()
{
  cout << "Top element: " << s1.top() << endl;
}

void specialStack::min()
{
  cout << "Minimum Element: " << s2.top() << endl;
}

int main()
{
  specialStack sp;

  sp.push(8);
  sp.push(2);
  sp.push(3);
  sp.push(1);
  sp.top();
  sp.min();
  sp.pop();
  sp.top();
  sp.min();
}

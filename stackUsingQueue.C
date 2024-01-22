#include <iostream>
#include <queue>

using namespace std;

class Stack{
  public:
  queue<int> q1,q2;
  
  void push(int);
  int pop();
  void top();
};

void Stack::push(int data)
{
  q1.push(data);
  while(!q2.empty())
  {
    q1.push(q2.front());
    q2.pop();
  }
  q1.swap(q2);
}

int Stack::pop()
{
  int num = q2.front();
  q2.pop();
  return num;
}

void Stack::top()
{
  cout << "Top element: " << q2.front() << endl;
}

int main()
{
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.top();
 
  cout << "Element popped: " << s.pop() << endl;;
  cout << "Element popped: " << s.pop() << endl;;
  s.show();

  s.push(5);
  s.push(6);
  s.top();
 
  return 0;
}

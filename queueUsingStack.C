#include <iostream>
#include <stack>

using namespace std;

class Queue{
  public:
  stack<int> s1,s2;
  
  void enQueue(int);
  int deQueue();
};

void Queue::enQueue(int data)
{
  s1.push(data);
}

int Queue::deQueue()
{
  if(s2.empty()){
    while(!s1.empty()){
      s2.push(s1.top());
      s1.pop();
    }
  }
  int num = s2.top();
  s2.pop();
  return num;
}

int main()
{
  Queue q;
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
 
  cout << q.deQueue() << '\n';
  cout << q.deQueue() << '\n';

  q.enQueue(5);
  q.enQueue(6);
 
  cout << q.deQueue() << '\n';
  cout << q.deQueue() << '\n';
  cout << q.deQueue() << '\n';
 
  return 0;
}

#include <iostream>
#include <stack>

using namespace std;

void printNGE(int arr[], int n)
{
  stack<int> s;
  s.push(arr[0]);
  for(int i=1; i<n; i++)
  {
    if(arr[i]>s.top())
    {
      while(!s.empty())
      {
        cout << s.top() << " --> " << arr[i] << endl;
        s.pop();
      }
    }
    s.push(arr[i]);
  }

  while (s.empty() == false) 
  {
    cout << s.top() << " --> " << -1 << endl;
    s.pop();
  }
}

int main()
{
  int arr[] = {11,13,21,3};
  int n = sizeof(arr) / sizeof(arr[0]);
  printNGE(arr, n);
  return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int getMaxArea(int hist[], int n)
{
    int i=0, maxArea=0, area;
    stack<int> s;
    while(i<n)
    {
        if(s.empty() || hist[i]>hist[s.top()])
            s.push(i++);
        else
        {
            int ele = s.top();
            s.pop();
            area  = hist[ele] * (s.empty() ? i : i - s.top() - 1); 
        
            if (maxArea < area)
                maxArea = area;
        }
    }

    while (s.empty() == false) { 
        int ele = s.top(); 
        s.pop(); 
        area = hist[ele] * (s.empty() ? i : i - s.top() - 1); 
  
        if (maxArea < area) 
            maxArea = area;
    } 
  
    return maxArea;
}

int main()
{
    int hist[] = { 6, 2, 4, 3, 4, 1, 6 }; 
    int n = sizeof(hist) / sizeof(hist[0]); 
  
    cout << "Maximum area is " << getMaxArea(hist, n) << endl; 
    return 0;
}

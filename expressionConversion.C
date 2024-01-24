#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Expression
{
  public:
    string PrefixToInfix(string);
    string InfixToPostfix(string);
    string PostfixToPrefix(string);
};

string Expression::PrefixToInfix(string str)
{
  stack<string> s1;
  string result1;

  int l = str.length();
  for (int i = l-1; i >= 0 ; i--){
    char ch = str.at(i);
    if(isalpha(ch))
      s1.push(string(1,ch));
    else
    {
      string ch1 = s1.top(); s1.pop();
      string ch2 = s1.top(); s1.pop();
      result1 = "(" + ch1 + ch + ch2 + ")";
      s1.push(result1);
    }
  }
  return s1.top();
}

string Expression::InfixToPostfix(string str)
{
  stack<string> s1;
  string result = "";

  int l = str.length();
  for (int i = 0; i < l ; i++){
    char ch = str.at(i);
    if(ch!=')')
      s1.push(string(1,ch));
    else
    {
      string ch1 = s1.top(); s1.pop();
      string ch2 = s1.top(); s1.pop();
      string ch3 = s1.top(); s1.pop(); s1.pop();
      result = ch3 + ch1 + ch2;
      s1.push(result);
    }
  }
  return s1.top();
}

string Expression::PostfixToPrefix(string str)
{
  stack<string> s1;
  string result1;

  int l = str.length();
  for (int i = 0; i < l; i++){
    char ch = str.at(i);
    if(isalpha(ch))
      s1.push(string(1,ch));
    else
    {
      string ch1 = s1.top(); s1.pop();
      string ch2 = s1.top(); s1.pop();
      result1 = ch + ch2 + ch1;
      s1.push(result1);
    }
  }
  return s1.top();
}

int main()
{
  string str; 
  cout << "Enter Expression: ";
  cin >> str;

  Expression exp;
  string result = exp.PrefixToInfix(str);
  cout << "Infix: " << result << endl;
  result = exp.InfixToPostfix(result);
  cout << "Postfix: " << result << endl;
  result = exp.PostfixToPrefix(result);
  cout << "Prefix: " << result << endl;

  return 0;
}

/*
Problem: Lucky Division
https://codeforces.com/problemset/problem/122/A
--------------------------------------------------------------------------------------------------------------------------------------------
Solution:
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long
#define endl "\n"

bool IsLucky(string s)
{
  for(char c: s)
  if(c!='4' and c!='7')
  return false;
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin>>n;
  for(int i=1;i*i<=n;i++)
  {
    if(n%i==0)
    {
      string div1=to_string(i),div2=to_string(n/i);
      if(IsLucky(div1) or IsLucky(div2))
      return cout<<"YES",0;

    }
  }
  cout<<"NO";
  
    return 0;
}
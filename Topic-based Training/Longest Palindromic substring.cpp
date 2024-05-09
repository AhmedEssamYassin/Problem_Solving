#include <iostream>
#include <string>
using namespace std;
bool Pal(string s)
{
    int j=s.size()-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[j])
        return false;
        j--;
    }
    return true;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s,r,t="";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        
        for(int j=i+1;j<=s.length();j++)
        {
            r=s.substr(i,j-i);
            if(Pal(r))
            {
                if(r.size()>t.size())
                t=r;
            }
        }
    }
    cout<<t;
    return 0;
}
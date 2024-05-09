#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int>LN;
    for(int i=1;i<=n;i++)
    {
        int nfs=0;
        int quo=i,digit;
        while(quo!=0)
        {
            digit=quo%10;
            if(digit!=4&&digit!=7)
            {
                nfs++;
                break;
            }
            quo/=10;
        }
        if(!nfs)
        LN.push_back(i);
    }
    for(int i=0;i<LN.size();i++)
    {
        if(LN[i]==n)
        {
            cout<<"YES";
            return 0;
        }
        if(n%LN[i]==0)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
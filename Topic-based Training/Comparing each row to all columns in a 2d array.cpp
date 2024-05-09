#include <iostream>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cin>>arr[i][j];
    }
    
    int cnt{};
    
    for(int i=0;i<n;i++)
    {
        int t=n,k=0;
        while(t--)
        {
            int temp{};
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==arr[j][k])
                temp++;
            }
            if(temp==n)
            cnt++;
            
            k++;
        }
    }
    cout<<cnt;
    return 0;
}
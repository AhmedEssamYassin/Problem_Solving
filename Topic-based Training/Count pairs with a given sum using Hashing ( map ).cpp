#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    sort(arr,arr+n);
    ll sum=arr[0]+arr[n-1];
    map<int,int>M;
    for(int i=0;i<n;i++)
    {
    	M[arr[i]]++;//counts and stores the frequency (number of occurrences ) of each number
    }
    ll cnt{};
    for(int i=0;i<n;i++)
    {
    	cnt+=M[sum-arr[i]];//(Notice that every pair is counted twice)
    	
    	if(sum-arr[i]==arr[i])//if (arr[i], arr[i]) pair satisfies the condition, then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i]) pair is not considered 
        //because we count the number of ordered pairs of indices i,j such that i≠j
    	cnt--;
    }
    cout<<cnt/2;
    return 0;
}
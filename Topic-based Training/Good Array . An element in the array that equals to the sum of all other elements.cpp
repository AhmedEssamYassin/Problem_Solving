/*
Good Array: an array is good if there is an element in the array that equals to the sum of all other elements. For example, the array a=[1,3,3,7] is good because there is the element a[3]=7 which equals to the sum 1+3+3

Your task is to print all indices j of this array such that after removing the j-th element from the array it will be good; such indices are called nice
*/

#include <iostream>
#include <map>
#include <set>
#include <algorithm> 
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
	map<int,int>mp;
	set<int>indices;
	ll sum{};
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		mp[arr[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		ll temp=sum-arr[i];
		mp[arr[i]]--;
		if(temp%2==0 and temp/2 <=1e6 and mp[temp/2]>0)
		indices.insert(i+1);
		++mp[arr[i]];
	}
	cout<<indices.size()<<endl;
	for(int ans:indices)
	cout<<ans<<" ";
	return 0;
}
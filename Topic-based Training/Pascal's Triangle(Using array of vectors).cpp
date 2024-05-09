#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<ll>arr[n];
	arr[0].push_back(1);
	
	for(int i=1;i<n;i++)
	{
		arr[i].push_back(1);
		for(int j=2;j<=i;j++)
		{
			arr[i].push_back(arr[i-1][j-2]+arr[i-1][j-1]);
		}
		arr[i].push_back(1);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i].size();j++)
		cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

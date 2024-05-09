#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,x,y;
    cin>>n>>m>>x>>y;//x and y are 1-indexed 
    int arr[n][m];//n is the number of rows and m is the number of columns
    x--,y--;//to make x and y 0-indexed 
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cin>>arr[i][j];
    	}
    }
    for(int i=0;i<m;i++)//swapping two rows x and y
	{
		swap(arr[x][i],arr[y][i]);
	}
	for(int i=0;i<n;i++)//swapping two columns x and y
	{
		swap(arr[i][x],arr[i][y]);
	}
	
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		cout<<arr[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}
/*
 An array of vectors is two dimensional array with fixed number of rows where each row is a vector of variable length.
 Each index of array stores a vector which can be traversed and accessed using iterators.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int>arr[5];//declaring an array containing five vectors of variable length 
    
    //arr[0], arr[1], arr[2] and so on are all vectors so the same methods of the class apply to them 
    //in other words we can use all methods like at(), front(), back(), push_back(), pop_back(), insert(), swap()
    //erase(), clear(), empty(), size(), resize(), etc.
    
    //initializing all vectors
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        arr[i].push_back(j);
    }
    //we can access elements stored in the vectors as if we were accessing the rows of a 2d array
    for(int i=0;i<5;i++)
    {
        cout<<"elements in the "<<i+1;
        if(i==0)
        cout<<"st";
        else if(i==1)
        cout<<"nd";
        else if(i==2)
        cout<<"rd";
        else
        cout<<"th";
        cout<<" vector are: ";
        
        for(int j=0;j<arr[i].size();j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
/*
Problem: Team Olympiad
https://codeforces.com/problemset/problem/490/A
-------------------------------------------------------------------------------------------------------------------------------------------------------------
Solution:
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define endl "\n"

bool comp(vector<int> v1, vector<int> v2)
{
    return v1.size() < v2.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,t;
	cin>>n;
	vector<int>arr[3];//array of 3 vectors, it means three rows but each row is of a variable size 
	//each row represents one of the t's: 1, 2 or three but (0-indexed), i.e, 0, 1 and 2 
	//in each row (vector), we will push values representing the indices (1-indexed) of occurrence of 0, 1 and 2 (previously denoted as 1, 2 and 3)
	//
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		arr[t-1].push_back(i);
	}
	
	sort(arr,arr+3,comp);//sorting the array in ascending order on basis of the size of its vectors
	int cnt=arr[0].size();//the minimum occurrence of 0, 1 and 2 
	//Because we can ONLY make a number of STH equal to the minimum quantity of one of its needed components 
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	{
		cout<<arr[0][i]<<" "<<arr[1][i]<<" "<<arr[2][i]<<endl;
	}
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------------
Another Solution using a MAP:
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,t;
	cin>>n;
	map<int,vector<int>>mp;//Maps every t with the indices of occurrence (1-indexed) 
	
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[t].push_back(i);
	}
	int cnt=min(min(mp[1].size(),mp[2].size()),mp[3].size());//gets the minimum occurrence of 1, 2 and 3 
	//Because we can ONLY make a number of STH equal to the minimum quantity of one of its needed components 
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
	{
		cout<<mp[1][i]<<" "<<mp[2][i]<<" "<<mp[3][i]<<endl;
	}
    return 0;
}
*/
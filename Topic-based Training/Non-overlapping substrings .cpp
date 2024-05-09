#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin>>s;
	vector<int>V1,V2;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='A')
		{
			if(s[i+1]=='B')
			V1.push_back(i);//stores the index of occurrencies of "AB"
		}
		if(s[i]=='B')
		{
			if(s[i+1]=='A')
			V2.push_back(i);//stores the index of occurrencies of "BA"
		}
	}
	for(int i=0;i<V1.size();i++)
	{
		for(int j=0;j<V2.size();j++)
		{
			if( V1[i]+1!=V2[j] and V1[i]!=V2[j]+1 )//checks if there exists a substring "AB" with a non-overlapping 'B' with the next substring "BA"
			// and also a non-overlapping 'A' with the prevoius substring "BA" (RESPECTIVELY)
			return cout<<"YES",0;
		}
	}
	cout<<"NO";
	
	return 0;
}
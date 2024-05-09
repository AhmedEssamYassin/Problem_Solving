#include <iostream>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
  
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//nCr=n!/((n-r)!*r!)
	ll n,m,Div,rem,min,max,min_Ans,max_Ans;
	cin>>n>>m;
	if(m==1)
	{
		ll ans=n*(n-1)/2;//n!/((n-2)!*2!)
		cout<<ans<<" "<<ans<<endl;
	}
	else
	{
		//minimum number of friendships can be achieved if teams filled equally with participants then, if remainder exists, it's added to teams one by one then 				calculated separately from other teams.
		//maximum number of friendships can be achieved if we fill a team with n-m+1 then fill all other teams one by one
		Div=n/m;
		rem=n%m;
		min=n-((m-1)*2);
		max=n-m+1;
		max_Ans=max*(max-1)/2;
		min_Ans=rem*(Div+1)*Div/2;
		min_Ans+=(m-rem)*Div*(Div-1)/2;
		cout<<min_Ans<<" "<<max_Ans<<endl;
	}
	
    return 0;
}
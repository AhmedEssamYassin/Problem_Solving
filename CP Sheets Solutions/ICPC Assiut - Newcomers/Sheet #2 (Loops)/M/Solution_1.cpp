#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

bool Is_Lucky(string S)
{
	for (const char &C : S)
		if (C != '4' and C != '7')
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	ll a, b;
	cin >> a >> b;
	vector<ll> Ans; // To store lucky numbers in the interval [a, b]
	for (int i = a; i <= b; i++)
	{
		string S = to_string(i);
		if (Is_Lucky(S))
			Ans.push_back(i);
	}
	if (Ans.empty()) // If there is NO lucky numbers in this interval
		cout << -1;
	else
	{
		for (const ll &Lucky_Number : Ans)
			cout << Lucky_Number << " ";
	}
	return 0;
}
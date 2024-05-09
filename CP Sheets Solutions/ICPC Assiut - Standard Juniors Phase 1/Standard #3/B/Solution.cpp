#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int N, Q, X;
	cin >> N >> Q;
	map<string, ll> mp;
	string Name;
	int Money;
	while (N--)
	{
		cin >> Name >> Money;
		mp[Name] = Money;
	}
	while (Q--)
	{
		cin >> X;
		if (X == 1)
		{
			cin >> Name >> Money;
			mp[Name] += Money;
		}
		else if (X == 2)
		{
			cin >> Name;
			cout << mp[Name] << endl;
		}
	}

	return 0;
}
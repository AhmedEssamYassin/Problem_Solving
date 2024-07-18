#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll bigMod(const string &num, ll x)
{
	// Initialize result
	ll res = 0;

	// One by one process all digits of 'num'
	for (ll i = 0; i < num.length(); i++)
	{
		res = (res * 10 + num[i] - '0');
		res %= x;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, x;
	// cin >> t;
	while (t--)
	{
		string n;
		cin >> n >> x;
		if (bigMod(n, x) == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}
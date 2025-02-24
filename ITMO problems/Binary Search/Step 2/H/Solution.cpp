#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
For a value K to be a valid answer, it should either:
1. K * mp['B'] <= N_bread && K * mp['S'] <= N_sausage && K * mp['C'] <= N_cheese
or Rubles should be enough to compensate the deficit
2. Rubles -= deficit * Price should be >= 0
*/

ll Rubles;
vector<ll> price(3), have(3), amount(3);
bool isOk(ll K)
{
	ll money = Rubles;
	for (int i = 0; i < 3; i++)
	{
		if (K * amount[i] > have[i])
			money -= (K * amount[i] - have[i]) * price[i];

		if (money < 0)
			return false;
	}
	return true;
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
	ll N, K;
	// cin >> t;
	while (t--)
	{
		string recipe;
		cin >> recipe;
		string pos("BSC"); // B is 0, S is 1 and C is 2
		for (const char &C : recipe)
			amount[pos.find(C)]++;

		// Stores the amount we actually have of every component
		for (int i = 0; i < 3; i++)
			cin >> have[i];
		// Stores the price of every component
		for (int i = 0; i < 3; i++)
			cin >> price[i];

		cin >> Rubles;

		ll L{}, R{1LL << 50}, ans{}, mid;
		while (L <= R)
		{
			mid = L + ((R - L) >> 1);
			if (isOk(mid)) // All before mid is also OK.
			{
				ans = mid;	 // A candidate solution
				L = mid + 1; // Search for a better (larger) answer
			}
			else // All after mid is NOT OK, either.
				R = mid - 1;
		}
		cout << ans;
	}
	return 0;
}
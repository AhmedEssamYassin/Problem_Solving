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
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, m, k, x, y, c;
	// cin >> t;
	while (t--)
	{
		/*
		The ONLY things affect our decision are:
		1. What are the dishes we have eaten before, because we cannot eat a dish twice
		2. What is the right previous dish? to check if it has an extra satisfaction
		*/
		cin >> N >> m >> k;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];

		vector<vector<ll>> extra(20, vector<ll>(20, 0));
		for (int i{}; i < k; i++)
		{
			cin >> x >> y >> c;
			x--, y--;
			extra[x][y] = c;
		}
		vector<vector<ll>> dp((1 << N), vector<ll>(N + 1, LLONG_MIN));
		for (int i{}; i < N; i++)
			dp[1 << i][i] = a[i];
		for (int i{1}; i < (1 << N); i++)
		{
			for (int j{}; j < N; j++)
			{
				if (i & (1LL << j))
					for (int k{}; k < N; k++)
					{
						if (!(i & (1LL << k)))
						{
							ll newMask = (i | (1LL << k));
							ll prev = dp[i][j] + a[k] + extra[j][k];
							dp[newMask][k] = max(prev, dp[newMask][k]);
						}
					}
			}
		}
		ll ans{};
		for (int bitmask{}; bitmask < (1 << N); bitmask++)
		{
			if (__popcount(bitmask) == m)
				ans = max(ans, *max_element(dp[bitmask].begin(), dp[bitmask].end()));
		}
		cout << ans;
	}
	return 0;
}
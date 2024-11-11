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
	ll N, m, k;
	// cin >> t;
	while (t--)
	{
		cin >> N >> m >> k;
		vector<ll> a(N), scanLine(N + 1, 0), occ(m + 1, 0);
		vector<tuple<ll, ll, ll>> op;
		for (int i{}; i < N; i++)
			cin >> a[i];

		for (int i{}; i < m; i++)
		{
			ll L, R, d;
			cin >> L >> R >> d;
			L--, R--;
			op.push_back({L, R, d});
		}

		while (k--)
		{
			ll x, y;
			cin >> x >> y;
			x--, y--;
			occ[x]++;
			occ[y + 1]--;
		}
		for (int i{1}; i <= m; i++)
			occ[i] += occ[i - 1];
		for (int i{}; i < m; i++)
		{
			const auto &[L, R, d] = op[i];
			scanLine[L] += occ[i] * d;
			scanLine[R + 1] -= occ[i] * d;
		}
		for (int i{1}; i <= N; i++)
			scanLine[i] += scanLine[i - 1];

		for (int i{}; i < N; i++)
			cout << a[i] + scanLine[i] << " ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Ok(const ll &N, const ll &X, const ll &Y, ll val)
{
	ll copyCount{};
	val -= min(X, Y);
	copyCount++;
	copyCount += (val / X) + (val / Y);
	return (copyCount >= N);
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
	ll N, X, Y;
	// cin >> t;
	while (t--)
	{
		cin >> N >> X >> Y;
		if (N == 1)
			return cout << min(X, Y), 0;
		ll L{}, R{(1LL << 40)}, ans;
		while (L <= R)
		{
			ll mid = (L + ((R - L) >> 1));
			if (Ok(N, X, Y, mid))
				ans = mid, R = mid - 1; // Search smaller answer (Less time)
			else
				L = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Ok(ll w, ll h, ll N, ll mid)
{
	return (__int128_t(mid / w) * (mid / h) >= N);
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
	ll w, h, N;
	// cin >> t;
	while (t--)
	{
		cin >> w >> h >> N;
		ll L{}, R = (1LL << 62);
		ll ans{1};
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (Ok(w, h, N, mid))
			{
				ans = mid;	 // A candidate answer
				R = mid - 1; // Search for a better answer
			}
			else
				L = mid + 1; // Search for a valid answer (larger length)
		}
		cout << ans;
	}
	return 0;
}
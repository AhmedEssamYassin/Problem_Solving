#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// #define endl "\n"

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
	cin >> t;
	while (t--)
	{
		auto Ask = [&](ll k, ll left, ll right)
		{
			cout << "? " << k << " ";
			for (int i = left; i <= right; i++)
				cout << i + 1 << " ";
			cout << endl;
			ll x;
			cin >> x;
			return x;
		};
		cin >> N;
		vector<ll> a(N), pref(N, 0);
		for (int i{}; i < N; i++)
		{
			cin >> a[i];
			if (!i)
				pref[i] = a[i];
			else
				pref[i] = pref[i - 1] + a[i];
		}

		ll L = 0, R = N - 1;
		ll ans = 0;
		while (L <= R)
		{
			ll mid = (L + R) / 2;
			ll W = Ask(mid - L + 1, L, mid);
			if (W == pref[mid] - (L > 0 ? pref[L - 1] : 0))
				L = mid + 1;
			else
				ans = mid + 1, R = mid - 1;
		}
		cout << "! " << ans << endl;
	}
	return 0;
}
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
	ll n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<ll> a(n);
		for (int i{}; i < n; i++)
			cin >> a[i];
		// Using this operation, we can always reach an element that is the AND of the whole array
		// (ans & x) <= ans, so it's most useful to bitwise AND the whole array
		ll ans = -1;
		for (int i{}; i < n; i++)
			ans &= a[i];
		cout << ans << endl;
	}
	return 0;
}
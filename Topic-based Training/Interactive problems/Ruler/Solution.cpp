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
		auto Ask = [&](ll x, ll y)
		{
			cout << "? " << x << " " << y << endl;
			ll p;
			cin >> p;
			return p;
		};
		ll L = 0, R = 1000;
		ll ans;
		while (L + 1 < R)
		{
			ll a = (2 * L + R) / 3;
			ll b = (L + 2 * R) / 3;
			ll area = Ask(a, b);
			if (area == a * b) // Both a and b are correct
				L = b;
			else if (area == a * (b + 1)) // a is correct but b is wrong
				ans = b, L = a, R = b;
			else // Both a and b are incorrect
				ans = a, R = a;
		}
		cout << "! " << ans << endl;
	}
	return 0;
}
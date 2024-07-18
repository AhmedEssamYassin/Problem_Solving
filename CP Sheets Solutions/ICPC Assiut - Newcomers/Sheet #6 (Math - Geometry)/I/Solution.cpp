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
	ll N, L, R, X;
	// cin >> t;
	while (t--)
	{
		cin >> L >> R >> X;
		if (L > R)
			swap(L, R); // Now L <= R
		// Σ X.i = X * Σi
		// Number of multiples of X <= R is u = (R / X)
		// Number of multiples of X <= (L - 1) is v = ((L - 1) / X)
		ll u = (R / X), v = (L - 1) / X;
		cout << X * (u * (u + 1) / 2 - v * (v + 1) / 2);
	}
	return 0;
}
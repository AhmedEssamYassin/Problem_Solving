#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll Pow(ll N, ll power)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res *= N;
		N *= N;
		power >>= 1;
	}
	return res;
}

ll F(ll X, ll N)
{
	if (X == 0 || N == 0)
		return 0;
	// Geometric sequence
	// a * (1 - r^n) / (1 - r)
	N >>= 1; // To represent number of terms
	if (X == 1)
		return N;
	return (X * X * (1 - Pow(X * X, N)) / (1 - X * X));
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
	ll N, X;
	// cin >> t;
	while (t--)
	{
		cin >> X >> N;
		cout << F(X, N);
	}
	return 0;
}
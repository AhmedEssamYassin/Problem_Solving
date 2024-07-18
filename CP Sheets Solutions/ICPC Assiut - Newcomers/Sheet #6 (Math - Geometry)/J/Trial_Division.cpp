#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

void primeFactorize(ll N)
{
	for (ll p{2}; p * p <= N && N > 1; p++)
	{
		ll power{};
		while (N % p == 0)
			N /= p, power++;
		if (power)
		{
			cout << "(" << p << "^" << power << ")";
			if (N > 1)
				cout << "*";
		}
	}
	if (N > 1)
		cout << "(" << N << "^" << 1 << ")";
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		primeFactorize(N);
	}
	return 0;
}
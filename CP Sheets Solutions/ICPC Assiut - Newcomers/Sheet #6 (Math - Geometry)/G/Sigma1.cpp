#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

map<ll, ll> Prime_factorize(ll N)
{
	map<ll, ll> primeFactors;
	while (!(N & 1))
		primeFactors[2]++, N >>= 1;
	for (ll p{3}; p * p <= N && N > 1; p += 2)
	{
		while (N % p == 0)
			primeFactors[p]++, N /= p;
	}
	if (N > 1)
		primeFactors[N]++;
	return primeFactors;
}

ll sigma_1(ll N)
{
	if (N == 1)
		return 1;

	ll sigma{1};
	map<ll, ll> primeFactors = Prime_factorize(N);
	for (auto &&[prime, power] : primeFactors)
	{
		ll val = (powl(prime, power + 1) - 1) / (prime - 1);
		sigma *= val;
	}
	return sigma;
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
		cout << sigma_1(N);
	}
	return 0;
}
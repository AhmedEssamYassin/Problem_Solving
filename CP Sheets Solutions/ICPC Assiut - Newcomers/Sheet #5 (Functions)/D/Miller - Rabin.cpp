#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll mult64(const ll &a, const ll &b, const ll &mod)
{
	return (__int128_t(a) * b % mod);
}

ll modBinExp(ll N, ll power, ll mod)
{
	if (N % mod == 0 || N == 0)
		return 0;
	if (N == 1 || power == 0)
		return 1;

	if (N >= mod)
		N -= mod;

	ll res{1};
	while (power)
	{
		if (power & 1) // ODD
			res = mult64(res, N, mod);

		N = mult64(N, N, mod);
		power >>= 1;
	}
	return res;
}

bool Check_Composite(ll N, ll a, ll d, int s)
{
	ll X = modBinExp(a, d, N);
	if (X == 1 || X == N - 1)
		return false; // Not composite

	for (int r = 1; r < s; r++)
	{
		X = mult64(X, X, N);
		if (X == 1 || X == N - 1)
			return false; // Not composite
	}
	return true; // Composite
}

bool Miller_Rabin(ll N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
	ll d = N - 1;
	int s = 0;
	while (!(d & 1))
		s++, d >>= 1;

	for (const ll &a : {11, 13, 17, 19, 23, 29, 31, 37, 73})
	{
		if (N == a)
			return true;
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

template <typename T>
bool isPrime(const T &N)
{
	if (N < 2)
		return false;

	if (N <= 3)
		return true;
	if (N == 5 || N == 7)
		return true;

	if (!(N & 1) || N % 3 == 0 || N % 5 == 0 || N % 7 == 0)
		return false;

	return Miller_Rabin(N);
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
	cin >> t;
	while (t--)
	{
		cin >> N;
		if (isPrime(N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
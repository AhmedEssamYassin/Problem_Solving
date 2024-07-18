#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

template <typename T>
T mult64(T a, T b, T mod)
{
	return (__int128_t)a * b % mod;
}

template <typename T>
inline T F(T x, T c, T mod) // Pollard-rho function
{
	return (mult64(x, x, mod) + c) % mod;
}

template <typename T>
inline T __abs(T N)
{
	if (N < 0)
		return -N;

	return N;
}

template <typename T>
T Pollard_Brent(T N)
{
	if (!(N & 1))
		return 2;

	// Random Number Linear Congruential Generator MMIX from D.E. Knuth
	static uint64_t rng = 0xdeafbeefff;
	uint64_t a = rng * 6364136223846793005ull + 1442695040888963407ull;
	uint64_t b = a * 6364136223846793005ull + 1442695040888963407ull;
	rng = (a + b) ^ (a * b);

	T X0 = 1 + a % (N - 1);
	T C = 1 + b % (N - 1);
	T X = X0; // X1
	T gcd_val = 1;
	T q = 1;
	T Xs, Xt;
	T m = 128;
	T L = 1;
	while (gcd_val == 1)
	{
		Xt = X;
		for (size_t i = 1; i < L; i++)
			X = F(X, C, N);

		int k = 0;
		while (k < L && gcd_val == 1)
		{
			Xs = X;
			for (size_t i = 0; i < m && i < L - k; i++)
			{
				X = F(X, C, N);
				q = mult64(q, __abs(Xt - X), N);
			}
			gcd_val = __gcd(q, N);
			k += m;
		}
		L += L;
	}
	if (gcd_val == N) // Failure
	{
		do
		{
			Xs = F(Xs, C, N);
			gcd_val = __gcd(__abs(Xs - Xt), N);
		} while (gcd_val == 1);
	}
	return gcd_val;
}

template <typename T>
T Mod_Bin_Exp(T N, T power, T mod) //(N^power) % mod
{
	if (N % mod == 0 || N == 0)
		return 0;
	if (N == 1 || power == 0)
		return 1;

	if (N >= mod)
		N -= mod;

	T res{1};
	while (power)
	{
		if (power & 1) // ODD
			res = mult64(res, N, mod);

		N = mult64(N, N, mod);
		power >>= 1;
	}
	return res;
}

template <typename T>
bool Check_Composite(T N, T a, T d, int s)
{
	T X = Mod_Bin_Exp(a, d, N);
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

template <typename T>
bool Miller_Rabin(T N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
	T d = N - 1;
	int s{};
	while (!(d & 1))
		d >>= 1, ++s;

	for (const T &a : {11, 13, 17, 19, 23, 29, 31, 37})
	{
		if (N == a)
			return true;
		if (Check_Composite(N, a, d, s))
			return false;
	}
	return true;
}

template <typename T>
bool isPrime(T N)
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

template <typename T>
void Factor(T N, map<T, int> &Prime_factors)
{
	if (N == 1)
		return;

	if (!isPrime(N))
	{
		T Y = Pollard_Brent(N);
		Factor(Y, Prime_factors);
		Factor(N / Y, Prime_factors);
	}
	else
	{
		Prime_factors[N]++;
		return;
	}
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
		map<ll, int> Prime_factors;
		Factor(N, Prime_factors);

		bool first = true;
		for (const auto &[prime, power] : Prime_factors)
		{
			if (!first)
				cout << "*";
			cout << "(" << prime << "^" << power << ")";
			first = false;
		}
	}
	return 0;
}
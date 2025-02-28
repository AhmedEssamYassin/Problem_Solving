#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> Prime, LPF;
bitset<1000005> isPrime;
void Linear_Sieve_Of_Eratosthenes(ll N)
{
	LPF.resize(N + 1);
	isPrime.set();
	isPrime[0] = isPrime[1] = 0; // 0 and 1 are NOT primes
	for (ll i{2}; i <= N; i++)
	{
		if (isPrime[i])
		{
			Prime.push_back(i);
			LPF[i] = i; // The least prime factor of a prime number is itself
		}
		for (ll j{}; j < (int)Prime.size() and i * Prime[j] <= N and Prime[j] <= LPF[i]; j++)
		{
			isPrime[i * Prime[j]] = 0; // Crossing out all the multiples of prime numbers
			LPF[i * Prime[j]] = Prime[j];
		}
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
	ll N, M;
	Linear_Sieve_Of_Eratosthenes(1000000);
	cin >> t;
	while (t--)
	{
		/*
		If a number N is a square of a prime, i.e., N = P²
		N will have ONLY 3 distinct divisors: 1, P, P²
		So we need to check if that number N satisfy two conditions:
		1. N is a perfect square
		2. sqrt(N) is a prime number
		*/
		cin >> N;
		ll Sqrt_N = sqrt(N);
		if (Sqrt_N * Sqrt_N == N && isPrime[Sqrt_N])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}

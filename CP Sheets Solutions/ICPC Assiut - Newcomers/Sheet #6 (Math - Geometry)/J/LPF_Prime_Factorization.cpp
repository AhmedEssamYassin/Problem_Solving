#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> Prime, LPF;
void Linear_Sieve_Of_Eratosthenes(int N)
{
	LPF.resize(N + 1);
	bitset<20000001> isPrime;
	isPrime.set();				 // Initially Assuming all numbers to be primes
	isPrime[0] = isPrime[1] = 0; // 0 and 1 are NOT primes
	for (int i{2}; i <= N; i++)
	{
		if (isPrime[i])
		{
			Prime.push_back(i);
			LPF[i] = i; // The least prime factor of a prime number is itself
		}
		for (int j{}; j < (int)Prime.size() and i * Prime[j] <= N and Prime[j] <= LPF[i]; j++)
		{
			isPrime[i * Prime[j]] = 0; // Crossing out all the multiples of prime numbers
			LPF[i * Prime[j]] = Prime[j];
		}
	}
}

void primeFactorize(ll N)
{
	while (N > 1)
	{
		ll power{1};
		while (LPF[N] == LPF[N / LPF[N]])
			N /= LPF[N], power++;
		cout << "(" << LPF[N] << "^" << power << ")";
		N /= LPF[N];
		if (N > 1)
			cout << "*";
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
	Linear_Sieve_Of_Eratosthenes(20000000);
	// cin >> t;
	while (t--)
	{
		cin >> N;
		primeFactorize(N);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
vector<int> Prime, LPF(1000001);
bitset<1000001> Is_Prime;
void Linear_Sieve_Of_Eratosthenes(int N)
{
	LPF[1] = 1;
	Is_Prime.set(); // Initially Assuming all numbers to be primes

	// 0 and 1 are NOT primes
	Is_Prime[0] = 0;
	Is_Prime[1] = 0;
	for (int i{2}; i <= N; i++)
	{
		if (Is_Prime[i])
		{
			Prime.push_back(i);
			LPF[i] = i; // The least prime factor of a prime number is itself
		}
		for (int j{}; j < (int)Prime.size() and i * Prime[j] <= N and Prime[j] <= LPF[i]; j++)
		{
			Is_Prime[i * Prime[j]] = 0; // Crossing out all the multiples of prime numbers
			LPF[i * Prime[j]] = Prime[j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	/*
	If a number N is a square of a prime, i.e., N = P²
	N will have ONLY 3 distinct divisors: 1, P, P²
	So we need to check if that number N satisfy two conditions:
	1. N is a perfect square
	2. sqrt(N) is a prime number

	To check if sqrt(N) is a prime number or NOT, we can use many approaches:
	1. Miller-rabbin primality test: Passes but NOT optimal because there are so many queries
	   And in fact, ALL numbers we are checking are in range [1, 1000'000] and that leads us to the second approach
	2. Use pre-computation to record the primality of all numbers in range [1, 1000'000]
	   That makes the primality check in ALL test cases run in constant time: O(1)

	NOTE:
	We CANNOT use an algorithm of O(sqrt(N)) checking primality, because it will be total O(t*sqrt(N)) which gives TLE
	*/
	Linear_Sieve_Of_Eratosthenes(1000001);
	int t;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		int Sqrt_N = sqrt(N);
		if (1LL * Sqrt_N * Sqrt_N == N && Is_Prime[Sqrt_N])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
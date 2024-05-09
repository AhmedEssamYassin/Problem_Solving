/*
Generating ALL primes in range [1, N]
|---------------------|
|Sieve Of Eratosthenes|
|---------------------|
The idea behind is this:
A number is prime, if NONE of the smaller prime numbers divides it.
Since we iterate over the prime numbers in order, we already marked all numbers, who are divisible by at least one of the prime numbers, as divisible.
Hence if we reach a cell and it is NOT marked, then it isn't divisible by any smaller prime number and therefore has to be prime.

Obviously, to find all the prime numbers until N , it will be enough just to perform the sifting only by the prime numbers, which do NOT exceed the sqrt(N)

bool* Sieve_Of_Eratosthenes(long long N)
{
	bool *Prime = new bool[N + 1]; // true means Prime and false means NOT prime
	memset(Prime, true, N + 1); // Assuming all numbers are initially primes
	Prime[0] = false, Prime[1] = false; // 0 and 1 are NOT primes
	for (int i{2}; i * i < N + 1; i++)
	{
		if (Prime[i]) // If Prime
		{
			for (int j = 2 * i; j <= N; j += i)
				Prime[j] = false; // Mark all multiples of i as NOT primes
		}
	}
	return Prime;
}

|----------------------------|
|Linear Sieve Of Eratosthenes|
|----------------------------|

vector<int> Prime;

void Linear_Sieve_Of_Eratosthenes(ll N)
{
	vector<bool> Is_Prime(N + 1, 1); // Initially Assuming all numbers to be primes
	vector<int> LPF(N + 1);
	Is_Prime[0] = Is_Prime[1] = 0; // 0 and 1 are NOT primes
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
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
vector<int> Prime;

void Linear_Sieve_Of_Eratosthenes(int N)
{
	vector<bool> Is_Prime(N + 1, 1); // Initially Assuming all numbers to be primes
	vector<int> LPF(N + 1);
	LPF[1] = 1;
	Is_Prime[0] = Is_Prime[1] = 0; // 0 and 1 are NOT primes
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
	int t = 1;
	ll N;
	// cin >> t;
	// Generating ALL primes until N
	cin >> N;
	Linear_Sieve_Of_Eratosthenes(N);
	for (int i{}; i < Prime.size(); i++)
		cout << Prime[i] << " ";

	/*
	Problems:
	* https://www.spoj.com/problems/PON/
	* https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/B
	* https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/D
	* https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/J
	* https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/H
	* https://codeforces.com/problemset/problem/230/B
	*/
	return 0;
}
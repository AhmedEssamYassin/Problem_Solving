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
#endif // !ONLINE_JUDGE

	int t;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		/*
		"YES" if N has an ODD divisor, greater than one
		"NO" otherwise.
		-----------------------------------------------------------------------------------------------------------
		Let P be a prime number
		For a number N = P1^a1 * P2^a2 * P3^a3 * ... * Pk^ak, which is the prime factorization of N
		Since ALL prime numbers are ODD numbers EXCEPT for the prime number 2
		If N has any other prime factor other than 2, it would have an ODD divisor
		Otherwise, if N has ONLY the prime factor 2^a, i.e., it's a power of two, it wouldn't have any ODD divisors
		*/
		if (__has_single_bit(N))
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
	/*
	Given a number N, Find the sum of powers of its set bits
	Example:
	N = 120
	Its bit representation is: 01111000
	The required sum = 3 + 4 + 5 + 6 = 18
	*/
	ll N;
	cin >> N;
	int Sum{};

	for (int Power{}; N > 0; N >>= 1, Power++)
		Sum += ((N & 1) * Power);
	// If the bit is set (1), Add the power
	// If the bit is cleared (0), it will nullify the term, thus adding NOTHING

	cout << Sum;
	return 0;
}
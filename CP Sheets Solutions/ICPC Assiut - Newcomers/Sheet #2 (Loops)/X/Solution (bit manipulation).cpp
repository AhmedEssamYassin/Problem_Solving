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
	Given a number N. Print the result of doing the following operation on N:

	1. Convert N to its binary representation.
	2. Count number of ones in the above binary representation.
	3. Print the equivalent decimal number that its binary representation has only the number of ones that were counted above.

	Example:
	5 in binary: 0101, It contains 2 ones
	So, A number with only two ones in binary is: 11 which is 3 in decimal

	We can easily observe, if there exists N ones, The Number required in binary would be 1111...1 (N times)
	We can obtain such number from such a (power_of_two - 1)
	Why?
	A power_of_two contains ONLY a single digit, subtracting 1 from that number flips ALL bits from beginning until the first set bit including that bit.
	So if we have (100000) in binary and we subtract 1, we get (011111)
	hence, in order to get such a number with N set bits, we can use ((1 << N) - 1)
	*/
	int t, Number;
	cin >> t;
	while (t--)
	{
		cin >> Number;
		int N = __builtin_popcount(Number);
		cout << (1 << N) - 1 << endl;
	}
	// A brute force solution
	/*
	int t, N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		int cnt{};
		while (N)
		{
			cnt += (N % 2); // Counting ones
			N /= 2;
		}
		int ans = 0;
		int T = 1;
		// 111111111
		for (int i = 0; i < cnt; i++)
		{
			ans += T; // 1 + 2 + 4 + 8 + 16 ...
			T *= 2;
		}
		cout << ans << endl;
	}
	*/
	return 0;
}
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
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		/*
		-1 + 2 - 3 + 4 - 5 + 6 - 7 + 8......
		(-1 + 2) + (-3 + 4) + (-5 + 6).......
		1 + 1 + 1 + 1 ......
		Every two consecutive terms in the series add up to 1
		So, if N is EVEN, we will end up with 1 + 1 + 1 ... --> 1's are repeated (N / 2) times (because every two numbers give a "1") --> So the answer is (N / 2) * 1
		but if N is ODD, we will end up with 1 + 1 + 1 ..... - N --> 1's are repeated floor(N / 2) times (because every two numbers give a "1" except for the last number)
		and (-N) has no pair --> So the answer is floor(N / 2) * 1 - N
		Example:
		N = 7 --> (-1 + 2) + (-3 + 4) + (-5 + 6) - 7
		*/
		if (N % 2) // N is ODD
			cout << N / 2 - N;
		else // N is EVEN
			cout << N / 2;
	}
	return 0;
}

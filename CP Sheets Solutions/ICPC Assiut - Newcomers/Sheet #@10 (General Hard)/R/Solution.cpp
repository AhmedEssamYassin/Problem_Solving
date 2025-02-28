#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Polycarpus has a ribbon, its length is N. He wants to cut the ribbon in a way that fulfils the following two conditions:
1. After the cutting each ribbon piece should have length a, b or c.
2. After the cutting the number of ribbon pieces should be maximum.

*/
int a, b, c;
ll dp[100000]; // Memoization to prevent repeated calculation (DP Solution)
ll Cut(ll N)
{
	if (N < 0)
		return -1e9; // Assigning it to a very small number in order to NOT be chosen as an optimal solution

	ll &ret = dp[N];
	if (~ret) // If calculated before
		return ret;
	ll Choice_1 = 1 + Cut(N - a); // Cut a piece 'a'
	ll Choice_2 = 1 + Cut(N - b); // Cut a piece 'b'
	ll Choice_3 = 1 + Cut(N - c); // Cut a piece 'c'

	return (ret = max({Choice_1, Choice_2, Choice_3}));
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
	ll N, x;
	// cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> N >> a >> b >> c;

		dp[0] = 0; // The optimal solution for N = 0 is 0 (To cut nothing)
		cout << Cut(N);
	}
	return 0;
}

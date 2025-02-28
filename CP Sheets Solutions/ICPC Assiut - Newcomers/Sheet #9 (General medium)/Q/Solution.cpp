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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		/*
		We can show that the maximum number of moves possible is (n) and minimal moves needed is ceil(n/2.0)
		So the problem equals to determine the minimal integer that is a multiple of m in the range [ceil(n/2.0),n].
		One way is to find the minimal number which is a multiple of m and greater than or equal to a number x is ceil(x/m)*m
		We can compare this number to the upper bound n to determine if there is a valid solution.
		*/
		cin >> N >> M;
		ll lowerBound = (N + 1) / 2; // (N + 2 - 1) / 2
		// if it's EVEN we need Exactly N/2 moves (each is of two steps) so (N + 1)/2 is floored because of integer division
		// Example: N = 10 --> 11 / 2 = 5 moves
		// else if it's ODD we need ceil(n / 2.0) moves (needs (n / 2) moves each of two steps and only one move of one step)
		// Example: N = 11 --> 12/2 = 6 (5 moves, each is of two steps and one move with one step)
		ll ans = (lowerBound + M - 1) / M * M; // minimal number which is a multiple of m and greater than or equal to the lowerBound

		if (ans > N) // if (ans) moves, each is of one step is greater than n then it's impossible to have such a valid solution
			return cout << -1, 0;
		cout << ans;
	}
	return 0;
}

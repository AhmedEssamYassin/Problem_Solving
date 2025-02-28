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
		int *coins = new int[N];
		for (int i{}; i < N; i++)
			cin >> coins[i];

		sort(coins, coins + N, greater<int>()); // Sorting in Descending order

		int *prefixSum = new int[N];
		prefixSum[0] = coins[0];
		for (int i = 1; i < N; i++)
			prefixSum[i] = prefixSum[i - 1] + coins[i];

		int cnt{};
		for (int i{}; i < N; i++)
		{
			cnt++;
			if (prefixSum[i] > prefixSum[N - 1] - prefixSum[i])
				break;
		}
		cout << cnt;
		delete coins, prefixSum;
	}
	return 0;
}

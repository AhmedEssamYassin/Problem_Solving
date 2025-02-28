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
	ll N, H;
	cin >> t;
	while (t--)
	{
		/*
		Since we are only interested in column sums,
		we don't actually need the full 2D prefix sum, just a 1D prefix sum per column.

		If you take a closer look at the sum of sub-grid (H * N),
		you will notice it's just the summation of the first H element of each column
		So we can compress all columns in just one column (1D array)
		*/
		cin >> N >> H;
		vector<ll> diffArr(N + 2, 0);
		vector<ll> prefix(N + 2, 0);

		// Queries - Difference Array
		for (int i = 0; i < N; i++)
		{
			ll L, R;
			cin >> L >> R;
			diffArr[1]++;	  // Mark start
			diffArr[L]--;	  // Remove at L
			diffArr[R + 1]++; // Add at R+1
			diffArr[N + 1]--; // End limit
		}

		// Convert Difference Array to Prefix Sum (O(N))
		for (int i = 1; i <= N; i++)
			prefix[i] = prefix[i - 1] + diffArr[i];

		// Compute first window sum (O(H))
		ll minSum = LLONG_MAX, windowSum = 0;
		for (int i = 1; i <= H; i++)
			windowSum += prefix[i];

		// Sliding Window to find the minimum sum (O(N))
		minSum = windowSum;
		for (int i = H + 1; i <= N; i++)
		{
			windowSum -= prefix[i - H];
			windowSum += prefix[i];
			minSum = min(minSum, windowSum);
		}

		cout << minSum << endl;
	}
	return 0;
}

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
	ll N, M, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> Q;
		// Create two separate difference arrays for left and right diagonal propagation
		vector<vector<ll>> leftDiffArr(N + 2, vector<ll>(M + 2, 0));  // For type 2 (left diagonal)
		vector<vector<ll>> rightDiffArr(N + 2, vector<ll>(M + 2, 0)); // For type 1 (right diagonal)
		vector<vector<ll>> grid(N + 2, vector<ll>(M + 2, 0));

		// Queries
		while (Q--)
		{
			ll type, x1, y1, a, k;
			cin >> type >> x1 >> y1 >> k >> a;
			// 1 - right
			// 2 - left

			if (type == 1) // Right diagonal (↘️)
			{
				ll x2 = min(x1 + k - 1, N);
				ll y2 = min(y1 + k - 1, M);
				rightDiffArr[x1][y1] += a;		   // Top-left
				rightDiffArr[x2 + 1][y2 + 1] -= a; // Bottom-right
			}
			else // Left diagonal (↙️)
			{
				ll x2 = min(x1 + k - 1, N);
				ll y2 = max(y1 - (k - 1), 1LL);
				leftDiffArr[x1][y1] += a;		  // Top-right
				leftDiffArr[x2 + 1][y2 - 1] -= a; // Bottom-left
			}
		}

		// Process right diagonal propagation (↘️)
		for (int i = 1; i <= N; i++)
		{
			// Add values from top-left diagonal neighbor
			for (int j = 1; j <= M; j++)
				grid[i][j] = grid[i - 1][j - 1] + rightDiffArr[i][j];
		}

		// Process left diagonal propagation (↙️)
		vector<vector<ll>> leftGrid(N + 2, vector<ll>(M + 2, 0));
		for (int i = 1; i <= N; i++)
		{
			// Add values from top-right diagonal neighbor
			for (int j = M; j >= 0; j--)
				leftGrid[i][j] += leftGrid[i - 1][j + 1] + leftDiffArr[i][j];
		}

		// Combine both propagations
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				grid[i][j] += leftGrid[i][j];
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

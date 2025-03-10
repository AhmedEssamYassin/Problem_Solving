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
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		// Create two separate difference arrays for left and right diagonal propagation
		vector<vector<ll>> rightDiffArr(N + 2, vector<ll>(M + 2, 0)); // For right diagonal (main diagonal)
		vector<vector<ll>> leftDiffArr(N + 2, vector<ll>(M + 2, 0));  // For left diagonal (anti diagonal)
		vector<vector<ll>> grid(N + 2, vector<ll>(M + 2, 0));
		vector<vector<ll>> vc(N + 2, vector<ll>(M + 2, 0));
		for (int i{1}; i <= N; i++)
		{
			string str;
			cin >> str;
			for (int j{1}; j <= M; j++)
				vc[i][j] = str[j - 1] - '0';
		}
		for (int i{1}; i <= N; i++)
		{
			for (int j{1}; j <= M; j++)
			{
				if (vc[i][j] == 1)
				{
					rightDiffArr[i - min(i, j) + 1][j - min(i, j) + 1] += 1;				 // Top-left
					rightDiffArr[i + min(N - i, M - j) + 1][j + min(N - i, M - j) + 1] -= 1; // Bottom-right

					leftDiffArr[i - min(i - 1LL, M - j)][j + min(i - 1LL, M - j)] += 1;			// Top-right
					leftDiffArr[i + min(N - i, j - 1LL) + 1][j - min(N - i, j - 1LL) - 1] -= 1; // Bottom-left
				}
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
				cout << ((grid[i][j] > 0) || (leftGrid[i][j] > 0));
			cout << endl;
		}
	}
	return 0;
}
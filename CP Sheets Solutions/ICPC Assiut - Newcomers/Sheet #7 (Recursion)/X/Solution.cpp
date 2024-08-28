#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll maxPath(const vector<vector<ll>> &grid, int i, int j)
{
	if (i >= grid.size() || j >= grid[0].size())
		return LLONG_MIN;
	if (i == grid.size() - 1 && j == grid[0].size() - 1)
		return grid[i][j];
	ll right = maxPath(grid, i, j + 1);
	ll down = maxPath(grid, i + 1, j);
	return grid[i][j] + max(right, down);
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<vector<ll>> grid(N, vector<ll>(M));
		for (int i{}; i < N; i++)
			for (int j{}; j < M; j++)
				cin >> grid[i][j];
		cout << maxPath(grid, 0, 0);
	}
	return 0;
}
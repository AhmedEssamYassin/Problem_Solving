#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll edges, nodes;
int dir_row[] = {0, 1, 0, -1};
int dir_col[] = {1, 0, -1, 0};

bool vis[51][51];
void dfs(const vector<vector<char>> &grid, int x, int y, char c)
{
	nodes++;
	vis[x][y] = 1;
	for (int i{}; i < 4; i++)
	{
		int Nx = x + dir_row[i];
		int Ny = y + dir_col[i];
		if (Nx >= 0 && Nx < grid.size() && Ny >= 0 && Ny < grid[0].size() && grid[Nx][Ny] == c)
		{
			edges++;
			if (!vis[Nx][Ny])
				dfs(grid, Nx, Ny, grid[Nx][Ny]);
		}
	}
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
	ll n, m;
	// cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<vector<char>> grid(n, vector<char>(m));
		for (int i{}; i < n; i++)
		{
			for (int j{}; j < m; j++)
				cin >> grid[i][j];
		}
		bool flag = false;
		for (int i{}; i < n; i++)
		{
			for (int j{}; j < m; j++)
			{
				if (!vis[i][j])
				{
					edges = 0;
					nodes = 0;
					dfs(grid, i, j, grid[i][j]);
					if (edges / 2 >= nodes)
					{
						flag = true;
						break;
					}
				}
			}
		}
		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
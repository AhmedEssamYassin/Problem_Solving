#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

ll bfs(ll x1, ll y1, ll x2, ll y2)
{
	if (x1 == x2 && y1 == y2)
		return 0;

	// Queue for BFS: each entry is {x, y, moves}
	queue<tuple<ll, ll, ll>> q;
	q.push({x1, y1, 0});

	// Visited array
	vector<vector<bool>> visited(9, vector<bool>(9, false));
	visited[x1][y1] = true;

	while (!q.empty())
	{
		auto [cx, cy, moves] = q.front();
		q.pop();

		for (auto [dx, dy] : directions)
		{
			ll nx = cx + dx, ny = cy + dy;

			// Check boundaries and if already visited
			if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && !visited[nx][ny])
			{
				if (nx == x2 && ny == y2)
					return moves + 1;

				visited[nx][ny] = true;
				q.push({nx, ny, moves + 1});
			}
		}
	}
	return -1; // Should never reach here
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
	ll N;
	cin >> t;
	while (t--)
	{
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << bfs(x1, y1, x2, y2) << endl;
	}
	return 0;
}
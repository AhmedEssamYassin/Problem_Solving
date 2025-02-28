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
		vector<vector<int>> farm(N, vector<int>(M));
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < M; j++)
				cin >> farm[i][j];
		}
		char c;
		int x, y;
		vector<int> row(N), col(M); // Two arrays for indices of rows and columns
		for (int i{}; i < N; i++)
			row[i] = i; // 0 1 2 3 ... n
		for (int i{}; i < M; i++)
			col[i] = i; // 0 1 2 3 ... m
		while (Q--)
		{
			cin >> c >> x >> y;
			x--, y--; // to make them 0-indexed
			if (c == 'r')
				swap(row[x], row[y]); // Swapping JUST the indices of xth and yth rows
			else if (c == 'c')
				swap(col[x], col[y]); // Swapping JUST the indices of xth and yth columns
			else
				cout << farm[row[x]][col[y]] << endl;
		}
	}
	return 0;
}

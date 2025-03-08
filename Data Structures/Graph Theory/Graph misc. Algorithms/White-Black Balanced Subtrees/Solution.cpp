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
	ll N, Node;
	string Tree_colors;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<vector<int>> Tree(N + 7);

		for (int i{2}; i <= N; i++)
		{
			cin >> Node;
			Tree[Node].push_back(i); // Tree[Parent].push_back(child)
		}
		cin >> Tree_colors;

		int res = 0;
		// [&] To capture external variables by reference
		// We can't use `auto` here because we do recursive calls
		function<int(int)> DFS = [&](int node)
		{
			int Balance = (Tree_colors[node - 1] == 'B') ? -1 : 1;
			if (Tree[node].empty())
				return Balance;

			for (const int &i : Tree[node]) // DFS on all children
				Balance += DFS(i);

			if (Balance == 0)
				res++;

			return Balance;
		};
		DFS(1); // Start from Parent: the root of the tree (Number 1)
		cout << res << endl;
	}
	return 0;
}
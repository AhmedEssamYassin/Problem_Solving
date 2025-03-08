#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll N, M;
vector<int> hasCat;
ll ans{};
void dfs(vector<vector<ll>> &tree, ll node, ll prev, ll k)
{
	if (k > M)
		return;
	ll valid = 1; // If the code reaches this, it must be a valid node until now
	for (int i{}; i < tree[node].size(); i++)
	{
		if (tree[node][i] != prev) // Not to go back to parents
			valid = 0, dfs(tree, tree[node][i], node, k * hasCat[tree[node][i]] + hasCat[tree[node][i]]);
	}
	ans += valid;
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
	ll x, y;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		hasCat.resize(N + 1);
		for (int i{1}; i <= N; i++)
			cin >> hasCat[i];
		vector<vector<ll>> tree(N + 1);
		for (int i{}; i < N - 1; i++)
		{
			cin >> x >> y;
			tree[x].push_back(y);
			tree[y].push_back(x);
		}
		dfs(tree, 1, -1, hasCat[1]);
		cout << ans;
	}
	return 0;
}
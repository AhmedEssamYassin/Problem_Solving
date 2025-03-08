#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bitset<200005> vis;
vector<ll> degree(200005, 0), vertices;

void dfs(const vector<ll> adj[], ll u)
{
	vis[u] = 1;
	vertices.push_back(u);
	for (const ll &v : adj[u])
	{
		if (!vis[v])
			dfs(adj, v);
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
	ll N, m;
	// cin >> t;
	while (t--)
	{
		cin >> N >> m;
		vector<ll> adj[N + 1];
		for (int i{}; i < m; i++)
		{
			ll u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			degree[u]++;
			degree[v]++;
		}
		ll cnt{};
		for (int u = 1; u <= N; u++)
		{
			if (!vis[u])
			{
				dfs(adj, u);
				bool cyclic = true;
				for (const ll &v : vertices)
					cyclic &= (degree[v] == 2);
				cnt += cyclic;
				vertices.clear();
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
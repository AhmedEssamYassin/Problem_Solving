#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bitset<200006> vis;
ll entryNode = -1;
bool dfs(const vector<vector<ll>> &adj, ll node, ll prev)
{
	vis[node] = 1;
	for (const ll &v : adj[node])
	{
		if (v != prev && vis[v])
		{
			entryNode = v;
			return true;
		}
		else if (v != prev && !vis[v])
			if (dfs(adj, v, node))
				return true;
	}
	return false;
}

ll dfsCalc(const vector<vector<ll>> &adj, ll node)
{
	vis[node] = 1;
	ll minDist = 200005;
	for (const ll &v : adj[node])
	{
		if (v == entryNode)
			return 1;
		if (!vis[v])
		{
			ll dist = dfsCalc(adj, v) + 1;
			minDist = min(minDist, dist);
		}
	}
	return minDist;
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
	ll N, a, b;
	cin >> t;
	while (t--)
	{
		cin >> N >> a >> b;
		vector<vector<ll>> adj(N + 1);
		for (int i{}; i < N; i++)
		{
			ll u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			// The graph is undirected
			adj[v].push_back(u);
		}
		dfs(adj, b, -1);
		vis.reset();
		ll distanceMarcel = 200005, distanceValeriu{};
		if (entryNode == a)
			distanceMarcel = 0;
		else
			distanceMarcel = dfsCalc(adj, a);

		vis.reset();
		if (entryNode == b)
			distanceValeriu = 0;
		else
			distanceValeriu = dfsCalc(adj, b);
		if (distanceValeriu < distanceMarcel)
			cout << "YES\n";
		else
			cout << "NO\n";
		vis.reset();
	}
	return 0;
}
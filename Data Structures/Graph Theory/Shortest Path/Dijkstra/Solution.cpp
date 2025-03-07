#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	ll par = -1; // parent
	Edge(ll node, ll weight, ll par = -1) : node(node), cost(weight), par(par) {}
	bool operator<(const Edge &E) const
	{
		return cost > E.cost;
	}
};

void Dijkstra(const vector<Edge> adj[], vector<ll> &dist, int N, int src, int dest)
{
	dist.assign(N + 1, INF);
	vector<ll> parent(N + 1, -1);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		auto [curNode, curCost, par] = prQue.top();
		prQue.pop();

		if (dist[curNode] != INF)
			continue;
		dist[curNode] = curCost;
		parent[curNode] = par;
		for (const Edge &v : adj[curNode])
			if (dist[v.node] == INF)
				prQue.emplace(v.node, v.cost + curCost, curNode);
	}
	vector<ll> path;
	ll temp = dest;
	while (parent[temp] != -1)
	{
		path.push_back(parent[temp]);
		temp = parent[temp];
	}
	if (path.empty())
		return void(cout << "-1" << endl);
	// Print the nodes on the shortest path themselves.
	reverse(path.begin(), path.end());
	path.push_back(dest);
	for (const ll &i : path)
		cout << i << " ";
	cout << endl;
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
		vector<Edge> adj[N + 1];
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			// If the Graph is Undirected
			adj[v].push_back({u, w});
		}
		vector<ll> dist;
		Dijkstra(adj, dist, N, 1, N);
	}
	return 0;
}

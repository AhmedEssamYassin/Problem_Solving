#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	bool hasTrain = false;
	Edge(ll node, ll weight, bool hasTrain = false) : node(node), cost(weight), hasTrain(hasTrain) {}
	bool operator<(const Edge &E) const
	{
		if (cost == E.cost) // If same cost, prioritize the edge without a train
			return hasTrain > E.hasTrain;
		return cost > E.cost;
	}
};
ll ans;
void Dijkstra(const vector<Edge> adj[], vector<ll> &dist, int N, int src)
{
	dist.assign(N + 1, INF);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		Edge cur = prQue.top();
		prQue.pop();
		if (dist[cur.node] != INF)
		{
			ans += cur.hasTrain;
			continue;
		}
		dist[cur.node] = cur.cost;
		for (const auto &[v, w, hasTrain] : adj[cur.node])
			if (dist[v] == INF)
				prQue.emplace(v, w + cur.cost, hasTrain);
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
	ll N, M, K;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> K;
		vector<Edge> adj[N + 1];
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w, 0});
			// If the Graph is Undirected
			adj[v].push_back({u, w, 0});
		}
		while (K--)
		{
			ll s, y;
			cin >> s >> y;
			adj[1].push_back({s, y, 1});
		}
		vector<ll> dist;
		Dijkstra(adj, dist, N, 1);
		cout << ans;
	}
	return 0;
}
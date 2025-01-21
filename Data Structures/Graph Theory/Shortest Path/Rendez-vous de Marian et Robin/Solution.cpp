#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	bool hasHorse = false;
	Edge(ll node, ll weight, bool hasHorse = false) : node(node), cost(weight), hasHorse(hasHorse) {}
	bool operator<(const Edge &E) const { return cost > E.cost; }
};

vector<bool> horse;
void Dijkstra(const vector<Edge> adj[], vector<array<ll, 2>> &dist, int N, int src)
{
	dist.assign(N + 1, array<ll, 2>{INF, INF});
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0, 0);
	while (!prQue.empty())
	{
		auto [u, curCost, curHasHorse] = prQue.top();
		prQue.pop();
		if (dist[u][curHasHorse] != INF)
			continue;
		dist[u][curHasHorse] = curCost;
		if (horse[u])
			curHasHorse = 1;
		for (auto [v, w, otherHorse] : adj[u])
		{
			if (curHasHorse)
				w /= 2;
			if (dist[v][curHasHorse] == INF)
				prQue.emplace(v, curCost + w, curHasHorse);
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
	ll N, M, h;
	cin >> t;
	while (t--)
	{
		cin >> N >> M >> h;
		horse.assign(N + 1, false);
		for (int i{}, node; i < h; i++)
			cin >> node, horse[node] = true;

		vector<Edge> adj[N + 1];
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			// If the Graph is Undirected
			adj[v].push_back({u, w});
		}

		vector<array<ll, 2>> distFrom1;
		vector<array<ll, 2>> distFromN;
		Dijkstra(adj, distFrom1, N, 1);
		Dijkstra(adj, distFromN, N, N);

		auto get = [&](int node)
		{ return max(min(distFrom1[node][0], distFrom1[node][1]), min(distFromN[node][0], distFromN[node][1])); };

		ll minDistance = INF;
		for (int node{1}; node <= N; node++)
			minDistance = min(minDistance, get(node));
		cout << (minDistance == INF ? -1 : minDistance) << endl;
	}
	return 0;
}
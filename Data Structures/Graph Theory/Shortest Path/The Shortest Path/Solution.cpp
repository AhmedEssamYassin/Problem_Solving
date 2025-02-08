#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll u, v, w;
	Edge(ll src, ll dest, ll weight) : u(src), v(dest), w(weight) {}
	bool operator<(const Edge &other) { return w > other.w; }
};

vector<ll> Bellman_Ford(vector<Edge> &edges, int N, int src)
{
	vector<ll> dist(N + 1, INF);
	dist[src] = 0;
	ll lastNode = -1;
	// Relax all edges N times
	for (int i = 0; i <= N; i++)
	{
		lastNode = -1;
		for (auto &[u, v, w] : edges)
		{
			if (dist[u] != INF && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				// Check for negative weight cycles
				if (i == N)
					return {};
			}
		}
	}

	return dist;
}

vector<ll> dist; // Being global and not initializing every time is a lot faster
void Dijkstra(vector<vector<pair<ll, ll>>> &edges, int N, int src)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> prQue;

	dist[src] = 0;
	prQue.emplace(0, src);
	while (!prQue.empty())
	{
		auto [currentDist, u] = prQue.top();
		prQue.pop();

		if (currentDist > dist[u])
			continue;

		dist[u] = currentDist;
		for (const auto &[v, w] : edges[u])
		{
			if (dist[u] + w < dist[v])
				prQue.emplace(dist[u] + w, v);
		}
	}
}

vector<vector<ll>> allPairs;
// Cannot work on a graph with negative cycles
void Johnson(vector<Edge> &edges, int N)
{
	ll minDist = INF;
	for (const auto &[u, v, w] : edges)
		minDist = min(minDist, w);

	/*
	Since we are finding the shortest path between ANY two nodes
	If all weights are positive, then the minimum of them is simply the answer!
	*/
	if (minDist >= 0) // All edges are non-negative
		return void(cout << minDist << endl);

	// Add a new source node S with edges to all nodes with weight 0
	vector<Edge> extendedEdges = edges;
	for (int i = 1; i <= N; i++)
		extendedEdges.emplace_back(0, i, 0);

	// Run Bellman-Ford from the new source
	vector<ll> P = Bellman_Ford(extendedEdges, N, 0);
	if (P.empty())
	{
		cout << "-inf" << endl; // Negative cycle detected
		return;
	}

	// Re-weight edges to ensure all weights are non-negative
	vector<vector<pair<ll, ll>>> reWeightedGraph(N + 1);
	for (const auto &[u, v, w] : edges)
		reWeightedGraph[u].emplace_back(v, w + P[u] - P[v]);

	// Run Dijkstra's algorithm for each node
	// Find minimum shortest path between any pair
	dist.assign(N + 1, INF);
	for (int i = 1; i <= N; i++)
	{
		Dijkstra(reWeightedGraph, N, i);
		for (int j = 1; j <= N; j++)
		{
			if (dist[j] != INF)
			{
				ll originalDist = dist[j] - (P[i] - P[j]);
				minDist = min(minDist, originalDist);
			}
		}
	}

	if (minDist == INF)
		cout << "-inf\n";
	else
		cout << minDist << "\n";
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
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<Edge> edges;
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			edges.emplace_back(u, v, w); // u is parent of v

			// The graph is Directed
			// The graph is also sparse, i.e., |E| <= |V| log |V|
			// In this case, Johnsons' algorithm would be more efficient
		}
		Johnson(edges, N);
	}
	return 0;
}
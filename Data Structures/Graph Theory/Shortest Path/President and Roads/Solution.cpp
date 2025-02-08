#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

/*
An edge in an undirected connected graph is a bridge if removing it disconnects the graph.
For a disconnected undirected graph, the definition is similar,
a bridge is an edge removal that increases the number of disconnected components.
*/

struct Edge
{
	ll node = -1;
	ll cost = INF;
	Edge(ll node, ll weight) : node(node), cost(weight) {}
	bool operator<(const Edge &E) const { return cost > E.cost; }
};

vector<bool> visited;
vector<int> entryTime, low;
map<int, bool> isBridge;
int timer;

void dfs(vector<Edge> adj[], int u, int par = -1)
{
	visited[u] = true;
	entryTime[u] = low[u] = timer++;
	bool parent_skipped = false;
	for (const auto &[v, pos] : adj[u])
	{
		if (v == par && !parent_skipped)
		{
			parent_skipped = true;
			continue;
		}
		if (visited[v])
			low[u] = min(low[u], entryTime[v]);
		else
		{
			dfs(adj, v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > entryTime[u])
				isBridge[pos] = true;
		}
	}
}
// Multiple edges CANNOT be bridge edges
void findBridges(vector<Edge> adj[], int N)
{
	timer = 0;
	visited.assign(N + 1, false);
	entryTime.assign(N + 1, -1);
	low.assign(N + 1, -1);
	for (int u = 0; u <= N; u++)
	{
		if (!visited[u])
			dfs(adj, u);
	}
}

void Dijkstra(const vector<Edge> adj[], vector<ll> &dist, int N, int src)
{
	dist.assign(N + 1, INF);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		auto [node, cost] = prQue.top();
		prQue.pop();
		if (dist[node] != INF)
			continue;
		dist[node] = cost;
		for (const auto &[v, w] : adj[node])
			if (dist[v] == INF)
				prQue.emplace(v, w + cost);
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
	ll N, M, S, T;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> S >> T;
		vector<Edge> adj[N + 1], revAdj[N + 1], unDirectedAdj[N + 1];
		vector<array<ll, 3>> edges;
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			revAdj[v].push_back({u, w}); // To be able to calculate SSSP from T to S
			edges.push_back({u, v, w});	 // To traverse edges in order
		}
		vector<ll> distFromS;
		vector<ll> distFromT;
		Dijkstra(adj, distFromS, N, S);
		Dijkstra(revAdj, distFromT, N, T);
		// To be part of the shortest path: w(S -> u) + w(u -> v) + w(T -> v) = w(S -> T)
		// If we mark edges by {u, v, w}, duplicate multiple edges will fail the algorithm
		// Let's maintain position instead of weight
		int pos{};
		for (const auto &[u, v, w] : edges)
		{
			if (distFromS[u] != INF && distFromT[v] != INF && distFromS[T] != INF)
			{
				if (distFromS[u] + w + distFromT[v] == distFromS[T])
				{
					unDirectedAdj[u].push_back({v, pos});
					unDirectedAdj[v].push_back({u, pos});
				}
			}
			pos++;
		}
		findBridges(unDirectedAdj, N);
		pos = 0;
		for (const auto &[u, v, w] : edges)
		{
			if (isBridge.count(pos))
				cout << "YES\n";
			else
			{
				if (distFromS[u] != INF && distFromT[v] != INF && distFromS[T] != INF)
				{
					if (distFromS[T] - distFromS[u] - distFromT[v] - 1 >= 1)
						cout << "CAN " << w - (distFromS[T] - distFromS[u] - distFromT[v] - 1) << endl;
					else
						cout << "NO\n";
				}
				else
					cout << "NO\n";
			}
			pos++;
		}
	}
	return 0;
}
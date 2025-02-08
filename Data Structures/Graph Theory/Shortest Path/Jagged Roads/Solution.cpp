#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF 2e15

struct Edge
{
	ll node = -1;
	long double cost = INF;
	Edge(ll node, long double weight) : node(node), cost(weight) {}
	bool operator<(const Edge &E) const { return cost > E.cost; }
};

void Dijkstra(const vector<Edge> edges[], vector<long double> &dist, int N, int src)
{
	dist.assign(N + 1, INF);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		auto &topNode = prQue.top();
		ll curNode = topNode.node;
		long double curCost = topNode.cost;
		prQue.pop();
		if (dist[curNode] != INF)
			continue;
		dist[curNode] = curCost;
		for (const auto &[v, w] : edges[curNode])
			if (dist[v] == INF)
				prQue.emplace(v, w + curCost);
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<Edge> edges[N + 1];
		cout << fixed << setprecision(12);
		for (int i{}; i < M; i++)
		{
			ll u, v, c;
			cin >> u >> v >> c;
			edges[u].push_back({v, logl(c) / logl(7)});
			edges[v].push_back({u, logl(c) / logl(7)});
		}
		vector<long double> dist;
		Dijkstra(edges, dist, N, 1);
		cout << dist[N] << endl;
	}
	return 0;
}
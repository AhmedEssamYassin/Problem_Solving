#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Edge
{
	ll node = -1;
	ll par = -1; // parent
	ll cost = LLONG_MAX;
	Edge(ll node, ll weight, ll par = -1) : node(node), cost(weight), par(par) {}
	bool operator<(const Edge &E) const { return cost > E.cost; }
};

void Dijkstra(const vector<Edge> graph[], int N, int src, int dest)
{
	vector<ll> dist(N + 1, LLONG_MAX), parent(N + 1, -1);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		Edge cur = prQue.top();
		prQue.pop();
		/*
		If we want the cost of the shortest path from src to dest

		if (cur.node == dest)
			return void(cout << cur.cost << endl);
		*/
		if (dist[cur.node] != LLONG_MAX)
			continue;
		dist[cur.node] = cur.cost;
		parent[cur.node] = cur.par;
		for (const Edge &v : graph[cur.node])
			if (dist[v.node] == LLONG_MAX)
				prQue.emplace(v.node, v.cost + cur.cost, cur.node);
	}
	// If there were NO path from src to dest
	// return void(cout << "NO\n");
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
		vector<Edge> graph[N + 1];
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back({v, w});
			// If the Graph is Undirected
			graph[v].push_back({u, w});
		}
		Dijkstra(graph, N, 1, N);
	}
	return 0;
}
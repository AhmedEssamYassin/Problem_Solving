#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	Edge(ll node, ll weight) : node(node), cost(weight) {}
	bool operator<(const Edge &E) const { return cost > E.cost; }
};

void Dijkstra(const vector<Edge> adj[], vector<ll> &dist, int N, int src, int dest)
{
	dist.assign(N + 1, INF);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		Edge cur = prQue.top();
		prQue.pop();

		// If we want the cost of the shortest path from src to dest
		if (cur.node == dest)
			return void(cout << cur.cost << endl);

		if (dist[cur.node] != INF)
			continue;
		dist[cur.node] = cur.cost;
		for (const Edge &v : adj[cur.node])
			if (dist[v.node] == INF)
				prQue.emplace(v.node, v.cost + cur.cost);
	}
	// If there were NO path from src to dest
	return void(cout << "-1\n");
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
	ll N;
	cin >> t;
	while (t--)
	{
		ll s, e;
		cin >> N >> s >> e;
		vector<array<int, 10>> vc(N);
		for (int i{}; i < N; i++)
		{
			string str;
			cin >> str;
			for (const char &C : str)
				vc[i][C - '0']++;
		}
		auto common = [&](int cur, int other)
		{
			int cnt{};
			for (int j{}; j < 10; j++)
				cnt += min(vc[cur][j], vc[other][j]);

			return (cnt == 17);
		};
		vector<Edge> adj[N + 1];
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < N; j++)
			{
				if (j == i)
					continue;
				if (common(i, j))
					adj[i + 1].push_back({j + 1, 1});
			}
		}
		vector<ll> dist;
		Dijkstra(adj, dist, N, s, e);
	}
	return 0;
}
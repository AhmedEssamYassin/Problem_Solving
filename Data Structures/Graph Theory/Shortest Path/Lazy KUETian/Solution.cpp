#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	ll cnt{};
	bool rev = 0;

	Edge(ll node, ll weight, ll cnt = 0, bool rev = false) : node(node), cost(weight), cnt(cnt), rev(rev) {}
	bool operator<(const Edge &E) const
	{
		// Min-heap function
		if (cost == E.cost) // If same cost, prioritize the one with less reversed edges
			return cnt > E.cnt;
		return cost > E.cost;
	}
};

void Dijkstra(const vector<Edge> adj[], vector<ll> &dist, int N, int src, int K)
{
	vector<ll> parent(N + 1, -1);
	dist.assign(N + 1, INF);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0);
	while (!prQue.empty())
	{
		Edge cur = prQue.top();
		prQue.pop();

		if (cur.cost > dist[cur.node])
			continue;
		for (auto &[v, w, cnt, rev] : adj[cur.node])
		{
			if (dist[v] <= cur.cost + w)
				continue;
			if (rev && cur.cnt == K)
				continue;
			dist[v] = cur.cost + w;
			prQue.push({v, dist[v], cur.cnt + rev});
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
	ll N, M, K, S, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> K >> S;
		vector<Edge> adj[N + 1];
		while (M--)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w, 0, 0});
			// The reverse edge is double the original weight
			adj[v].push_back({u, 2 * w, 0, 1});
		}
		vector<ll> dist;
		Dijkstra(adj, dist, N, S, K);
		cin >> Q;
		while (Q--)
		{
			ll x;
			cin >> x;
			ll answer = dist[x];
			cout << (answer == INF ? -1 : answer) << endl;
		}
	}
	return 0;
}
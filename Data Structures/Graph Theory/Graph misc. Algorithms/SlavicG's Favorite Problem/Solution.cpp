#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	Edge(ll n, ll c)
	{
		node = n;
		cost = c;
	}
	bool operator<(const Edge &E) const
	{
		return cost > E.cost;
	}
};
ll a, b;
set<ll> st;
void dfs1(vector<Edge> adj[], ll u, ll prev, ll XOR)
{
	if (u == b)
		return;
	st.insert(XOR);
	for (const auto &[v, w] : adj[u])
	{
		if (v == prev)
			continue;
		dfs1(adj, v, u, XOR ^ w);
	}
}

bool dfs2(vector<Edge> adj[], ll u, ll prev, ll XOR)
{
	// NOT the node `b`, but this cost is recorded as a path from node `a`
	// that means we can go directly from that node to `b`, or teleport from that node to `b`
	if (u != b && st.count(XOR))
		return true;
	for (const auto &[v, w] : adj[u])
	{
		if (v == prev)
			continue;
		if (dfs2(adj, v, u, w ^ XOR))
			return true;
	}
	return false;
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
		cin >> N >> a >> b;
		vector<Edge> adj[N + 1];
		while (--N)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			// Undirected graph
			adj[v].push_back({u, w});
		}
		/*
		Choose a path with value X = one of the edges leading to `b`
		Teleport to some node doesn't cost anything
		The idea is, if we can travel from node `a` to some node `x` with value `XOR`
		and we can travel from node `x` to `b` with the same value `XOR`
		that means traveling from `a` to `b` would cost ((XOR ^ XOR) = 0) which is required

		A thing to notice is that we must stop the DFS form `a` once we reach `b`
		because we cannot pass `b` on our path because (c ^ c = 0)
		that means the weight of an edge leading to `b` will cancel and this is NOT valid
		even if the path's value eventually is 0, it won't be a 0 because of an edge leading to `b`
		*/

		dfs1(adj, a, -1, 0); // record all costs from node `a` to all other nodes until node `b`
		if (dfs2(adj, b, -1, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
		st.clear();
	}
	return 0;
}
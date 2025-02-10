#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

// https://codeforces.com/contest/843/problem/D

struct Edge
{
	ll node = -1;
	ll par = -1; // parent
	ll cost = INF;
	Edge(ll node, ll weight, ll par = -1) : node(node), cost(weight), par(par) {}
	bool operator<(const Edge &E) const
	{
		return cost > E.cost;
	}
};

bitset<100001> inQueue;
void SPFA(const vector<vector<Edge>> &graph, vector<ll> &dis, int N, int src)
{
	dis.assign(N + 1, INF);
	inQueue.reset();
	deque<ll> q;
	q.push_back(src);
	dis[src] = 0;

	while (!q.empty())
	{
		ll u;
		if (dis[q.front()] > dis[q.back()])
		{
			u = q.back();
			q.pop_back();
		}
		else
		{
			u = q.front();
			q.pop_front();
		}
		inQueue[u] = false;
		for (const auto &[v, p, w] : graph[u])
		{
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if (!inQueue[v])
				{
					if (!q.empty() && dis[v] < dis[q.front()])
						q.push_front(v);
					else
						q.push_back(v);
					inQueue[v] = true;
				}
			}
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
	ll N, M, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> Q;
		vector<vector<Edge>> graph(N + 1);
		vector<array<ll, 2>> ind(M + 1);
		vector<ll> dis;
		for (int i{1}; i <= M; i++) // O(M)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			ind[i] = {u, (ll)graph[u].size()};
			graph[u].push_back({v, w});
		}
		bool pending = true;
		while (Q--) // O(Q * M)
		{
			ll query;
			cin >> query;
			if (query == 1)
			{
				ll v;
				cin >> v;
				if (pending)
					SPFA(graph, dis, N, 1), pending = false;
				if (dis[v] == INF)
					cout << -1 << endl;
				else
					cout << dis[v] << endl;
			}
			else
			{
				int c, l;
				cin >> c;
				while (c--)
				{
					cin >> l;
					graph[ind[l][0]][ind[l][1]].cost++;
				}
				pending = true;
			}
		}
	}
	return 0;
}
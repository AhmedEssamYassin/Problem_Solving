#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
	ll node = -1;
	ll cost = INF;
	ll countLoanCities = 0;
	Edge(ll node, ll weight, ll countLoanCities) : node(node), cost(weight), countLoanCities(countLoanCities) {}
	bool operator<(const Edge &E) const
	{
		if (countLoanCities == E.countLoanCities)
			return cost > E.cost; // Prioritize smaller cost if bad city count is the same

		return countLoanCities > E.countLoanCities; // Prioritize fewer bad cities
	}
};

bitset<100010> isBad;
void Dijkstra(const vector<Edge> adj[], int N, int src, int dest)
{
	vector<ll> dist(N + 1, INF);
	priority_queue<Edge> prQue;
	prQue.emplace(src, 0, isBad[src]);
	while (!prQue.empty())
	{
		auto [curNode, curCost, countLoanCities] = prQue.top();
		prQue.pop();
		if (curNode == dest)
		{
			cout << countLoanCities << " " << curCost << endl;
			return;
		}

		if (curCost > dist[curNode])
			continue; // Avoid revisiting with a worse cost

		dist[curNode] = curCost;
		for (const auto &[nextNode, nextCost, nextBadCount] : adj[curNode])
		{
			ll newBadCount = countLoanCities + isBad[nextNode];
			if (dist[nextNode] == INF)
				prQue.emplace(nextNode, curCost + 1, newBadCount);
		}
	}
	// Never reached because it's guaranteed to find a path to N in this problem
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
	ll N, M, D;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M >> D;
		isBad.reset();
		for (int i{}; i < D; i++)
		{
			ll city;
			cin >> city;
			isBad[city] = 1;
		}
		vector<Edge> adj[N + 1];
		for (int i{}; i < M; i++)
		{
			ll u, v;
			cin >> u >> v;
			adj[u].push_back({v, 1, 0});
			adj[v].push_back({u, 1, 0});
		}
		Dijkstra(adj, N, 1, N);
	}
	return 0;
}
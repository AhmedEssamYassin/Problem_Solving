#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
Spanning tree
Suppose we have a connected directed graph G = {V, E}
The spanning tree is any sub-Graph = {V', E'}, where V' = V and E' = |V| - 1
Number of spanning trees = (|E| Choose (|V|-1)) - number of cycles

1. A minimum spanning tree of a graph is unique, if the weight of all the edges are distinct.
   Otherwise, there may be multiple minimum spanning trees.
   (Specific algorithms typically output one of the possible minimum spanning trees).
2. Minimum spanning tree is also the tree with minimum product of weights of edges.
   (It can be easily proved by replacing the weights of all edges with their logarithms)
3. In a minimum spanning tree of a graph, the maximum weight of an edge is the minimum possible from all possible spanning trees of that graph.
   (This follows from the validity of Kruskal's algorithm).
   The maximum spanning tree (spanning tree with the sum of weights of edges being maximum) of a graph
   can be obtained similarly to that of the minimum spanning tree,
   by changing the signs of the weights of all the edges to their opposite and then applying any of the minimum spanning tree algorithm.
*/

struct Edge
{
	ll u, v, cost;
	Edge(ll u, ll v, ll cost) : u(u), v(v), cost(cost) {}
	bool operator<(const Edge &e) const { return cost < e.cost; }
};

struct DSU
{
	vector<ll> parent, size; // Representative
	// The leader should be the parent of itself
	DSU(int n)
	{
		parent.resize(n + 1);
		size.resize(n + 1, 1); // Each component if of size 1 initially
		iota(parent.begin(), parent.end(), 0);
	}
	ll representative(ll node)
	{
		// Small to large technique
		if (parent[node] == node)
			return node;

		return parent[node] = representative(parent[node]); // Path compression
	}
	void Union(ll u, ll v)
	{
		ll rep1 = representative(u);
		ll rep2 = representative(v);
		if (rep1 == rep2)
			return;
		if (size[rep1] > size[rep2])
			swap(rep1, rep2); // representative of smaller set comes first
		parent[rep1] = rep2;
		size[rep2] += size[rep1];
	}
	bool isSameComponent(ll u, ll v)
	{
		return (representative(u) == representative(v));
	}
};

pair<vector<vector<ll>>, ll> buildMST(vector<Edge> &edges, ll N)
{
	DSU disjointSet(N + 1);
	vector<vector<ll>> mst(N + 1);	  // Adjacency list for MST
	sort(edges.begin(), edges.end()); // Sort edges by cost
	ll mstCost{};
	for (const auto &[u, v, cost] : edges)
	{
		if (!disjointSet.isSameComponent(u, v))
		{
			disjointSet.Union(u, v);
			mst[u].push_back(v);
			mst[v].push_back(u);
			mstCost += cost;
		}
	}
	return {mst, mstCost};
}

pair<ll, ll> dfsFarthestNode(ll node, vector<vector<ll>> &mst, vector<bool> &visited)
{
	visited[node] = true;
	pair<ll, ll> farthest = {node, 0};

	for (auto &neighbor : mst[node])
	{
		if (!visited[neighbor])
		{
			auto result = dfsFarthestNode(neighbor, mst, visited);
			if (result.second + 1 > farthest.second) // Count edges, not weights
			{
				farthest.first = result.first;
				farthest.second = result.second + 1;
			}
		}
	}
	return farthest;
}

ll findDiameter(vector<vector<ll>> &mst, ll N)
{
	vector<bool> visited(N + 1, false);
	auto farthestNode = dfsFarthestNode(1, mst, visited); // First DFS to find the farthest node from node 1
	fill(visited.begin(), visited.end(), false);
	auto diameter = dfsFarthestNode(farthestNode.first, mst, visited); // Second DFS to find the farthest node from the first farthest node
	return diameter.second;
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
		vector<Edge> edges;
		for (int i{}; i < M; i++)
		{
			ll u, v, c;
			cin >> u >> v >> c;
			edges.push_back({u, v, c});
		}

		// Build the MST
		auto [mst, mstCost] = buildMST(edges, N);

		// Find the diameter of the MST
		ll diameter = findDiameter(mst, N);

		cout << mstCost << endl;
		cout << diameter;
	}
	return 0;
}
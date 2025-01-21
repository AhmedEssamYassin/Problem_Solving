#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

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
    map<ll, ll> findConnectedComponents(int N)
    {
        map<ll, ll> components;
        for (int i = 1; i <= N; i++)
        {
            ll root = representative(i);
            components[root]++;
        }
        return components;
    }
};

bool isBipartite(vector<vector<int>> &adj)
{
    int N = adj.size();
    DSU dsu(N + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < adj[i].size(); j++)
            dsu.Union(adj[i][j], adj[i][j - 1]);
    }

    // Check for bipartite violations
    for (int i = 0; i < N; i++)
    {
        for (const int &j : adj[i])
        {
            if (dsu.isSameComponent(i, j))
                return false; // Not bipartite
        }
    }

    return true; // Bipartite
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
    }
    return 0;
}

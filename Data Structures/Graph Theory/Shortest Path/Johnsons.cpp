#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
    ll u, v, w;
    Edge(ll src, ll dest, ll weight) : u(src), v(dest), w(weight) {}
    bool operator<(const Edge &other) { return w > other.w; }
};

vector<ll> Bellman_Ford(vector<Edge> &edges, int N, int src)
{
    vector<ll> dist(N + 1, INF);
    dist[src] = 0;
    // Relax all edges N times
    for (int i = 0; i <= N; i++)
    {
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                // Check for negative weight cycles
                if (i == N)
                    return {};
            }
        }
    }

    return dist;
}

void Dijkstra(vector<vector<pair<ll, ll>>> &graph, vector<ll> &dist, int N, int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> prQue;

    dist[src] = 0;
    prQue.emplace(0, src);

    while (!prQue.empty())
    {
        auto [currentDist, u] = prQue.top();
        prQue.pop();

        if (currentDist > dist[u])
            continue;

        dist[u] = currentDist;
        for (const auto &[v, w] : graph[u])
        {
            if (dist[u] + w < dist[v])
                prQue.emplace(dist[u] + w, v);
        }
    }
}

vector<vector<ll>> allPairs;
// Cannot work on a graph with negative cycles
void Johnson(vector<Edge> &edges, int N)
{
    // Add a new source node S with edges to all nodes with weight 0
    vector<Edge> extendedEdges = edges;
    for (int i = 1; i <= N; i++)
        extendedEdges.emplace_back(0, i, 0);

    // Run Bellman-Ford from the new source
    vector<ll> P = Bellman_Ford(extendedEdges, N, 0);
    if (P.empty())
    {
        cout << "-inf" << endl; // Negative cycle detected
        return;
    }

    // Re-weight edges to ensure all weights are non-negative
    vector<vector<pair<ll, ll>>> reWeightedGraph(N + 1);
    for (const auto &[u, v, w] : edges)
        reWeightedGraph[u].emplace_back(v, w + P[u] - P[v]);

    allPairs.assign(N + 1, vector<ll>(N + 1, INF));
    // Run Dijkstra's algorithm for each node
    for (int u = 1; u <= N; u++)
    {
        Dijkstra(reWeightedGraph, allPairs[u], N, u);
        // Restore original weights
        for (int v = 1; v <= N; v++)
        {
            if (allPairs[u][v] != INF)           // There is an edge
                allPairs[u][v] -= (P[u] - P[v]); // Inverse operation
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
        vector<Edge> edges;
        while (M--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
            edges.emplace_back(v, u, w);
        }
        // Faster for sparse graphs (than Floyd-Warshall)
        // A graph is sparse when |E| <= |V| log |V|
        Johnson(edges, N);
        while (Q--)
        {
            ll u, v;
            cin >> u >> v;
            ll minDist = allPairs[u][v];
            cout << (minDist == INF ? -1 : minDist) << endl;
        }
    }
    return 0;
}

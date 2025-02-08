#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Edge
{
    ll node = -1;
    ll par = -1; // parent
    ll cost = INT_MAX;
    Edge(ll node, ll weight, ll par = -1) : node(node), cost(weight), par(par) {}
    bool operator<(const Edge &E) const
    {
        return cost > E.cost;
    }
};

// Kahn’s Algorithm
vector<int> KahnTopologicalSort(vector<Edge> adj[], int N)
{
    vector<int> inDegree(N + 1);
    for (int u = 1; u <= N; u++)
    {
        for (auto &[v, par, w] : adj[u])
            inDegree[v]++;
    }

    // Queue to store vertices with inDegree 0
    queue<int> que;
    for (int u = 1; u <= N; u++)
    {
        if (inDegree[u] == 0)
            que.push(u);
    }
    vector<int> result;
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        result.push_back(node);

        // Decrease inDegree of adjacent vertices as the current node is in topological order
        for (auto &[v, par, w] : adj[node])
        {
            inDegree[v]--;

            // If inDegree becomes 0, push it to the queue
            if (inDegree[v] == 0)
                que.push(v);
        }
    }

    // Check for cycle
    if (result.size() != N)
        return {};

    return result;
}

vector<ll> shortestPath(vector<Edge> adj[], int N, int src, int dest)
{
    // Find the topological sort of graph
    vector<int> topologicalOrder = KahnTopologicalSort(adj, N);
    // Find the shortest path to reach all vertices from source 0
    vector<ll> minDistance(N + 1, INT_MAX);
    minDistance[src] = 0;
    for (const int &node : topologicalOrder)
    {
        if (minDistance[node] == INT_MAX)
            continue;

        for (const auto &[v, par, w] : adj[node])
        {
            if (minDistance[node] + w < minDistance[v])
                minDistance[v] = minDistance[node] + w;
        }
    }

    for (int node = 0; node <= N; ++node)
        if (minDistance[node] == INT_MAX)
            minDistance[node] = -1; // If its impossible to reach the node

    return minDistance;
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
        vector<Edge> adj[N + 1];
        while (M--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            // If the Graph is Directed
        }

        shortestPath(adj, N, 1, N);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

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

vector<vector<ll>> dist;
void DetectNegativeCycles(int N)
{
    for (int k = 1; k <= N; k++)
    {
        if (dist[k][k] < 0) // Negative cycle detected
        {
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= N; j++)
                {
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = -INF;
                }
            }
        }
    }
}
void Floyd_Warshall(vector<Edge> graph[], int N)
{
    dist.assign(N + 1, vector<ll>(N + 1, INF));
    for (int u = 1; u <= N; u++)
    {
        for (const auto &[v, par, cost] : graph[u])
        {
            dist[u][v] = min(dist[u][v], cost);
            dist[v][u] = min(dist[v][u], cost);
        }
    }
    for (int i = 0; i <= N; i++)
        dist[i][i] = 0;

    for (int k = 0; k <= N; k++)
    {
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    // Detect and propagate -inf due to negative cycles
    // DetectNegativeCycles(N);
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
        vector<Edge> graph[N + 1];
        while (M--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            // If the Graph is Undirected
            graph[v].push_back({u, w});
        }
        // Faster than Johnson's algorithm for Dense graphs
        // A graph is dense if |E| <= |V|²
        Floyd_Warshall(graph, N); // O(N³)
        while (Q--)
        {
            ll A, B;
            cin >> A >> B;
            cout << (dist[A][B] == INF ? -1 : dist[A][B]) << "\n";
        }
    }
    return 0;
}

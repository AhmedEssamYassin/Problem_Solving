#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
    ll u, v, w;
    Edge(ll src, ll dest, ll c)
    {
        u = src;
        v = dest;
        w = c;
    }
    bool operator<(const Edge &other)
    {
        return w > other.w;
    }
};

void Bellman_Ford(vector<Edge> &edges, int N, int src)
{
    vector<ll> dist(N + 1, INF);
    dist[src] = 0;
    ll lastNode;
    // Relax all edges N times (to check for negative cycles)
    for (int i = 1; i <= N; i++)
    {
        lastNode = -1;
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] < INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                // dist[v] = max(-INF, dist[u] + w);
                lastNode = v;
            }
        }
    }

    // Check for negative cycles
    if (lastNode != -1)
        return void(cout << "-inf" << endl);

    // Do something with minimum distances from src to all other nodes
    for (int i = 1; i <= N; i++)
        cout << dist[i] << " ";
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
            ll u, v, cost;
            cin >> u >> v >> cost;
            edges.push_back({u, v, cost});
        }
        Bellman_Ford(edges, N, 1);
    }
    return 0;
}

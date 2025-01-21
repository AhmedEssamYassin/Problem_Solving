#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

/*
A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color.
This means we can divide the graph’s vertices into two distinct sets where:
- All edges connect vertices from one set to vertices in the other set.
- No edges exist between vertices within the same set.
*/
vector<vector<ll>> adj;

vector<int> matchings;
vector<bool> visited;

// Kuhn's algorithm for finding augmenting paths
bool try_kuhn(int u)
{
    if (visited[u])
        return false;
    visited[u] = true;

    for (auto &v : adj[u])
    {
        // Try to match the v or find an augmenting path
        if (matchings[v] == -1 || try_kuhn(matchings[v]))
        {
            matchings[v] = u;
            return true;
        }
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
    ll N, M, K;
    // cin >> t;
    while (t--)
    {
        cin >> N >> M >> K;
        adj.assign(N + 1, vector<ll>());
        // Potential pairs (edges in the bipartite graph)
        while (K--)
        {
            ll u, v;
            cin >> u >> v;
            // Graph is directed and Unweighted
            adj[u].push_back(v);
        }
        matchings.assign(M + 1, -1); // Find matches to `v`
        ll cntPairs{};
        for (int u = 1; u <= N; u++) // Run Kuhn's algorithm on adj[u]
        {
            visited.assign(N + M + 1, false);
            cntPairs += try_kuhn(u);
        }
        cout << cntPairs << endl;
        for (int v = 1; v <= M; v++) // Get matches of every `v` if any
            if (matchings[v] != -1)
                cout << matchings[v] << " " << v << endl;
    }
    return 0;
}
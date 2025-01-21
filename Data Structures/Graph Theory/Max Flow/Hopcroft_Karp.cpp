#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

vector<ll> match, dist;
vector<vector<ll>> adj;

bool bfs(int N)
{
    queue<ll> q;
    // The alternating path starts with unmatched nodes
    for (int u = 1; u <= N; u++)
    {
        if (!match[u])
        {
            q.push(u);
            dist[u] = 0;
        }
        else
            dist[u] = INF;
    }

    dist[0] = INF;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        if (dist[u] >= dist[0])
            continue;
        for (const ll &v : adj[u])
        {
            // If the match of v is matched
            if (dist[match[v]] == INF)
            {
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
    }
    // Returns true if an alternating path has been found
    return dist[0] != INF;
}

// Returns true if an augmenting path has been found starting from vertex node
bool dfs(int u)
{
    if (u == 0)
        return true;
    for (const ll &v : adj[u])
    {
        if (dist[match[v]] == dist[u] + 1 && dfs(match[v]))
        {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

ll hopcroft_karp(int N)
{
    ll cnt = 0;
    // While there is an alternating path
    while (bfs(N))
    {
        for (int u = 1; u <= N; u++)
        {
            // If u is unmatched but we can match it using an augmenting path
            if (!match[u] && dfs(u))
                cnt++;
        }
    }
    return cnt;
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
        int sz = N + M + 1;
        adj.assign(sz, vector<ll>());
        dist.assign(sz, 0);
        match.assign(sz, 0);
        // Potential pairs (edges in the bipartite graph)
        while (K--)
        {
            ll u, v;
            cin >> u >> v;
            // Graph is directed and Unweighted
            // u is a boy, v is a girl (They are two different sets)
            v += N;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << hopcroft_karp(N) << endl;
        for (int boy = 1; boy <= N; boy++)
        {
            if (match[boy])
                cout << boy << ' ' << match[boy] - N << endl;
        }
    }
    return 0;
}
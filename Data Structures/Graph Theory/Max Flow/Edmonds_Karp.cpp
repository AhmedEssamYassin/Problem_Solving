#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

vector<vector<ll>> capacity;
vector<vector<ll>> adj;

ll bfs(vector<ll> &parent, int src, int dest)
{
    fill(parent.begin(), parent.end(), -1);
    parent[src] = -2;
    queue<pair<ll, ll>> q;
    q.push({src, INF});

    while (!q.empty())
    {
        auto &[cur, flow] = q.front();
        q.pop();

        for (auto &next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next] > 0)
            {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == dest)
                    return new_flow; // If we reach the sink, return the flow
                q.push({next, new_flow});
            }
        }
    }

    return 0; // No augmenting path found
}

// Edmonds-Karp implementation for Maximum Flow
ll maxflow(int N, ll src, ll dest)
{
    ll flow = 0;
    vector<ll> parent(N + 1);
    ll new_flow;

    while (new_flow = bfs(parent, src, dest))
    {
        flow += new_flow;
        ll cur = dest;
        while (cur != src)
        {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
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
        cin >> N >> M;
        adj.assign(N + 1, vector<ll>());
        capacity.assign(N + 1, vector<ll>(N + 1));
        while (M--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            // Graph is directed
            adj[u].push_back(v);
            adj[v].push_back(u); // Reverse edge for residual graph
            capacity[u][v] += w; // Handle multiple edges between the same nodes
        }
        cout << maxflow(N, 1, N);
    }
    return 0;
}
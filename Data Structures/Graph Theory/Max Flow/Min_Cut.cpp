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

// Find reachable nodes using BFS on the residual graph
vector<bool> findReachable(int N, int src)
{
    vector<bool> visited(N + 1, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto &next : adj[cur])
        {
            if (!visited[next] && capacity[cur][next] > 0)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return visited;
}

// Find reachable nodes using DFS on the residual graph
void dfs(vector<bool> &visited, ll node)
{
    visited[node] = true;
    for (ll next : adj[node])
    {
        if (!visited[next] && capacity[node][next] > 0)
            dfs(visited, next); // Unvisited and residual capacity > 0
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
        cin >> N >> M;
        adj.assign(N + 1, vector<ll>());
        capacity.assign(N + 1, vector<ll>(N + 1));
        while (M--)
        {
            ll u, v;
            cin >> u >> v;
            // Graph is Undirected and Unweighted
            adj[u].push_back(v);
            adj[v].push_back(u); // Reverse edge for residual graph
            // Capacity of 1 in the graph and residual graph means that it is undirected
            capacity[u][v] = 1;
            capacity[v][u] = 1;
        }
        cout << maxflow(N, 1, N) << endl;
        // vector<bool> reachable = findReachable(N, 1);
        vector<bool> reachable(N + 1, false);
        dfs(reachable, 1);
        for (int u = 1; u <= N; u++)
        {
            for (int v : adj[u])
            {
                if (reachable[u] && !reachable[v])
                    // u is reachable but v is not
                    cout << u << " " << v << endl;
            }
        }
    }
    return 0;
}
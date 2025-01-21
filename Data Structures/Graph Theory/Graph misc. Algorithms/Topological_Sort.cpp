#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<int> topologicalSort;
vector<int> parent;
vector<bool> vis;
vector<int> recStack;
int cycleStart, cycleEnd;
void dfs(vector<vector<ll>> &adj, int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    for (const auto &v : adj[u])
    {
        if (!vis[v])
            dfs(adj, v);
    }
    topologicalSort.push_back(u);
    // This alone cannot check for a cycle in the topological sort
    // We should check on a cycle separately
}
//////////////////////////////////////////////////////////////////////
bool dfsUndirected(vector<vector<ll>> &adj, int u, int par)
{
    vis[u] = true;

    for (const auto &v : adj[u])
    {
        if (!vis[v])
        {
            if (dfsUndirected(adj, v, u))
                return true;
        }
        else if (v != par)
            return true;
    }
    return false;
}

bool hasCycleUndirected(vector<vector<ll>> &adj, int N)
{
    vis.assign(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            if (dfsUndirected(adj, i, -1))
                return true;
        }
    }
    return false;
}

bool dfsDirected(vector<vector<ll>> &adj, int u)
{
    vis[u] = true;
    recStack[u] = true;

    for (const auto &v : adj[u])
    {
        if (!vis[v])
        {
            if (dfsDirected(adj, v))
                return true;
        }
        else if (recStack[v])
            return true;
    }
    recStack[u] = false;
    return false;
}

bool hasCycleDirected(vector<vector<ll>> &adj, int N)
{
    vis.assign(N + 1, false);
    recStack.assign(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            if (dfsDirected(adj, i))
                return true;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////
// Kahn’s Algorithm
vector<int> KahnTopologicalSort(vector<vector<ll>> &adj, int N)
{
    vector<int> inDegree(N + 1);
    for (int u = 1; u <= N; u++)
    {
        for (auto &v : adj[u])
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
        for (auto &v : adj[node])
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
        vector<vector<ll>> adj(N + 1);
        while (M--)
        {
            ll u, v;
            cin >> u >> v;
            // This should be a DAG to work
            adj[u].push_back(v);
        }

        if (hasCycleDirected(adj, N))
            cout << "IMPOSSIBLE";
        else
        {
            // vector<int> result = KahnTopologicalSort(adj, N);
            vis.assign(N + 1, false);
            for (int u = 1; u <= N; u++)
            {
                if (!vis[u])
                    dfs(adj, u);
            }
            reverse(topologicalSort.begin(), topologicalSort.end());
            for (const auto &node : topologicalSort)
                cout << node << " ";
        }
    }
    return 0;
}

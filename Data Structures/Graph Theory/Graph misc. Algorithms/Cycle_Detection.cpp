#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<bool> vis;
vector<int> recStack;
vector<int> path;
//////////////////////////////////////////////////////////////////////
bool dfsUndirected(vector<vector<ll>> &adj, int u, int par)
{
    vis[u] = true;
    path.push_back(u);
    for (const auto &v : adj[u])
    {
        if (!vis[v])
        {
            if (dfsUndirected(adj, v, u))
                return true;
        }
        else if (v != par)
        {
            path.push_back(v);
            return true;
        }
    }
    path.pop_back();
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

void printCycleUndirected(vector<vector<ll>> &adj, int N)
{
    vis.assign(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            if (dfsUndirected(adj, i, -1))
            {
                // Print the cycle
                auto start = find(path.begin(), path.end(), path.back());
                cout << path.end() - start << endl;
                for (auto it = start; it != path.end(); it++)
                    cout << *it << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

bool dfsDirected(vector<vector<ll>> &adj, int u)
{
    vis[u] = true;
    recStack[u] = true;
    path.push_back(u);
    for (const auto &v : adj[u])
    {
        if (!vis[v])
        {
            if (dfsDirected(adj, v))
                return true;
        }
        else if (recStack[v])
        {
            path.push_back(v);
            return true;
        }
    }
    path.pop_back();
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

void printCycleDirected(vector<vector<ll>> &adj, int N)
{
    vis.assign(N + 1, false), recStack.assign(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            if (dfsDirected(adj, i))
            {
                // Print the cycle
                auto start = find(path.begin(), path.end(), path.back());
                cout << path.end() - start << endl;
                for (auto it = start; it != path.end(); ++it)
                    cout << *it << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
            adj[u].push_back(v);
        }

        printCycleDirected(adj, N);
    }
    return 0;
}

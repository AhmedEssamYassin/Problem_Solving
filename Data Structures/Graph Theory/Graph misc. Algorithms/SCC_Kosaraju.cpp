#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<bool> vis;
vector<int> SCC_Label;
void dfs1(vector<vector<ll>> const &adj, int u, vector<ll> &components)
{
    vis[u] = true;
    for (const auto &v : adj[u])
        if (!vis[v])
            dfs1(adj, v, components);
    components.push_back(u);
}

void dfs2(vector<vector<ll>> const &adj_rev, int u, vector<ll> &component, int label)
{
    vis[u] = true;
    SCC_Label[u] = label; // Assign the SCC label
    component.push_back(u);
    for (const auto &v : adj_rev[u])
    {
        if (!vis[v])
            dfs2(adj_rev, v, component, label);
    }
}

void SSC(vector<vector<ll>> const &adj, vector<vector<ll>> &components)
{
    int N = adj.size() - 1;
    components.clear();

    vector<ll> order; // To store the Finish order
    vis.assign(N + 1, false);

    // Step 1: Perform DFS on the original graph to determine the finish order
    for (int u = 1; u <= N; u++)
    {
        if (!vis[u])
            dfs1(adj, u, order);
    }

    // Step 2: Create the reverse graph
    vector<vector<ll>> adj_rev(N + 1);
    for (int u = 1; u <= N; u++)
    {
        for (const auto &v : adj[u])
            adj_rev[v].push_back(u);
    }

    // Step 3: Perform DFS on the reverse graph to find SCCs
    vis.assign(N + 1, false);
    reverse(order.begin(), order.end());
    SCC_Label.assign(N + 1, 0);

    int label = 0; // SCC label counter
    for (const auto &v : order)
    {
        if (!vis[v])
        {
            vector<ll> component;
            dfs2(adj_rev, v, component, ++label);
            components.push_back(component);
        }
    }
    reverse(components.begin(), components.end());
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
        vector<vector<ll>> components;
        SSC(adj, components);

        cout << components.size() << endl;

        // Output the SCC label for each node
        for (int i = 1; i <= N; i++)
            cout << SCC_Label[i] << " ";
        cout << endl;
    }
    return 0;
}

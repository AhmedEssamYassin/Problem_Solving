#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

struct Edge
{
    ll node = -1;
    ll cost = INF;
    Edge(ll node, ll weight) : node(node), cost(weight) {}
    bool operator<(const Edge &E) const { return cost > E.cost; }
};

vector<bool> visited;
vector<int> entryTime, low;
map<pair<int, int>, bool> isBridge;
int timer;

void dfs(vector<Edge> adj[], int u, int par = -1)
{
    visited[u] = true;
    entryTime[u] = low[u] = timer++;
    bool parent_skipped = false;
    for (const auto &[v, w] : adj[u])
    {
        if (v == par && !parent_skipped)
        {
            parent_skipped = true;
            continue;
        }
        if (visited[v])
            low[u] = min(low[u], entryTime[v]);
        else
        {
            dfs(adj, v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > entryTime[u])
                isBridge[{u, v}] = true;
        }
    }
}
// Multiple edges CANNOT be bridge edges
void findBridges(vector<Edge> adj[], int N)
{
    timer = 0;
    visited.assign(N + 1, false);
    entryTime.assign(N + 1, -1);
    low.assign(N + 1, -1);
    for (int u = 0; u <= N; u++)
    {
        if (!visited[u])
            dfs(adj, u);
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
    ll N;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}

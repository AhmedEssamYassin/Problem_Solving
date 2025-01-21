#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define INF LLONG_MAX

class maxFlow
{
public:
    int N;
    vector<vector<ll>> adj;
    vector<vector<ll>> capacity;
    vector<vector<ll>> paths;
    vector<deque<ll>> flowEdges;
    vector<bool> visited;
    maxFlow(int _N)
    {
        N = _N;
        adj.assign(N + 1, vector<ll>());
        flowEdges.assign(N + 1, deque<ll>());
        visited.assign(N + 1, false);
        capacity.assign(N + 1, vector<ll>(N + 1, 0));
    }

    void addEdge(ll u, ll v, ll cap)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Reverse edge for residual graph
        // To handle multiple edges make it +=
        // Capacity of 1 in the graph and residual graph means that it is Unweighted
        capacity[u][v] += cap;
        // capacity[v][u] = cap;// if the graph is Undirected
    }

    ll BFS(int source, int sink, vector<ll> &parents)
    {
        fill(parents.begin(), parents.end(), -1);
        parents[source] = -2;
        queue<pair<ll, ll>> que;
        que.push({source, INF});

        while (!que.empty())
        {
            auto &[current, flow] = que.front();
            que.pop();

            for (const auto &next : adj[current])
            {
                if (parents[next] == -1 && capacity[current][next] > 0)
                {
                    parents[next] = current;
                    ll currentFlow = min(flow, capacity[current][next]);
                    if (next == sink) // If we reach the sink, return the flow
                        return currentFlow;
                    que.push({next, currentFlow});
                }
            }
        }
        return 0; // No augmenting path found
    }

    ll Edmond_Karp(int source, int sink)
    {
        ll flow = 0;

        vector<ll> parents(N + 1);

        ll augmentingFlow = 0;
        while ((augmentingFlow = BFS(source, sink, parents)))
        {
            flow += augmentingFlow;
            ll current = sink;
            while (current != source)
            {
                ll previous = parents[current];
                capacity[previous][current] -= augmentingFlow;
                capacity[current][previous] += augmentingFlow;
                current = previous;
            }
        }
        return flow;
    }
    void dfs(vector<ll> &path, int node, int sink)
    {
        path.push_back(node); // Add the current node to the path
        if (node == sink)
        {
            paths.push_back(path);
            return;
        }
        dfs(path, flowEdges[node].front(), sink);
        flowEdges[node].pop_front();
    }
    void extractPaths(vector<array<ll, 2>> &orgEdges, int src, int sink)
    {
        for (const auto &[u, v] : orgEdges)
            capacity[u][v]--;
        for (int u = 1; u <= sink; u++)
        {
            for (int v = 1; v <= sink; v++)
            {
                if (capacity[u][v] < 0)
                    flowEdges[u].push_back(v); // adding the edge
            }
        }
        while (!flowEdges[src].empty())
        {
            vector<ll> path;
            dfs(path, src, sink);
        }
    }
};

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
        ll src = 1, sink = N;
        maxFlow maxflow(sink + 1);
        while (M--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            // Graph is directed and weighted
            maxflow.addEdge(u, v, w);
        }
        cout << maxflow.Edmond_Karp(src, sink) << endl;
        // maxflow.extractPaths(edges, src, sink);
        // for (const auto &path : maxflow.paths)
        // {
        // 	cout << path.size() << endl;
        // 	for (const auto &node : path)
        // 		cout << node << " ";
        // 	cout << endl;
        // }
    }
    return 0;
}
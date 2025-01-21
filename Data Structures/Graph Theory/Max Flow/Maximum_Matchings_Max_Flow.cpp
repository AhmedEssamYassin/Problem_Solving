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
    /*
    It's possible to determine matchings using only the capacity matrix without maintaining a separate matrix.
    After finding the maximum flow, the capacity matrix is updated to reflect residual capacities.
    Reverse edges in the residual graph indicate the matched pairs.
    */
    vector<bool> visited;
    maxFlow(int _N)
    {
        N = _N;
        adj.assign(N + 1, vector<ll>());
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
    ll N, M, K;
    // cin >> t;
    while (t--)
    {
        cin >> N >> M >> K;
        ll src = 0, sink = N + M + 1;
        maxFlow maxflow(sink + 1);
        // Potential pairs (edges in the bipartite graph)
        while (K--)
        {
            ll u, v;
            cin >> u >> v;
            // Graph is directed and Unweighted
            // u is a boy, v is a girl (They are already two different sets)
            maxflow.addEdge(u, v + N, 1);
        }
        // Transforming the bipartite graph to a network
        // We will add nodes 0 (source) and (N + M + 1) (sink) to the graph

        // Add edges from source to boys
        for (ll i = 1; i <= N; i++)
            maxflow.addEdge(src, i, 1);

        // Add edges from girls to sink
        for (ll i = N + 1; i <= N + M; i++)
            maxflow.addEdge(i, sink, 1);
        cout << maxflow.Edmond_Karp(src, sink) << endl;
        vector<pair<ll, ll>> pairs;
        for (int i = 1; i <= N; i++)
        {
            for (int j = N + 1; j <= N + M; j++)
            {
                if (maxflow.capacity[j][i] > 0)
                    pairs.push_back({i, j - N});
            }
        }
        for (const auto &[boy, girl] : pairs)
            cout << boy << " " << girl << endl;
    }
    return 0;
}
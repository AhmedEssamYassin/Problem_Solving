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

bool dfsBiCheck(int u, int color, vector<int> &colors)
{
    // Assign a color to the current u
    colors[u] = color;

    // Traversing all adjacent vertices
    for (auto &v : adj[u])
    {
        if (colors[v] == -1)
        {
            // Assign alternate color to the adjacent u
            if (dfsBiCheck(v, 1 - color, colors) == false)
                return false;
        }
        else if (colors[v] == color) // If the adjacent u has the same color, it's not bipartite
            return false;
    }
    return true;
}

bool isBipartiteDFS(int N)
{
    // Initialize all vertices as uncolored
    vector<int> colors(N + 1, -1);

    // Check each component of the graph
    for (int i = 1; i <= N; i++)
    {

        // If the vertex is uncolored
        if (colors[i] == -1)
        {
            // If DFS fails, the graph is not bipartite
            if (dfsBiCheck(i, 0, colors) == false)
                return false;
        }
    }

    // All vertices can be colored bipartite
    return true;
}

bool isBipartiteBFS(int N)
{
    vector<int> color(N + 1, -1); // To store colors, -1 means uncolored yet

    queue<int> q;
    // Iterate through all vertices to handle disconnected graphs
    for (int i = 1; i <= N; i++)
    {
        // If the vertex is uncolored, start BFS from it
        if (color[i] == -1)
        {
            // Assign first color (0) to the starting vertex
            color[i] = 0;
            q.push(i);
            // Perform BFS
            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                // Traverse all adjacent vertices
                for (auto &v : adj[u])
                {

                    // If the adjacent vertex is uncolored, assign alternate color
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }

                    // If the adjacent vertex has the same color, graph is NOT bipartite
                    else if (color[v] == color[u])
                        return false;
                }
            }
        }
    }

    // If no conflicts in coloring, graph is bipartite
    return true;
}

vector<int> matchings;
vector<bool> visited;

// Kuhn's algorithm for finding augmenting paths
bool try_kuhn(vector<vector<ll>> &adj, int u)
{
    if (visited[u])
        return false;
    visited[u] = true;

    for (auto &v : adj[u])
    {
        // Try to match the v or find an augmenting path
        if (matchings[v] == -1 || try_kuhn(adj, matchings[v]))
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
            cntPairs += try_kuhn(adj, u);
        }
        cout << cntPairs << endl;
        for (int i = 1; i <= M; i++) // Get matches of every `v` if any
            if (matchings[i] != -1)
                cout << matchings[i] << " " << i << endl;
    }
    return 0;
}
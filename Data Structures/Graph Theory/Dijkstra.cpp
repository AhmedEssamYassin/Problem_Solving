#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// https://www.spoj.com/problems/EZDIJKST/
// https://codeforces.com/contest/20/problem/C
struct Edge
{
    ll cost = LLONG_MAX;
    ll node = -1;
    ll pra = -1;
    Edge(ll n, ll c, ll p = -1)
    {
        node = n;
        cost = c;
        pra = p;
    }
    bool operator<(const Edge &E) const
    {
        return cost > E.cost;
    }
};

void Dijkstra(const vector<Edge> graph[], int N, int u, int v)
{
    vector<ll> len(N + 1, -1), parent(N + 1, -1);
    priority_queue<Edge> prQue;
    prQue.emplace(u, 0);
    while (!prQue.empty())
    {
        Edge cur = prQue.top();
        prQue.pop();
        /*
        If we want the cost of the shortest path from u to v

        if (cur.node == v)
            return void(cout << cur.cost << endl);
        */
        if (len[cur.node] != -1)
            continue;
        len[cur.node] = cur.cost;
        parent[cur.node] = cur.pra;
        for (const Edge &v : graph[cur.node])
            if (len[v.node] == -1)
                prQue.emplace(v.node, v.cost + cur.cost, cur.node);
    }
    // If there were NO path from u to v
    // return void(cout << "NO\n");
    vector<ll> res;
    ll temp = v;
    while (parent[temp] != -1)
    {
        res.push_back(parent[temp]);
        temp = parent[temp];
    }
    if (res.empty())
        return void(cout << "NO" << endl);
    // Print the nodes on the shortest path themselves.
    reverse(res.begin(), res.end());
    for (const ll &i : res)
        cout << i << " ";
    cout << endl;
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
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        vector<Edge> graph[N + 1];
        while (M--)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            // If the Graph is Undirected
            graph[v].push_back({u, w});
        }
        ll A, B;
        cin >> A >> B;
        Dijkstra(graph, N, A, B);
    }
    return 0;
}

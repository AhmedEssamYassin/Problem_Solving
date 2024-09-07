#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct LCA
{
#define L (2 * node)
#define R (2 * node + 1)
#define mid ((left + right) >> 1)
    vector<ll> height, euler, first, segTree;
    vector<bool> visited;
    ll n;

    LCA(const vector<ll> adj[], ll root, ll size)
    {
        n = size;
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        ll m = euler.size();
        segTree.resize(m * 4);
        build(0, m - 1, 1);
    }

    void dfs(const vector<ll> adj[], ll node, ll h = 0)
    {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (const ll &to : adj[node])
        {
            if (!visited[to])
            {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(ll left, ll right, ll node)
    {
        if (left == right)
            segTree[node] = euler[left];
        else
        {
            build(left, mid, L);
            build(mid + 1, right, R);
            ll l = segTree[L], r = segTree[R];
            segTree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    ll query(ll left, ll right, ll leftQuery, ll rightQuery, ll node)
    {
        if (left > rightQuery || right < leftQuery)
            return -1;
        if (left >= leftQuery && right <= rightQuery)
            return segTree[node];

        ll getLeftQuery = query(left, mid, leftQuery, rightQuery, L);
        ll getRightQuery = query(mid + 1, right, leftQuery, rightQuery, R);
        if (getLeftQuery == -1)
            return getRightQuery;
        if (getRightQuery == -1)
            return getLeftQuery;
        return height[getLeftQuery] < height[getRightQuery] ? getLeftQuery : getRightQuery;
    }

    ll lca(ll u, ll v)
    {
        ll left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(0, euler.size() - 1, left, right, 1);
    }
#undef L
#undef R
#undef mid
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
    ll N, M, Q;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        vector<ll> adj[N + 1];
        for (int i{}; i < N; i++)
        {
            cin >> M;
            while (M--)
            {
                ll v;
                cin >> v;
                adj[i].push_back(v);
            }
        }
        LCA LowestCommonAncestor(adj, 0, N);
        cin >> Q;
        while (Q--)
        {
            ll u, v;
            cin >> u >> v;
            cout << LowestCommonAncestor.lca(u, v) << endl;
        }
    }
    return 0;
}
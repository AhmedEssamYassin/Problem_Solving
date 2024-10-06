#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
A Lowest Common Ancestor (LCA) of nodes `a` and `b` in a rooted tree is the deepest (farthest from root) node
that has both `a` and `b` as descendants (where a node can be a descendant of itself)

We can also find LCA for more than 2 nodes like that LCA(a, b, c, d, ...) = LCA(LCA(a, b), LCA(c,d)...)
1. Make sure the tree is rooted (has a root that is a parent of itself)
2. Ensure all nodes have unique indices (usually from 0 to (N - 1))

Eulerian path method:
1. Find the Eulerian tour of the edges in the rooted tree
        0
        |
        1
       / \
      2   3
    The tour [0, 1, 2, 1, 3, 1, 0]
2. Let's maintain the depth of all nodes (depth is 0 at the root level and increments on every coming level)

So for this rooted tree let's find the indices as well as the depths

            0
          /   \
         1     2
         |    / \
         3   4   5
             |
             6
---> idx : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
depth[] = {0, 1, 2, 1, 0, 1, 2, 3, 2, 1, 2,  1,  0}
nodes[] = {0, 1, 3, 1, 0, 2, 4, 6, 4, 2, 5,  2,  0}

Then, what's the LCA(5, 6)
- Find the indices mapped to (5, 6) which are (7, 10)
- Query the index of the minimum value in [7, 10]
  --> the minimum value is 1 and its index is 9, so idx = 9
- The LCA is the element having idx = 9, which is 2
So, LCA(5, 6) = 2

Some nodes will have more than index because they are visited multiple times
So, LCA(1, 2) for example, what indices we choose for 2? 5, 91 or 11?
In fact, it doesn't matter, choose any!
We can for simplicity, maintain the first index mapped to a node and just use it
*/

// Can be used for GCD, LCM, Maximum, Minimum queries, OR this code is for Range Minimum Query AKA RMQ
// Here, the Sparse table works on indices so int32_t is enough
struct sparseTable
{
    int size, LOG;
    vector<vector<int>> m;
    vector<int> arr;

    sparseTable() {}
    sparseTable(const vector<int> &arr, int lg)
    {
        build(arr, lg);
    }

    int merge(const int &a, const int &b) const
    {
        return (arr[a] < arr[b]) ? a : b;
    }

    void build(const vector<int> &arr, int lg)
    {
        int n = arr.size();
        LOG = lg;
        m.resize(n, vector<int>(LOG, 0));
        this->arr = arr;
        int N = arr.size();
        for (int i{}; i < N; i++)
            m[i][0] = i;
        for (int k = 1; k < LOG; k++)
        {
            for (int i{}; i + (1 << k) - 1 < N; i++)
                m[i][k] = merge(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
        }
    }

    int query(int L, int R) const // 0-based
    {
        int len = R - L + 1;
        int k = 31 - __builtin_clz(len);
        return merge(m[L][k], m[R - (1 << k) + 1][k]);
    }
};

struct LCA
{
    int n = 0;
    vector<vector<int>> adj; // Adjacency list
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end;
    vector<int> tour_list, rev_tour_list;
    vector<int> heavy_root;
    vector<int> heavy_root_depth, heavy_root_parent; // These two vectors serve purely to optimize get_kth_ancestor
    sparseTable rmq;
    bool built = false;

    LCA(int _n = 0)
    {
        init(_n);
    }

    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj)
    {
        init(_adj);
    }

    void init(const int &_n)
    {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }

    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj)
    {
        init(int(_adj.size()));
        adj = _adj;
    }

    void add_edge(const int &a, const int &b) // Undirected
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int degree(const int &v) const
    {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }

    void dfs(const int &node, const int &par)
    {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());

        for (const int &child : adj[node])
        {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }

        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b)
             { return subtree_size[a] > subtree_size[b]; });
    }

    int tour{};

    void tour_dfs(const int &node, bool heavy)
    {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;

        for (const int &child : adj[node])
        {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }

        tour_end[node] = tour;
    }

    void build(const vector<int> &roots = {}, bool build_rmq = true)
    {
        depth.assign(n, -1);

        for (const int &root : roots)
            if (depth[root] < 0)
                dfs(root, -1);

        for (int i = 0; i < n; i++)
            if (depth[i] < 0)
                dfs(i, -1);

        tour = 0;
        euler.resize(2 * n, 0);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0)
            {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }

        vector<int> euler_depth;
        euler_depth.reserve(euler.size());

        for (int node : euler)
            euler_depth.push_back(node < 0 ? node : depth[node]);

        if (build_rmq)
            rmq.build(euler_depth, 20);

        euler_depth.clear();
        heavy_root_depth.resize(n);
        heavy_root_parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            heavy_root_depth[i] = depth[heavy_root[i]];
            heavy_root_parent[i] = parent[heavy_root[i]];
        }

        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        built = true;
    }

    pair<int, array<int, 2>> get_diameter() const
    {
        // We find the maximum of depth[u] - 2 * depth[x] + depth[v] where u, x, v occur in order in the Euler tour.
        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};

        for (int node : euler)
        {
            if (node < 0)
                break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
        }

        return uxv_max;
    }

    // Returns the center(s) of the tree (the midpoint(s) of the diameter).
    array<int, 2> get_center() const
    {
        pair<int, array<int, 2>> diam = get_diameter();
        int length = diam.first, a = diam.second[0], b = diam.second[1];
        return {get_kth_node_on_path(a, b, length / 2), get_kth_node_on_path(a, b, (length + 1) / 2)};
    }

    // Note: returns -1 if `a` and `b` aren't connected.
    int get_LCA(int a, int b) const
    {
        a = first_occurrence[a];
        b = first_occurrence[b];

        if (a > b)
            swap(a, b);
        return euler[rmq.query(a, b)];
    }

    bool is_ancestor(const int &a, const int &b) const
    {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }

    bool on_path(const int &x, const int &a, const int &b) const
    {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_LCA(a, b), x);
    }

    int get_dist(const int &a, const int &b) const
    {
        return depth[a] + depth[b] - 2 * depth[get_LCA(a, b)];
    }

    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(const int &a, const int &b) const
    {
        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query(first_occurrence[a], first_occurrence[b] + 1) + 1];
        return child;
    }

    int get_kth_ancestor(int a, const int &k) const
    {
        if (k > depth[a])
            return -1;

        int goal = depth[a] - k;

        while (heavy_root_depth[a] > goal)
            a = heavy_root_parent[a];

        return tour_list[tour_start[a] + goal - depth[a]];
    }

    int get_kth_node_on_path(const int &a, const int &b, const int &k) const
    {
        int anc = get_LCA(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];

        if (k < 0 || k > first_half + second_half)
            return -1;

        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }

    // Note: this is the LCA of any two nodes out of three when the third node is the root.
    // It is also the node with the minimum sum of distances to all three nodes (the centroid of the three nodes).
    int get_common_node(const int &a, const int &b, const int &c) const
    {
        // Return the deepest node among lca(a, b), lca(b, c), and lca(c, a).
        int x = get_LCA(a, b);
        int y = get_LCA(b, c);
        int z = get_LCA(c, a);
        return (x ^ y ^ z);
    }

    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree sorted by tour index. Runs in O(k log k).
    // Note that all parents also appear as a node in the return value, and nodes[0].first is the compressed root.
    vector<pair<int, int>> compress_tree(vector<int> nodes) const
    {
        if (nodes.empty())
            return {};

        auto compare_tour = [&](int a, int b) -> bool
        { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());

        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_LCA(nodes[i], nodes[i + 1]));

        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};

        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_LCA(nodes[i], nodes[i - 1]));

        return result;
    }
};

///////////////////////////////////////////////////////////////////////////////////////

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
    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cout << "Case " << T << ":\n";
        cin >> N;
        LCA lca(N + 1);
        for (int i{1}; i <= N; i++)
        {
            cin >> M;
            while (M--)
            {
                ll v;
                cin >> v;
                lca.add_edge(i, v);
            }
        }
        lca.build();
        cin >> Q;
        while (Q--)
        {
            ll u, v;
            cin >> u >> v;
            cout << lca.get_LCA(u, v) << endl;
        }
    }
    return 0;
}

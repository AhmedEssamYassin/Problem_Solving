#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
    struct Node
    {
        ll value;
        Node() {}
        Node(const ll &N) : value(N) {}
        Node operator+(const Node &RHS)
        {
            value += RHS.value;
            return *this;
        }
    };
    int size;
    vector<Node> seg;
    vector<Node> lazy;
    Node merge(const Node &leftNode, const Node &rightNode)
    {
        Node res = (leftNode.value + rightNode.value);
        return res;
    }
    void build(int left, int right, int node, const vector<ll> &arr)
    {
        // If the segment has only one element, leaf node
        if (left == right)
        {
            if (left < arr.size())
                seg[node] = arr[left];
            return;
        }
        // Recursively build the left child
        build(left, mid, L, arr);
        // Recursively build the right child
        build(mid + 1, right, R, arr);
        // Merge the children values
        seg[node] = merge(seg[L], seg[R]);
    }
    void push(int left, int right, int node)
    {
        // Propagate the value
        if (lazy[node].value == 0)
            return;
        seg[node].value += (right - left + 1) * lazy[node].value;
        // If the node is not a leaf
        if (left != right)
        {
            // Update the lazy values for the left child
            lazy[L].value += lazy[node].value;
            // Update the lazy values for the right child
            lazy[R].value += lazy[node].value;
        }
        // Reset the lazy value
        lazy[node] = 0;
    }
    void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
    {
        push(left, right, node);
        // If the range is invalid, return
        if (left > rightQuery || right < leftQuery)
            return;
        // If the range matches the segment
        if (left >= leftQuery && right <= rightQuery)
        {
            // Update the lazy value
            lazy[node].value += val;
            // Apply the update immediately
            push(left, right, node);
            return;
        }
        // Recursively update the left child
        update(left, mid, L, leftQuery, rightQuery, val);
        // Recursively update the right child
        update(mid + 1, right, R, leftQuery, rightQuery, val);
        // Merge the children values
        seg[node] = merge(seg[L], seg[R]);
    }
    Node query(int left, int right, int node, int leftQuery, int rightQuery)
    {
        // Apply the pending updates if any
        push(left, right, node);
        // If the range is invalid, return a value that does NOT to affect other queries
        if (left > rightQuery || right < leftQuery)
            return 0;

        // If the range matches the segment
        if (left >= leftQuery && right <= rightQuery)
            return seg[node];

        return merge(query(left, mid, L, leftQuery, rightQuery), query(mid + 1, right, R, leftQuery, rightQuery));
    }

public:
    segmentTree(const vector<ll> &arr)
    {
        size = 1;
        int n = arr.size();
        while (size < n)
            size <<= 1;
        seg = vector<Node>(2 * size, 0);
        lazy = vector<Node>(2 * size, 0);
        build(0, size - 1, 0, arr);
    }
    void update(int left, int right, const ll &val)
    {
        update(0, size - 1, 0, left, right, val);
    }
    ll query(int left, int right)
    {
        Node ans = query(0, size - 1, 0, left, right);
        return ans.value;
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
    ll N, M;
    // cin >> t;
    while (t--)
    {
        cin >> N >> M;
        segmentTree segTree(vector<ll>(N, 0));

        while (M--)
        {
            ll query, L, R, val;
            cin >> query >> L >> R;
            if (query == 1)
            {
                cin >> val;
                segTree.update(L, R - 1, val);
            }
            else
            {
                cout << segTree.query(L, R - 1) << endl;
            }
        }
    }
    return 0;
}

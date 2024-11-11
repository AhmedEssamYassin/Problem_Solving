/*
D-query
PSEGTREE
MKTHNUM
Persistent Bookcase
Kth number
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Node
{
    ll Value;
    Node *LeftChild, *RightChild; // Pointers to left child and right child

    Node(const ll &val = 0)
    {
        Value = val;
        LeftChild = nullptr;
        RightChild = nullptr;
    }
    Node(Node *l, Node *r, const ll &val = 0)
    {
        LeftChild = l;
        RightChild = r;
        Value = val;
    }

    void createChildren() // Construct Childs
    {
        if (LeftChild == nullptr)
            LeftChild = new Node();
        if (RightChild == nullptr)
            RightChild = new Node();
    }
    ~Node() // Destructor. Notice the "~" character before the struct name.
    {
        delete LeftChild;
        delete RightChild;
        LeftChild = nullptr;
        RightChild = nullptr;
    }
};
Node *Versions[200001]; // To maintain versions of the segment tree

#define mid ((left + right) >> 1)
ll N = 2e5 + 10;
Node *merge(Node *leftNode, Node *rightNode, bool in_place = 0, Node *Current = nullptr) // In_place for update and insert
{
    ll res = ((leftNode == nullptr ? 0 : leftNode->Value) + (rightNode == nullptr ? 0 : rightNode->Value));

    if (not in_place)
        return new Node(nullptr, nullptr, res);
    else
    {
        Current->Value = res;
        return Current;
    }
}

Node *insert(Node *node, int left, int right, int i, ll val) // Can update for a single version
{
    if (left <= i && right >= i)
    {
        if (node == nullptr)
            node = new Node(val);

        if (left == right)
            return new Node(node->LeftChild, node->RightChild, val);

        Node *goLeft = insert(node->LeftChild, left, mid, i, val);
        Node *goRight = insert(node->RightChild, mid + 1, right, i, val);
        Node *res = new Node(goLeft, goRight);
        return merge(goLeft, goRight, 1, res);
    }
    return node;
}

void update(Node *Current, int left, int right, int idx, const ll &val) // Updates for all versions
{
    // idx is not in range [left, right]
    if (left > idx || right < idx)
        return;

    // Current is the Node that manage only ith element
    if (left == right)
    {
        Current->Value = val;
        return;
    }

    Current->createChildren();
    if (idx <= mid)
        update(Current->LeftChild, left, mid, idx, val);
    else
        update(Current->RightChild, mid + 1, right, idx, val);
    // Don't change the node, change the value at this node
    Current = merge(Current->LeftChild, Current->RightChild, 1, Current);
}

ll query(Node *Current, int left, int right, int leftQuery, int rightQuery)
{
    // [left, right] doesn't intersect with [leftQuery, rightQuery]
    if (Current == nullptr || left > rightQuery || right < leftQuery)
        return 0;

    // [left, curR] is inside [leftQuery, rightQuery]
    if (leftQuery <= left && right <= rightQuery)
        return Current->Value;

    ll leftSegment = query(Current->LeftChild, left, mid, leftQuery, rightQuery);
    ll rightSegment = query(Current->RightChild, mid + 1, right, leftQuery, rightQuery);
    return (leftSegment + rightSegment);
}

// Interface

Node *insert(Node *Current, int i, ll val)
{
    return insert(Current, 1, N, i, val);
}

void update(Node *Current, int idx, const ll &val)
{
    update(Current, 1, N, idx, val);
}

ll query(Node *Current, int left, int right)
{
    ll ans = query(Current, 1, N, left, right);
    return ans;
}

#undef mid

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N, Q, K;
    // cin >> t;
    while (t--)
    {
        cin >> N >> Q;
        Versions[1] = new Node(0);
        for (int i{1}; i <= N; i++)
        {
            ll x;
            cin >> x;
            update(Versions[1], i, x);
        }
        int cur = 2;
        while (Q--)
        {
            int q;
            cin >> q;
            if (q == 1)
            {
                ll k, a, x;
                cin >> k >> a >> x;
                Versions[k] = insert(Versions[k], a, x);
            }
            else if (q == 2)
            {
                ll k, a, b;
                cin >> k >> a >> b;
                cout << query(Versions[k], a, b) << endl; // Doesn't add nodes
            }
            else
            {
                int k;
                cin >> k;
                Versions[cur++] = Versions[k];
            }
        }
    }
    return 0;
}
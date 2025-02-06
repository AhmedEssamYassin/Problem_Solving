#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct dynamicSegmentTree
{
#define mid ((left + right) >> 1)
private:
    struct Node
    {
        ll Value;
        Node *LeftChild, *RightChild; // Pointers to left child and right child

        Node() // Constructor
        {
            Value = 0;
            LeftChild = nullptr;
            RightChild = nullptr;
        }
        Node(const ll &val)
        {
            Value = val;
            LeftChild = nullptr;
            RightChild = nullptr;
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
    ll N;
    Node *root;
    ll merge(const ll &leftNode, const ll &rightNode)
    {
        ll res;
        res = (leftNode + rightNode);
        return res;
    }
    void update(ll left, ll right, Node *Current, ll idx, const ll &newValue)
    {
        // idx is not in range [left, right]
        if (left > idx || right < idx)
            return;

        // Current is the Node that manage only ith element
        if (left == right)
        {
            Current->Value += newValue;
            return;
        }

        Current->createChildren();
        update(left, mid, Current->LeftChild, idx, newValue);
        update(mid + 1, right, Current->RightChild, idx, newValue);
        Current->Value = merge(Current->LeftChild->Value, Current->RightChild->Value);
    }
    ll query(ll left, ll right, Node *Current, ll leftQuery, ll rightQuery)
    {
        // [left, right] doesn't intersect with [leftQuery, rightQuery]
        if (left > rightQuery || right < leftQuery)
            return 0;

        // [left, curR] is inside [leftQuery, rightQuery]
        if (leftQuery <= left && right <= rightQuery)
            return Current->Value;

        Current->createChildren();
        ll leftSegment = query(left, mid, Current->LeftChild, leftQuery, rightQuery);
        ll rightSegment = query(mid + 1, right, Current->RightChild, leftQuery, rightQuery);
        return merge(leftSegment, rightSegment);
    }

public:
    dynamicSegmentTree()
    {
        root = new Node();
        N = 1e9 + 1;
    }
    void update(ll idx, const ll &val)
    {
        update(1, N, root, idx, val);
    }
    ll query(ll left, ll right)
    {
        ll ans = query(1, N, root, left, right);
        return ans;
    }
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
    ll N;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        map<ll, dynamicSegmentTree> mp;

        ll type, time, value;
        for (int i{}; i < N; i++)
        {
            cin >> type >> time >> value;
            if (type == 1) // Insert
                mp[value].update(time, 1);
            else if (type == 2) // Delete
                mp[value].update(time, -1);
            else // Count
                cout << mp[value].query(1, time) << endl;
        }
    }
    return 0;
}
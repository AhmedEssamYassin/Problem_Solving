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

        void createChildren(const int val = 0) // Construct Childs
        {
            if (LeftChild == nullptr)
                LeftChild = new Node(val);
            if (RightChild == nullptr)
                RightChild = new Node(val);
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
    Node *segRoot;
    Node *lazyRoot;
    ll merge(const ll &leftNode, const ll &rightNode) { return leftNode + rightNode; }

    void push(ll left, ll right, Node *segNode, Node *lazyNode)
    {
        // Propagate the value
        if (segNode == nullptr || lazyNode == nullptr || lazyNode->Value == -1)
            return;
        // (a + b + c + d + e) --> (x + x + x + x + x) --> (right - left + 1) * x
        segNode->Value = (right - left + 1) * lazyNode->Value;
        // If the node is not a leaf
        if (left != right)
        {
            // Update the lazy values for the left child
            if (lazyNode->LeftChild == nullptr)
                lazyNode->LeftChild = new Node(lazyNode->Value);
            else
                lazyNode->LeftChild->Value = lazyNode->Value;

            // Update the lazy values for the right child
            if (lazyNode->RightChild == nullptr)
                lazyNode->RightChild = new Node(lazyNode->Value);
            else
                lazyNode->RightChild->Value = lazyNode->Value;
        }
        // Reset the lazy value
        lazyNode->Value = -1;
    }
    void update(ll left, ll right, Node *segNode, Node *lazyNode, ll leftQuery, ll rightQuery, const ll &val)
    {
        push(left, right, segNode, lazyNode);
        // If the range is invalid, return
        if (left > rightQuery || right < leftQuery)
            return;
        // If the range matches the segment
        if (left >= leftQuery && right <= rightQuery)
        {
            // Update the lazy value
            lazyNode->Value = val;
            // Apply the update immediately
            push(left, right, segNode, lazyNode);
            return;
        }
        segNode->createChildren();
        lazyNode->createChildren(-1);
        // Recursively update the left child
        update(left, mid, segNode->LeftChild, lazyNode->LeftChild, leftQuery, rightQuery, val);
        // Recursively update the right child
        update(mid + 1, right, segNode->RightChild, lazyNode->RightChild, leftQuery, rightQuery, val);
        // Merge the children values
        segNode->Value = merge(segNode->LeftChild->Value, segNode->RightChild->Value);
    }
    ll query(ll left, ll right, Node *segNode, Node *lazyNode, ll leftQuery, ll rightQuery)
    {
        // If the range is invalid, return a value that does NOT to affect other queries
        if (left > rightQuery || right < leftQuery)
            return 0;

        // Apply the pending updates if any
        push(left, right, segNode, lazyNode);

        // If the range matches the segment
        if (leftQuery <= left && right <= rightQuery)
            return segNode->Value;
        segNode->createChildren();
        lazyNode->createChildren(-1);
        ll leftSegment = query(left, mid, segNode->LeftChild, lazyNode->LeftChild, leftQuery, rightQuery);
        ll rightSegment = query(mid + 1, right, segNode->RightChild, lazyNode->RightChild, leftQuery, rightQuery);
        return merge(leftSegment, rightSegment);
    }

public:
    dynamicSegmentTree()
    {
        segRoot = new Node();
        lazyRoot = new Node(-1);
        N = 1e5 + 1;
    }
    void update(ll left, ll right, const ll &val)
    {
        update(0, N, segRoot, lazyRoot, left, right, val);
    }
    ll query(ll left, ll right)
    {
        ll ans = query(0, N, segRoot, lazyRoot, left, right);
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
    ll N, M;
    // cin >> t;
    while (t--)
    {
        cin >> N >> M;
        dynamicSegmentTree segTree;
        while (M--)
        {
            ll query, L, R, i, v;
            cin >> query >> L >> R;
            if (query == 1)
            {
                cin >> v;
                segTree.update(L, R - 1, v);
            }
            else
                cout << segTree.query(L, R - 1) << endl;
        }
    }
    return 0;
}
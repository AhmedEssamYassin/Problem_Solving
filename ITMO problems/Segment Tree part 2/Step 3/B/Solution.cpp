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
		ll sum;
		// Constructors
		Node() {}
		Node(const ll &val) : sum(val) {}
	};
	struct LazyNode
	{
		ll value;
		// Constructors
		LazyNode() {}
		LazyNode(const ll &val) : value(val) {}
		LazyNode operator^(const LazyNode &RHS)
		{
			value ^= RHS.value;
			return *this;
		}
	};
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.sum = (leftNode.sum + rightNode.sum);
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
		if (lazy[node].value == 1)
		{
			// 0 0 0 0 1 1 1 1 1 1 --> XORing with 1 (flipping the range) --> 1 1 1 1 0 0 0 0 0 0
			// Number of ones swaps with number of zeros
			seg[node].sum = (right - left + 1) - (seg[node].sum);
			// If the node is not a leaf
			if (left != right)
			{
				// XOR with children because the updating an updated range cancels out just like 1 ^ 1
				// Update the lazy values for the left child
				lazy[L] = (lazy[L] ^ lazy[node]);
				// Update the lazy values for the right child
				lazy[R] = (lazy[R] ^ lazy[node]);
			}
			// Reset the lazy value
			lazy[node] = 0;
		}
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
			lazy[node] = val;
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
	Node query(int left, int right, int node, int k)
	{
		// Apply the pending updates if any
		push(left, right, node);
		if (left == right)
			return left;
		// Apply the pending updates (if any) on the Left segment before using
		push(left, mid, L);
		return (seg[L].sum >= k) ? query(left, mid, L, k) : query(mid + 1, right, R, k - seg[L].sum);
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		lazy = vector<LazyNode>(2 * size, 0); // Assign it to a Not-possible / Neutral value
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	ll query(int k)
	{
		Node ans = query(0, size - 1, 0, k);
		return ans.sum;
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
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		segmentTree segTree(vector<ll>(N, 0));
		while (Q--)
		{
			ll query, L, R, K;
			cin >> query;
			if (query == 1)
			{
				cin >> L >> R;
				segTree.update(L, R - 1, 1);
			}
			else
			{
				cin >> K;
				cout << segTree.query(K + 1) << endl;
			}
		}
	}
	return 0;
}
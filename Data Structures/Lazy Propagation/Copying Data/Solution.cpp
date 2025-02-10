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
	};
	struct LazyNode
	{
		ll cnt, inc;
		LazyNode() {}
		LazyNode(ll b, ll c) : cnt(b), inc(c) {}
	};
	ll sum(const ll &N)
	{
		return N * (N + 1) / 2;
	}
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
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
		if (lazy[node].cnt == -1)
			return;
		ll len = right - left + 1;
		seg[node].value = lazy[node].cnt * len;
		seg[node].value += lazy[node].inc * sum(len - 1);
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L].cnt = lazy[node].cnt;
			lazy[L].inc = lazy[node].inc;
			// Update the lazy values for the right child
			lazy[R].cnt = lazy[node].cnt + (mid - left + 1) * lazy[node].inc;
			lazy[R].inc = lazy[node].inc;
		}
		// Reset the lazy value
		lazy[node] = LazyNode(-1, -1);
	}
	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &a, const ll &d)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			lazy[node].inc = d;
			lazy[node].cnt = a + (left - leftQuery) * d;
			// Apply the update immediately
			push(left, right, node);
			return;
		}
		// Recursively update the left child
		update(left, mid, L, leftQuery, rightQuery, a, d);
		// Recursively update the right child
		update(mid + 1, right, R, leftQuery, rightQuery, a, d);
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
	segmentTree(int n)
	{
		size = 1;
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, -1);
		lazy = vector<LazyNode>(2 * size, LazyNode(-1, -1));
		// build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &a, const ll &d)
	{
		update(0, size - 1, 0, left, right, a, d);
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
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> a(N), b(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		for (int i{}; i < N; i++)
			cin >> b[i];
		segmentTree segTree(N + 1);
		while (Q--)
		{
			int query, x, y, k;
			cin >> query;
			if (query == 1)
			{
				cin >> x >> y >> k;
				x--, y--;
				segTree.update(y, y + k - 1, x, 1);
			}
			else
			{
				cin >> x;
				x--;
				int idx = segTree.query(x, x);
				if (idx == -1)
					cout << b[x] << endl;
				else
					cout << a[idx] << endl;
			}
		}
	}
	return 0;
}
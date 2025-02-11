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
		LazyNode(ll a, ll d) : cnt(a), inc(d) {}
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
		if (lazy[node].cnt == 0)
			return;
		ll len = right - left + 1;
		seg[node].value += lazy[node].cnt * len;
		seg[node].value += lazy[node].inc * sum(len - 1);
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L].cnt += lazy[node].cnt;
			lazy[L].inc += lazy[node].inc;
			// Update the lazy values for the right child
			lazy[R].cnt += lazy[node].cnt + (mid - left + 1) * lazy[node].inc;
			lazy[R].inc += lazy[node].inc;
		}
		// Reset the lazy value
		lazy[node] = LazyNode(0, 0);
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
			lazy[node].cnt = a + (left - leftQuery) * d;
			lazy[node].inc = d;
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
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		lazy = vector<LazyNode>(2 * size, LazyNode(0, 0));
		build(0, size - 1, 0, arr);
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		segmentTree segTree(vector<ll>(N + 1, 0));
		while (M--)
		{
			ll query, L, R, a, d, i;
			cin >> query;
			if (query == 1)
			{
				cin >> L >> R >> a >> d;
				L--, R--;
				segTree.update(L, R, a, d);
			}
			else
			{
				cin >> i;
				i--;
				cout << segTree.query(i, i) << endl;
			}
		}
	}
	return 0;
}
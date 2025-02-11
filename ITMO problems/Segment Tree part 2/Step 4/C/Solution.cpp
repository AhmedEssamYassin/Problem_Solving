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
		ll totalLength, leftMost, rightMost, cnt;
		Node(const ll &N = 0) : totalLength(N), leftMost(N), rightMost(N), cnt(N) {}
	};
	struct LazyNode
	{
		ll value;
		LazyNode(const ll &val) : value(val) {}
	};
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.totalLength = (leftNode.totalLength + rightNode.totalLength);
		res.cnt = (leftNode.cnt + rightNode.cnt);
		res.leftMost = leftNode.leftMost;
		res.rightMost = rightNode.rightMost;
		if (leftNode.rightMost == 1 && rightNode.leftMost == 1)
			res.cnt--; // They become one continuous segment
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
		if (lazy[node].value == -1)
			return;
		if (lazy[node].value == 0)
			seg[node] = 0;
		else
		{
			seg[node].totalLength = right - left + 1;
			seg[node].leftMost = seg[node].rightMost = seg[node].cnt = 1;
		}
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L] = lazy[node];
			// Update the lazy values for the right child
			lazy[R] = lazy[node];
		}
		// Reset the lazy value
		lazy[node] = -1;
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
		lazy = vector<LazyNode>(2 * size, -1);
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	pair<ll, ll> query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return {ans.cnt, ans.totalLength};
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		segmentTree segTree(vector<ll>(1e6 + 1, 0));
		auto giveOffset = [&](ll coord)
		{
			return coord + 5e5;
		};
		for (int i{}; i < N; i++)
		{
			char color;
			int x, l;
			cin >> color >> x >> l;
			x = giveOffset(x);
			if (color == 'W')
				segTree.update(x, x + l - 1, 0);
			else
				segTree.update(x, x + l - 1, 1);
			auto [cnt, totalLength] = segTree.query(0, 1e6);
			cout << cnt << " " << totalLength << endl;
		}
	}
	return 0;
}

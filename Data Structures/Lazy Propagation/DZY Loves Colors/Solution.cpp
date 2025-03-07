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
		ll cnt = 0;
		ll color;
		ll colorfulness;
		Node() {}
		Node(const ll &color, const ll &colorfulness, const ll &cnt)
		{
			this->cnt = cnt;
			this->color = color;
			this->colorfulness = colorfulness;
		}
	};
	struct LazyNode
	{
		ll value = 0, color;
		LazyNode() {}
		LazyNode(const ll &N, const ll &c) : value(N), color(c) {}
	};
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.cnt = (leftNode.cnt + rightNode.cnt);
		res.colorfulness = (leftNode.colorfulness + rightNode.colorfulness);

		// color != 0 if the left segment is the same color as the right segment, 0 otherwise
		res.color = (leftNode.color == rightNode.color) * leftNode.color;
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = {arr[left], 0, 1};
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
		seg[node].color = lazy[node].color;
		seg[node].colorfulness += seg[node].cnt * lazy[node].value;
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L].value += lazy[node].value;
			lazy[L].color = lazy[node].color;
			// Update the lazy values for the right child
			lazy[R].value += lazy[node].value;
			lazy[R].color = lazy[node].color;
		}
		// Reset the lazy value
		lazy[node] = {0, -1};
		return;
	}
	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery && seg[node].color > 0) // The whole segment is the same color
		{
			// Update the lazy value
			lazy[node] = {abs(val - seg[node].color), val};
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
			return {0, 0, 0};

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
		seg = vector<Node>(2 * size, {0, 0, 0});
		lazy = vector<LazyNode>(2 * size, {0, -1});
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.colorfulness;
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
		vector<ll> vc(N + 1);
		iota(vc.begin(), vc.end(), 0);
		segmentTree segTree(vc);
		while (M--)
		{
			ll type, L, R, x;
			cin >> type;
			cin >> L >> R;
			if (type == 1)
			{
				cin >> x;
				segTree.update(L, R, x);
			}
			else
				cout << segTree.query(L, R) << endl;
		}
	}
	return 0;
}
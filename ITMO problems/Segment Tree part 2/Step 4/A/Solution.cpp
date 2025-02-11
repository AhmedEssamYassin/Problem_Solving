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
		ll lazyAddValue;
		ll lazyAssignValue;
		LazyNode() {}
		LazyNode(const ll &add = 0, const ll &assign = -1) : lazyAddValue(add), lazyAssignValue(assign) {}
	};
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.value = (leftNode.value + rightNode.value);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
			return;
		}
		build(left, mid, L, arr);
		build(mid + 1, right, R, arr);
		seg[node] = merge(seg[L], seg[R]);
	}
	void push(int left, int right, int node)
	{
		// check assignment first, because it over-writes every thing
		if (lazy[node].lazyAssignValue != -1)
		{
			seg[node].value = (right - left + 1) * lazy[node].lazyAssignValue;
			if (left != right)
			{
				lazy[L] = {0, lazy[node].lazyAssignValue};

				lazy[R] = {0, lazy[node].lazyAssignValue};
			}
			lazy[node].lazyAssignValue = -1;
		}
		if (lazy[node].lazyAddValue > 0)
		{
			seg[node].value += (right - left + 1) * lazy[node].lazyAddValue;
			if (left != right)
			{
				lazy[L].lazyAddValue += lazy[node].lazyAddValue;
				lazy[R].lazyAddValue += lazy[node].lazyAddValue;
			}
			lazy[node].lazyAddValue = 0;
		}
	}
	void updateAdd(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		if (leftQuery > rightQuery)
			return;

		if (left >= leftQuery && right <= rightQuery)
		{
			lazy[node].lazyAddValue += val; // We don't change the lazyAssignValue, we leave it as it is
			push(left, right, node);
			return;
		}
		updateAdd(left, mid, L, leftQuery, min(rightQuery, mid), val);
		updateAdd(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery, val);
		seg[node] = merge(seg[L], seg[R]);
	}
	void updateAssign(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		if (leftQuery > rightQuery)
			return;

		if (left >= leftQuery && right <= rightQuery)
		{
			lazy[node] = {0, val}; // We cancel the lazyAddValue, because the assignment overwrites the addition
			push(left, right, node);
			return;
		}
		updateAssign(left, mid, L, leftQuery, min(rightQuery, mid), val);
		updateAssign(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery, val);
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		push(left, right, node);
		if (leftQuery > rightQuery || left > rightQuery || right < leftQuery)
			return 0;

		if (left >= leftQuery && right <= rightQuery)
			return seg[node];
		Node leftSegment = query(left, mid, L, leftQuery, min(rightQuery, mid));
		Node rightSegment = query(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		lazy = vector<LazyNode>(2 * size, {0, -1});
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val, int type)
	{
		if (type == 1)
			updateAssign(0, size - 1, 0, left, right, val);
		else
			updateAdd(0, size - 1, 0, left, right, val);
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
			if (query == 1 || query == 2)
			{
				cin >> val;
				segTree.update(L, R - 1, val, query);
			}
			else
				cout << segTree.query(L, R - 1) << endl;
		}
	}
	return 0;
}
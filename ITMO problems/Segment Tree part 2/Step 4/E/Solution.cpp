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
		ll minValue;
		ll maxValue;
		Node(const ll &a = LLONG_MAX, const ll &b = LLONG_MIN) : minValue(a), maxValue(b) {}
	};
	// The LazyNode here is just the same as Node
	int size;
	vector<Node> seg;
	vector<Node> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.minValue = min(leftNode.minValue, rightNode.minValue);
		res.maxValue = max(leftNode.maxValue, rightNode.maxValue);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = {arr[left], arr[left]};
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
		if (lazy[node].minValue == -1)
			return;

		ll leastH = lazy[node].minValue;
		ll mostH = lazy[node].maxValue;
		if (lazy[node].maxValue < leastH) // That means also the minValue < leastH of course, both will reach leastH
			seg[node] = {leastH, leastH};
		else
			seg[node].minValue = max(seg[node].minValue, leastH); // minValue will be leastH if it is less than leastH

		if (seg[node].minValue > mostH) // That means also the maxValue > mostH of course, both will go down to mostH
			seg[node] = {mostH, mostH};
		else
			seg[node].maxValue = min(seg[node].maxValue, mostH); // maxValue will be mostH if it is greater than mostH

		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the children
			auto updateChildLazy = [&](Node &child)
			{
				if (child.minValue == -1) // Has NO pending update
					child = lazy[node];

				else
				{
					if (child.maxValue < lazy[node].minValue) // That means also the minValue < leastH of course, both will reach leastH
						child = {lazy[node].minValue, lazy[node].minValue};
					else
						child.minValue = max(child.minValue, lazy[node].minValue); // minValue will be leastH if it is less than leastH

					if (child.minValue > lazy[node].maxValue) // That means also the maxValue > mostH of course, both will go down to mostH
						child = {lazy[node].maxValue, lazy[node].maxValue};
					else
						child.maxValue = min(child.maxValue, lazy[node].maxValue); // maxValue will be mostH if it is greater than mostH
				}
			};
			updateChildLazy(lazy[L]);
			updateChildLazy(lazy[R]);
		}

		// Reset the lazy value
		lazy[node] = {-1, -1};
	}
	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val, ll type)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			if (type == 1)
				lazy[node] = {val, LLONG_MAX};
			else
				lazy[node] = {LLONG_MIN, val};

			// Apply the update immediately
			push(left, right, node);
			return;
		}
		// Recursively update the left child
		update(left, mid, L, leftQuery, rightQuery, val, type);
		// Recursively update the right child
		update(mid + 1, right, R, leftQuery, rightQuery, val, type);
		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Apply the pending updates if any
		push(left, right, node);
		// If the range is invalid, return a value that does NOT to affect other queries
		if (left > rightQuery || right < leftQuery)
			return {LLONG_MAX, LLONG_MIN};

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
		seg = vector<Node>(2 * size, {LLONG_MAX, LLONG_MIN});
		lazy = vector<Node>(2 * size, {-1, -1});
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val, ll type)
	{
		update(0, size - 1, 0, left, right, val, type);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.minValue;
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
	ll N, K;
	// cin >> t;
	while (t--)
	{
		cin >> N >> K;
		segmentTree segTree(vector<ll>(N + 1, 0));

		while (K--)
		{
			ll query, L, R, h;
			cin >> query >> L >> R >> h;
			if (query == 1)
				segTree.update(L, R, h, 1);
			else
				segTree.update(L, R, h, 2);
		}
		for (int i{}; i < N; i++)
			cout << segTree.query(i, i) << endl;
	}
	return 0;
}
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
		ll weightedSum;
		Node(const ll &N = 0, const int &idx = 1) : sum(N), weightedSum(idx * N) {}
	};
	struct LazyNode
	{
		ll value;
		LazyNode(const ll &val) : value(val) {}
		LazyNode operator+(const LazyNode &RHS)
		{
			value += RHS.value;
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
		res.weightedSum = (leftNode.weightedSum + rightNode.weightedSum);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = Node(arr[left], left + 1);
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
		ll len = right - left + 1;
		seg[node].sum += len * lazy[node].value;
		/*
		(len / 2) * (first_term + last_term)
		(len / 2) * (a + (a + (len - 1) * d))
		since d = 1
		(len / 2) * (a + a + len - 1)
		(len / 2) * (2a + len - 1)
		a * len + len * (len - 1) / 2
		add (-len + len) = (-len + (2 * len) / 2) to make denominators equal, we get:
		(a * len - len) + len * (len - 1) / 2 + (2 * len / 2)
		(a - 1) * len + len * (len + 1) / 2
		*/
		seg[node].weightedSum += (left * len + (len * (len + 1)) / 2) * lazy[node].value;
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L] = lazy[L] + lazy[node];
			// Update the lazy values for the right child
			lazy[R] = lazy[R] + lazy[node];
		}
		// Reset the lazy value
		lazy[node] = 0;
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
		lazy = vector<LazyNode>(2 * size, 0);
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		/*
		If we have the full range: [a, b, c, d, e, f, g, h]
		Then, the weighted sum is: [1a + 2b + 3c + 4d + 5e + 6f + 7g + 8h]
		When we query the range [2, 4] (0-based), i.e., [c, d, e]
		That means, we need the value (1c + 2d + 3e) but we have the value (3c + 4d + 5e)
		It can be easily noticed that the required range is just (3c + 4d + 5e) - 2 * (a + b + c)
		This is equivalent to left shift the weighted sum by (left)
		*/
		return ans.weightedSum - left * ans.sum;
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
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		segmentTree segTree(vc);

		while (M--)
		{
			ll query, L, R, d;
			cin >> query >> L >> R;
			L--, R--; // To be 0-based
			if (query == 1)
			{
				cin >> d;
				segTree.update(L, R, d);
			}
			else
				cout << segTree.query(L, R) << endl;
		}
	}
	return 0;
}

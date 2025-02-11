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
		int sum;
		// Constructors
		Node() {}
		Node(ll val) : sum(val) {}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.sum = (leftNode.sum + rightNode.sum);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = Node(arr[left]);
			return;
		}

		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int idx, ll val)
	{
		if (left == right)
		{
			seg[node].sum += val;
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, val);
		else
			update(mid + 1, right, R, idx, val);

		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int k)
	{
		if (left == right)
		{
			seg[node].sum -= (seg[node].sum > 0);
			return;
		}
		ll leftSum = seg[L].sum;
		if (k <= leftSum)
			update(left, mid, L, k);
		else
			update(mid + 1, right, R, k - leftSum);

		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Out of range
		if (right < leftQuery || left > rightQuery)
			return 0;
		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];
		// ONLY a part of this segment belongs to the query
		Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
		Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(0));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, ll val)
	{
		update(0, size - 1, 0, idx, val);
	}
	void update(int idx)
	{
		update(0, size - 1, 0, idx);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
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
	ll N, Q, X, Ki;
	cin >> N >> Q;
	segmentTree segTree(vector<ll>(N + 1, 0));
	for (int i{}; i < N; i++)
	{
		cin >> X;
		segTree.update(X, 1);
	}

	while (Q--)
	{
		cin >> Ki;
		if (Ki > 0)
			segTree.update(Ki, 1);
		else
			segTree.update(-Ki);
	}
	for (int i{}; i <= N; i++)
	{
		if (segTree.query(0, i) > 0)
			return cout << i, 0;
	}
	cout << 0;
	return 0;
}
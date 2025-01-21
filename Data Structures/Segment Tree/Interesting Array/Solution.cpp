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
		ll AND;
		// Constructors
		Node() {}
		Node(const ll &val) : AND(val) {}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.AND = (leftNode.AND & rightNode.AND);
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
		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int idx, const ll &val)
	{
		if (left == right)
		{
			seg[node] = val;
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, val);
		else
			update(mid + 1, right, R, idx, val);
		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Out of range
		if (right < leftQuery || left > rightQuery)
			return -1; // A value that doesn't affect the query

		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		else // ONLY a part of this segment belongs to the query
		{
			Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
			Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
			return merge(leftSegment, rightSegment);
		}
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		ll n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, -1);
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.AND;
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
		vector<ll> arr(N, 0);
		vector<tuple<int, int, int>> queries(M);
		for (auto &[l, r, q] : queries)
		{
			cin >> l >> r >> q;
			l--, r--;
		}

		for (int k = 0; k < 31; k++)
		{
			vector<ll> range(N + 1, 0);
			for (const auto &[l, r, q] : queries)
			{
				if (q & (1LL << k))
					range[l]++, range[r + 1]--;
			}
			for (int i{}; i < N; i++)
			{
				if (i)
					range[i] += range[i - 1];
				if (range[i] > 0)
					arr[i] |= (1LL << k);
			}
		}
		segmentTree segTree(arr);
		for (auto &[l, r, q] : queries)
			if (segTree.query(l, r) != q)
				return cout << "NO", 0;
		cout << "YES\n";
		for (ll &x : arr)
			cout << x << " ";
	}
	return 0;
}
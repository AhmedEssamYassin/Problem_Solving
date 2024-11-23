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
		// Constructors
		Node() {}
		Node(ll val) : value(val) {}
	};
	int size;
	vector<Node> seg;
	Node merge(Node &leftNode, Node &rightNode)
	{
		Node res;
		res.value = (leftNode.value + rightNode.value);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		if (left == right) // Leaf Node (single element)
		{
			if (left < arr.size()) // Making sure we are inside the boundaries of the array
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
			seg[node].value += val;
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
			return 0; // A value that doesn't affect the query

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
		size = __bit_ceil(arr.size());
		seg = vector<Node>(2 * size, 0);
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
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

struct cup
{
	ll capacity;
	ll value;
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
	ll N, M, i, X, K, q;
	cin >> N >> M;
	vector<cup> vc(N, {0, 0});
	for (int i{}; i < N; i++)
		cin >> vc[i].capacity;
	segmentTree segTree(vector<ll>(1000000, 0));
	while (M--)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> i >> X;
			i--; // To be 0-based
			if (X <= vc[i].capacity - vc[i].value)
			{
				segTree.update(vc[i].value, -1);
				segTree.update(vc[i].value + X, 1);
				vc[i].value += X;
			}
		}
		else if (q == 2)
		{
			cin >> i >> X;
			i--; // To be 0-based
			if (X <= vc[i].value)
			{
				segTree.update(vc[i].value, -1);
				segTree.update(vc[i].value - X, 1);
				vc[i].value -= X;
			}
		}
		else
		{
			cin >> K;
			cout << segTree.query(K, 1000000) << endl;
		}
	}
	return 0;
}
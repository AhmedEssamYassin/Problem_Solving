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
		// Constructors
		Node() {}
		Node(const ll &value) : minValue(value) {}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.minValue = min(leftNode.minValue, rightNode.minValue);
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
	void update(int left, int right, int node, int idx, const ll &value)
	{
		if (left == right)
		{
			seg[node] = Node(value);
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, value);
		else
			update(mid + 1, right, R, idx, value);

		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery, int P)
	{
		if (right < leftQuery || left > rightQuery)
			return 0;

		if (leftQuery > rightQuery)
			return 0; // Neutral addend
		if (seg[node].minValue > P)
			return 0;
		if (left == right) // Leaf node
		{
			Node res;
			res.minValue = 1;
			seg[node] = Node(INT_MAX); // Ruining this building
			return res;
		}
		Node traverseLeft = query(left, mid, L, leftQuery, min(rightQuery, mid), P);
		Node traverseRight = query(mid + 1, right, R, max(mid + 1, leftQuery), rightQuery, P);
		seg[node] = merge(seg[L], seg[R]);

		return traverseLeft.minValue + traverseRight.minValue;
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(INT_MAX));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right, int P)
	{
		Node ans = query(0, size - 1, 0, left, right, P);
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
	ll N, M, q, i, h, L, R, P;
	cin >> N >> M;
	segmentTree segTree(vector<ll>(N, INT_MAX));
	while (M--)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> i >> h;
			segTree.update(i, h);
		}
		else
		{
			cin >> L >> R >> P;
			// Answering the query
			cout << segTree.query(L, R - 1, P) << endl;
		}
	}
	return 0;
}
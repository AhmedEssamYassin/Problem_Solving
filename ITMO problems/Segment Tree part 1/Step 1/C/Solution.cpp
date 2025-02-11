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
		int countMinVal{};
		// Constructors
		Node() {}
		Node(ll val, int cnt)
		{
			value = val;
			countMinVal = cnt;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		if (leftNode.value == rightNode.value)
			return Node(leftNode.value, leftNode.countMinVal + rightNode.countMinVal);
		else
		{
			if (leftNode.value < rightNode.value)
				return leftNode;
			else
				return rightNode;
		}
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = Node(arr[left], 1);
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
			seg[node] = Node(val, 1);
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
			return Node(LLONG_MAX, 1); // A value that doesn't affect the minimization

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
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(LLONG_MAX, 1));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	pair<int, int> query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return {ans.value, ans.countMinVal};
	}

#undef L
#undef R
#undef mid
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, M, q, i, v, L, R;
	cin >> N >> M;
	vector<ll> vc(N);
	for (int i{}; i < N; i++)
		cin >> vc[i];
	segmentTree segTree(vc);
	while (M--)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> i >> v;
			segTree.update(i, v);
		}
		else
		{
			cin >> L >> R;
			auto [minVal, countMinVal] = segTree.query(L, R - 1);
			cout << minVal << " " << countMinVal << endl;
		}
	}

	return 0;
}
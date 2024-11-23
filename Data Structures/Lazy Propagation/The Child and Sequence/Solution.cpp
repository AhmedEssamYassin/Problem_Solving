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
		ll maxVal;
		Node() {}
		Node(const ll &N)
		{
			value = N;
			maxVal = N;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.value = (leftNode.value + rightNode.value);
		res.maxVal = max(leftNode.maxVal, rightNode.maxVal);
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
		}
		else
		{
			// Recursively build the left child
			build(left, mid, L, arr);
			// Recursively build the right child
			build(mid + 1, right, R, arr);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}
	void rangeUpdate(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		if (left > rightQuery || right < leftQuery)
			return;
		if (left == right)
		{
			if (left >= leftQuery && right <= rightQuery)
				seg[node] = (seg[node].value % val);
			return;
		}
		if (seg[L].maxVal >= val)
			rangeUpdate(left, mid, L, leftQuery, rightQuery, val);
		if (seg[R].maxVal >= val)
			rangeUpdate(mid + 1, right, R, leftQuery, rightQuery, val);

		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}

	void pointUpdate(int left, int right, int node, int idx, const ll &val)
	{
		if (idx > right || idx < left)
			return;
		if (left == right)
		{
			seg[node] = val;
			return;
		}
		pointUpdate(left, mid, L, idx, val);
		pointUpdate(mid + 1, right, R, idx, val);
		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}

	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// If the range is invalid, return a value that does NOT to affect other queries
		if (left > rightQuery || right < leftQuery)
			return 0;

		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		Node getLeftQuery = query(left, mid, L, leftQuery, rightQuery);
		Node getRightQuery = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(getLeftQuery, getRightQuery);
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val, int type, int idx = 0)
	{
		if (type == 1)
			rangeUpdate(0, size - 1, 0, left, right, val);
		else
			pointUpdate(0, size - 1, 0, idx, val);
	}
	Node query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans;
	}
	void print()
	{
		for (int i = 7; i < 15; i++)
			cout << seg[i].value << " ";
		cout << endl;
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
		vector<ll> A(N);
		for (int i{}; i < N; i++)
			cin >> A[i];
		segmentTree segTree(A);

		while (M--)
		{
			ll query, L, R, x, i, v;
			cin >> query;
			if (query == 1)
			{
				cin >> L >> R;
				L--, R--;
				cout << segTree.query(L, R).value << "\n";
			}
			else if (query == 2)
			{
				cin >> L >> R >> x;
				L--, R--;
				segTree.update(L, R, x, 1, 0);
			}
			else
			{
				cin >> i >> x;
				i--;
				segTree.update(0, 0, x, 2, i);
			}
		}
	}
	return 0;
}
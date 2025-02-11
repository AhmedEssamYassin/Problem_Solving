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
		int O{}, C{}, len{};
		// Constructors
		Node() {}
		Node(const char &x)
		{
			O += (x == '(');
			C += (x == ')');
			len = 0;
		}
	};

	int size;
	vector<Node> seg;
	Node merge(Node &leftNode, Node &rightNode)
	{
		Node res;
		ll regular = min(leftNode.O, rightNode.C);
		res.len = leftNode.len + rightNode.len + regular;
		res.O = leftNode.O + rightNode.O - regular;
		res.C = leftNode.C + rightNode.C - regular;
		return res;
	}
	void build(int left, int right, int node, const string &arr)
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

	// No update here
	void update(int left, int right, int node, int idx, const ll &val)
	{
		if (left == right)
		{
			seg[node] = {};
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
			return ' '; // A value that doesn't affect the query

		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		// ONLY a part of this segment belongs to the query
		Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
		Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	segmentTree(const string &str)
	{
		size = 1;
		int n = str.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, ' ');
		build(0, size - 1, 0, str);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.len;
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
	ll N;
	// cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		segmentTree segTree(str);
		cin >> N;
		while (N--)
		{
			ll L, R;
			cin >> L >> R;
			L--, R--;
			cout << (segTree.query(L, R) << 1) << endl;
		}
	}
	return 0;
}
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
		int countDistinct{};
		bitset<26> distinct; // All is cleared by default
		// Constructors
		Node() {}
		Node(char val, int cnt)
		{
			countDistinct = cnt;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(Node &leftNode, Node &rightNode)
	{
		Node res;
		res.distinct = (leftNode.distinct | rightNode.distinct);
		res.countDistinct = res.distinct.count();
		return res;
	}
	void build(int left, int right, int node, string &arr)
	{
		if (left == right) // Leaf Node (single element)
		{
			if (left < arr.size()) // Making sure we are inside the boundaries of the array
				seg[node].countDistinct = 1, seg[node].distinct[arr[left] - 'a'] = 1;
			return;
		}
		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int idx, const char &val)
	{
		if (left == right)
		{
			seg[node].countDistinct = 1;
			seg[node].distinct.reset();
			seg[node].distinct[val - 'a'] = 1;
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
			return Node(0, 0); // A value that doesn't affect the solution

		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		// ONLY a part of this segment belongs to the query
		Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
		Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	segmentTree(string &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(0, 0));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.countDistinct;
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
	ll N, Q, query, pos, L, R;
	char C;
	string str;
	// cin >> t;
	while (t--)
	{
		cin >> str;
		segmentTree segTree(str);
		cin >> Q;
		while (Q--)
		{
			cin >> query;
			if (query == 1)
			{
				cin >> pos >> C;
				pos--;
				segTree.update(pos, C);
			}
			else
			{
				cin >> L >> R;
				L--, R--;
				cout << segTree.query(L, R) << endl;
			}
		}
	}
	return 0;
}
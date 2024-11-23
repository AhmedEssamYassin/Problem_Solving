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
		Node(const ll &value) : value(value) {}
	};

	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode, int type)
	{
		Node res;
		if (type == 1) // OR
			res.value = (leftNode.value | rightNode.value);
		else // XOR
			res.value = (leftNode.value ^ rightNode.value);
		return res;
	}
	template <typename T>
	void build(int left, int right, int node, vector<T> &arr)
	{
		if (left == right) // Leaf node (single element)
		{
			if (left < arr.size()) // Making sure we are inside the boundaries of the array
				seg[node] = Node(arr[left]);
			return;
		}

		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		if (__builtin_ctz(right - left + 1) & 1)
			seg[node] = merge(seg[L], seg[R], 1); // OR
		else
			seg[node] = merge(seg[L], seg[R], 2); // XOR
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
		if (__builtin_ctz(right - left + 1) & 1)
			seg[node] = merge(seg[L], seg[R], 1); // OR
		else
			seg[node] = merge(seg[L], seg[R], 2); // XOR
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Out of range
		if (right < leftQuery || left > rightQuery)
			return Node(0); // A value that doesn't affect the answer

		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		else // ONLY a part of this segment belongs to the query
		{
			Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
			Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
			return merge(leftSegment, rightSegment, 3); // NOT reached
		}
	}

public:
	template <typename T>
	segmentTree(vector<T> &arr)
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
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.value;
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
	int N, M, P, B;
	cin >> N >> M;
	vector<int> vc(1 << N);
	for (int i{}; i < (1 << N); i++)
		cin >> vc[i];
	segmentTree segTree(vc);
	while (M--)
	{
		cin >> P >> B;
		segTree.update(P - 1, B);
		cout << segTree.query(0, (1 << N) - 1) << endl;
	}
	return 0;
}
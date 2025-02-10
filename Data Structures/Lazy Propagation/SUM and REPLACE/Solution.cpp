#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<ll> countDivisors(1000001, 1);

template <typename T>
T D(T N)
{
	return countDivisors[N];
}

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
		Node(const ll &N) : value(N), maxVal(N) {}
		Node(const ll &val, const ll &max) : value(val), maxVal(max) {}
		Node operator+(const Node &RHS)
		{
			value = (value + RHS.value);
			return *this;
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
		// If the segment has only one element
		if (left == right)
		{
			if (left < arr.size())
				seg[node] = arr[left];
			return;
		}
		// Recursively build the left child
		build(left, mid, L, arr);
		// Recursively build the right child
		build(mid + 1, right, R, arr);

		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}

	void update(int left, int right, int node, int leftQuery, int rightQuery)
	{
		if (left > rightQuery || right < leftQuery)
			return;
		if (left == right)
		{
			seg[node] = D(seg[node].value);
			return;
		}
		if (leftQuery <= mid && seg[L].maxVal > 2)
			update(left, mid, L, leftQuery, rightQuery);
		if (rightQuery > mid && seg[R].maxVal > 2)
			update(mid + 1, right, R, leftQuery, rightQuery);

		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// If the range is invalid, return a value that does NOT to affect other queries
		if (left > rightQuery || right < leftQuery)
			return Node(0, -1);

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
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right)
	{
		update(0, size - 1, 0, left, right);
	}
	Node query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans;
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
		for (int i{2}; i <= 1000000; i++)
		{
			for (int j = i; j <= 1000000; j += i)
				countDivisors[j] += 1;
		}

		cin >> N >> M;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		segmentTree segTree(vc);
		while (M--)
		{
			ll query, L, R;
			cin >> query >> L >> R;
			L--, R--; // To be 0-based
			if (query == 1)
			{
				if (segTree.query(L, R).maxVal > 2)
					segTree.update(L, R);
			}
			else
				cout << segTree.query(L, R).value << endl;
		}
	}
	return 0;
}
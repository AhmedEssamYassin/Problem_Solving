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
		ll GCD;
		ll cnt{};
		Node() {}
		Node(const ll &N) : GCD(N), cnt(1) {}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.GCD = gcd(leftNode.GCD, rightNode.GCD);
		// count how many elements in both ranges having value = gcd = minimum
		if (res.GCD == leftNode.GCD && res.GCD == rightNode.GCD)
			res.cnt = leftNode.cnt + rightNode.cnt;
		else if (res.GCD == leftNode.GCD)
			res.cnt = leftNode.cnt;
		else if (res.GCD == rightNode.GCD)
			res.cnt = rightNode.cnt;

		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element
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

	void update(int left, int right, int node, int idx, ll val)
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
		// If the range is invalid, return a value that does NOT to affect other queries
		if (left > rightQuery || right < leftQuery)
			return 0;

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
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.cnt;
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
	ll N, L, R;
	cin >> N;
	vector<ll> S(N);
	for (int i{}; i < N; i++)
		cin >> S[i];
	segmentTree segTree(S);
	cin >> t;
	while (t--)
	{
		cin >> L >> R;
		L--, R--; // To be 0-based
		cout << (R - L + 1) - segTree.query(L, R) << endl;
	}
	return 0;
}
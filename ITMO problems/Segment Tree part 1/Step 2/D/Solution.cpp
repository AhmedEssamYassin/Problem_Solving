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
		ll maxValue;
		// Constructors
		Node() {}
		Node(ll val) : maxValue(val) {}
	};
	int size;
	vector<Node> seg;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.maxValue = max(leftNode.maxValue, rightNode.maxValue);
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
	void update(int left, int right, int node, int idx, ll val)
	{
		if (left == right)
		{
			seg[node].maxValue = val;
			return;
		}
		if (idx <= mid)
			update(left, mid, L, idx, val);
		else
			update(mid + 1, right, R, idx, val);

		// Updating while returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int x, int pos)
	{
		if (seg[node].maxValue < x || right < pos) // Invalid subtree
			return -1;
		if (left == right)
			return {left};

		Node traversingLeft = query(left, mid, L, x, pos);
		if (traversingLeft.maxValue == -1)
			return query(mid + 1, right, R, x, pos);
		else
			return traversingLeft;
	}

public:
	segmentTree(const vector<ll> &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, Node(0));
		build(0, size - 1, 0, arr);
	}
	void update(int idx, ll val)
	{
		update(0, size - 1, 0, idx, val);
	}
	ll query(ll x, int pos)
	{
		Node ans = query(0, size - 1, 0, x, pos);
		return ans.maxValue;
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
	ll N, M, i, v, x, pos, q;
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
			cin >> x >> pos;
			int ans = segTree.query(x, pos);
			if (ans > N)
				cout << -1 << endl;
			else
				cout << ans << endl;
		}
	}
	return 0;
}
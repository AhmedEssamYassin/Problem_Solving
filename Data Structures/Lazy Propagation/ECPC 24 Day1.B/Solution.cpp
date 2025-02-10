#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const ll mod = 1e9 + 7;
ll mult(const initializer_list<ll> &init)
{
	ll res{1};
	for (const ll &x : init)
		res = (res % mod * x % mod) % mod;
	return res;
}

ll modBinExp(ll N, ll power, ll mod)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = mult({res, N});
		N = mult({N, N});
		power >>= 1;
	}
	return res;
}

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll sum1, sum2, sum3;
		// Constructors
		Node() {}
		Node(const ll &val)
		{
			sum1 = val;
			sum2 = mult({val, val});
			sum3 = mult({val, val, val});
		}
	};
	struct LazyNode
	{
		ll value;
		// Constructors
		LazyNode() {}
		LazyNode(const ll &val) : value(val) {}
		LazyNode operator+(const LazyNode &RHS)
		{
			value = (value + RHS.value);
			value %= mod;
			return *this;
		}
	};
	int size;
	vector<Node> seg;
	vector<LazyNode> lazy;
	Node merge(const Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.sum1 = (leftNode.sum1 + rightNode.sum1);
		res.sum2 = (leftNode.sum2 + rightNode.sum2);
		res.sum3 = (leftNode.sum3 + rightNode.sum3);
		res.sum1 %= mod;
		res.sum2 %= mod;
		res.sum3 %= mod;
		return res;
	}
	void build(int left, int right, int node, const vector<ll> &arr)
	{
		// If the segment has only one element, leaf node
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
	void push(int left, int right, int node)
	{
		// Propagate the value
		const ll &upd = lazy[node].value;
		ll &X = seg[node].sum3;
		X = (X + mult({(right - left + 1), modBinExp(upd, 3, mod)})) % mod;
		X = (X + 3 * mult({seg[node].sum1, modBinExp(upd, 2, mod)})) % mod;
		X = (X + 3 * mult({seg[node].sum2, upd})) % mod;
		X %= mod;
		////////////////////////
		ll &Y = seg[node].sum2;
		Y = (Y + mult({(right - left + 1), modBinExp(upd, 2, mod)}));
		Y = (Y + 2 * mult({seg[node].sum1, upd}));
		Y %= mod;
		///////////////////////
		ll &Z = seg[node].sum1;
		Z += mult({upd, right - left + 1});
		Z %= mod;
		// If the node is not a leaf
		if (left != right)
		{
			// Update the lazy values for the left child
			lazy[L] = (lazy[L] + lazy[node]);
			// Update the lazy values for the right child
			lazy[R] = (lazy[R] + lazy[node]);
		}
		// Reset the lazy value
		lazy[node] = 0;
	}
	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (left > rightQuery || right < leftQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			lazy[node] = (lazy[node] + val);

			// Apply the update immediately
			push(left, right, node);
			return;
		}
		// Recursively update the left child
		update(left, mid, L, leftQuery, rightQuery, val);
		// Recursively update the right child
		update(mid + 1, right, R, leftQuery, rightQuery, val);
		// Merge the children values
		seg[node] = merge(seg[L], seg[R]);
	}
	Node query(int left, int right, int node, int leftQuery, int rightQuery)
	{
		// Apply the pending updates if any
		push(left, right, node);
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
		lazy = vector<LazyNode>(2 * size, 0);
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.sum3 % mod;
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
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];

		segmentTree segTree(vc);
		cin >> Q;
		while (Q--)
		{
			ll query, L, R, val;
			cin >> query >> L >> R;
			L--, R--;
			if (query == 1)
			{
				cin >> val;
				segTree.update(L, R, val);
			}
			else
				cout << segTree.query(L, R) << endl;
		}
	}
	return 0;
}
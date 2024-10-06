#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const int BITS = 19;
struct XORBasis
{
	int sz = 0;
	array<int, BITS> basis{};

	void insertVector(ll x)
	{
		if (sz == BITS)
			return;
		for (ll i = __lg(x); x > 0; i = __lg(x))
		{
			if (!basis[i])
				return sz++, void(basis[i] = x);
			x ^= basis[i];
		}
	}

	bool canRepresent(ll x)
	{
		if (sz == BITS)
			return true;
		for (ll i = __lg(x); x > 0; i = __lg(x))
		{
			if (basis[i])
				x ^= basis[i];
			else
				return false;
		}
		return !x;
	}

	ll getMaxXor()
	{
		if (sz == BITS)
			return (1LL << BITS) - 1;
		ll maxXor = 0;
		for (int i = BITS - 1; i >= 0; i--)
		{
			if ((maxXor ^ basis[i]) > maxXor)
				maxXor ^= basis[i];
		}
		return maxXor;
	}

	friend XORBasis operator+(const XORBasis &LHS, const XORBasis &RHS)
	{
		XORBasis res;
		if (LHS.sz == BITS)
			return LHS;

		if (RHS.sz == BITS)
			return (RHS);
		res += LHS;
		for (int i = 0; i < BITS; i++)
		{
			if (RHS.basis[i])
				res.insertVector(RHS.basis[i]);
		}
		return res;
	}

	XORBasis &operator+=(const XORBasis &other)
	{
		if (sz == BITS)
			return *this;

		if (other.sz == BITS)
			return (*this = other);

		for (int i = 0; i < BITS; i++)
		{
			if (other.basis[i])
				insertVector(other.basis[i]);
		}
		return *this;
	}

	void clear()
	{
		if (!sz)
			return;
		basis.fill(0);
		sz = 0;
	}
};

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		ll value;
		XORBasis xB;
		Node() {}
		Node(const ll &N)
		{
			value = N;
			xB.insertVector(N);
		}
		Node operator&(const Node &RHS)
		{
			value = (value & RHS.value);
			return *this;
		}
	};
	int size;
	vector<Node> seg, lazy;
	Node merge(Node leftNode, const Node &rightNode)
	{
		Node res;
		res.xB = (leftNode.xB += rightNode.xB);
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
	void push(int left, int right, int node)
	{
		if (lazy[node].value != -1)
		{
			// Propagate the value
			ll x = lazy[node].value;
			XORBasis &A = seg[node].xB;
			auto B = A.basis; // A copy
			A.clear();
			for (const int &y : B)
				A.insertVector(x & y);
			// If the node is not a leaf
			if (left != right)
			{
				// Update the lazy values for the left child
				lazy[L] = (lazy[L] & lazy[node]);
				// Update the lazy values for the right child
				lazy[R] = (lazy[R] & lazy[node]);
			}
			// Reset the lazy value
			lazy[node] = -1;
		}
	}
	void rangeUpdate(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (leftQuery > rightQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			lazy[node] = (lazy[node] & val);

			// Apply the update immediately
			push(left, right, node);
		}
		else
		{
			// Recursively update the left child
			rangeUpdate(left, mid, L, leftQuery, min(rightQuery, mid), val);
			// Recursively update the right child
			rangeUpdate(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery, val);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}

	void pointUpdate(int left, int right, int node, int idx, const ll &val)
	{
		push(left, right, node);
		if (idx > right || idx < left)
			return;
		if (left == right)
		{
			seg[node].xB.clear();
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
		// Apply the pending updates if any
		push(left, right, node);
		// If the range is invalid, return a value that does NOT to affect other queries
		if (leftQuery > rightQuery || left > rightQuery || right < leftQuery)
			return 0;

		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		Node getLeftQuery = query(left, mid, L, leftQuery, min(rightQuery, mid));
		Node getRightQuery = query(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery);
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
		lazy = vector<Node>(2 * size, -1); // 111111111111
		build(0, size - 1, 0, arr);
	}
	void update(int left, int right, const ll &val, int type, int idx = 0)
	{
		if (type == 1)
			rangeUpdate(0, size - 1, 0, left, right, val);
		else
			pointUpdate(0, size - 1, 0, idx, val);
	}
	ll query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.xB.getMaxXor();
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
	cin >> t;
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
				cin >> L >> R >> x;
				L--, R--;
				segTree.update(L, R, x, 1);
			}
			else if (query == 2)
			{
				cin >> i >> x;
				i--;
				segTree.update(0, 0, x, 2, i);
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

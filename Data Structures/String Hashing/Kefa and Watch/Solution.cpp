#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
std::mt19937 rnd(time(nullptr));
#define rng(l, r) uniform_int_distribution<int64_t>(l, r)(rnd)

constexpr ll mod = 1e9 + 7;
ll mult64(const ll &a, const ll &b)
{
	return __int128_t(a) * b % mod;
}
ll modPow(ll N, ll power, ll mod)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = mult64(res, N);
		N = mult64(N, N);
		power >>= 1;
	}
	return res;
}
ll b1 = rng(1000, 1000000000), b2 = rng(1000, 1000000000);
ll b1I = modPow(b1, mod - 2, mod), b2I = modPow(b2, mod - 2, mod);
vector<ll> Pb1, Pb2, sumB1, sumB2;
void pre(ll maxSize)
{
	Pb1 = Pb2 = sumB1 = sumB2 = vector<ll>(maxSize + 1, 1);
	for (int i = 1; i <= maxSize; i++)
	{
		Pb1[i] = (Pb1[i - 1] * b1 % mod);
		Pb2[i] = (Pb2[i - 1] * b2 % mod);
		sumB1[i] = ((sumB1[i - 1] + Pb1[i]) % mod);
		sumB2[i] = ((sumB2[i - 1] + Pb2[i]) % mod);
	}
}
class Hash
{
	using pll = pair<ll, ll>;
	ll size{};
	ll mul(const ll &x, const ll &y)
	{
		return (x * y % mod);
	}
	ll plus(const ll &x, const ll &y)
	{
		return ((x + y + mod) % mod);
	}

public:
	pll code{};

	explicit Hash(pair<ll, ll> x = {}, ll sz = {}) : code(std::move(x)), size(sz) {}

	Hash(const ll &x) : code({x % mod, x % mod}), size(1) {}

	Hash(const string &x) : code(), size(0)
	{
		for (const char &c : x)
			*this = *(this) + c;
	}

	void pop_front(int x)
	{
		code.first = (code.first - Pb1[--size] * x % mod + mod) % mod;
		code.second = (code.second - Pb2[size] * x % mod + mod) % mod;
	}

	void pop_back(int x)
	{
		code.first = ((code.first - x + mod) * b1I) % mod;
		code.second = ((code.second - x + mod) * b2I) % mod;
		size--;
	}
	void clear()
	{
		code = {}, size = 0;
	}
	Hash operator+(const Hash &o)
	{
		Hash ans;
		ans.code = {plus(mul(code.first, Pb1[o.size]), o.code.first),
					plus(mul(code.second, Pb2[o.size]), o.code.second)};
		ans.size = size + o.size;
		return ans;
	}
	friend Hash operator+(const Hash &f, const Hash &o)
	{
		return Hash({int((f.code.first * Pb1[o.size] + o.code.first) % mod),
					 int((f.code.second * Pb2[o.size] + o.code.second) % mod)},
					f.size + o.size);
	}
	bool operator<(const Hash &o) const
	{
		if (code == o.code)
			return size < o.size;
		return code < o.code;
	}
	bool operator==(const Hash &o) const
	{
		return size == o.size && code == o.code;
	}
	bool operator!=(const Hash &o) const
	{
		return size != o.size || code != o.code;
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
		Hash v;
		ll edit = -1;
		Node() {}
		Node(const ll &N)
		{
			if (N)
				v = v + N;
		}
	};
	int size;
	vector<Node> seg;
	Node merge(Node &leftNode, const Node &rightNode)
	{
		Node res;
		res.v = (leftNode.v + rightNode.v);
		return res;
	}
	void build(int left, int right, int node, const string &str)
	{
		// If the segment has only one element, leaf node
		if (left == right)
		{
			if (left < str.size())
				seg[node] = str[left];
		}
		else
		{
			// Recursively build the left child
			build(left, mid, L, str);
			// Recursively build the right child
			build(mid + 1, right, R, str);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
	}
	void push(int left, int right, int node)
	{
		// Propagate the value
		if (seg[node].edit != -1)
		{
			seg[node].v.code = {sumB1[right - left] * seg[node].edit % mod, sumB2[right - left] * seg[node].edit % mod};
			// If the node is not a leaf
			if (left != right)
			{
				// Update the lazy values for the left child
				seg[L].edit = seg[node].edit;
				// Update the lazy values for the right child
				seg[R].edit = seg[node].edit;
			}
			// Reset the lazy value
			seg[node].edit = -1;
		}
	}
	void update(int left, int right, int node, int leftQuery, int rightQuery, const ll &val)
	{
		push(left, right, node);
		// If the range is invalid, return
		if (leftQuery > rightQuery)
			return;
		// If the range matches the segment
		if (left >= leftQuery && right <= rightQuery)
		{
			// Update the lazy value
			seg[node].edit = val;

			// Apply the update immediately
			push(left, right, node);
		}
		else
		{
			// Recursively update the left child
			update(left, mid, L, leftQuery, min(rightQuery, mid), val);
			// Recursively update the right child
			update(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery, val);
			// Merge the children values
			seg[node] = merge(seg[L], seg[R]);
		}
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
		Node leftSegment = query(left, mid, L, leftQuery, min(rightQuery, mid));
		Node rightSegment = query(mid + 1, right, R, max(leftQuery, mid + 1), rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	segmentTree(const string &str)
	{
		size = 1;
		int n = str.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		build(0, size - 1, 0, str);
	}
	void update(int left, int right, const ll &val)
	{
		update(0, size - 1, 0, left, right, val);
	}
	Hash query(int left, int right)
	{
		Node ans = query(0, size - 1, 0, left, right);
		return ans.v;
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
	ll N, m, k;
	string str;
	// cin >> t;
	while (t--)
	{
		cin >> N >> m >> k >> str;
		pre(N);
		m += k;
		segmentTree segTree(str);
		while (m--)
		{
			ll t, l, r, c;
			cin >> t >> l >> r >> c;
			if (t == 1)
				segTree.update(--l, --r, c + 48);
			else
				cout << (segTree.query(l - 1, r - c - 1) == segTree.query(l + c - 1, r - 1) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}
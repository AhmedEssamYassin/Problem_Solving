#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

auto random_address = []
{ char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
std::mt19937 rnd(SEED);
#define rng(l, r) uniform_int_distribution<int64_t>(l, r)(rnd)
/*
Large Primes for hash
1000000007
10000000019
100000000003
1000000000039
10000000000037
100000000000031
1000000000000037
10000000000000061
2305843009213693951 = (1LL << 61) - 1
*/

constexpr ll mod = (1LL << 61) - 1; // Large prime,
// Takes more time, choose a smaller prime and omit mult64() for faster code but higher probability of collision
// constexpr ll mod = 1e9 + 7; // Is usually sufficient for most of the hashing problems

inline ll mult64(const ll &a, const ll &b)
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
ll b1 = rng(200, 1000), b2 = rng(b1 + 1, 10000);
ll b1I = modPow(b1, mod - 2, mod), b2I = modPow(b2, mod - 2, mod);
vector<ll> Pb1, Pb2, sumB1, sumB2;
void pre(ll maxSize)
{
	Pb1 = Pb2 = sumB1 = sumB2 = vector<ll>(maxSize + 1, 1);
	for (int i = 1; i <= maxSize; i++)
	{
		Pb1[i] = mult64(Pb1[i - 1], b1);
		Pb2[i] = mult64(Pb2[i - 1], b2);
		sumB1[i] = ((sumB1[i - 1] + Pb1[i]) % mod);
		sumB2[i] = ((sumB2[i - 1] + Pb2[i]) % mod);
	}
}
class Hash
{
	using pll = pair<ll, ll>;
	ll size{};
	ll plus(const ll &x, const ll &y)
	{
		return ((__int128_t(x) + y + mod) % mod);
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
		code.first = (code.first - mult64(Pb1[--size], x) + mod) % mod;
		code.second = (code.second - mult64(Pb2[size], x) + mod) % mod;
	}

	void pop_back(int x)
	{
		code.first = mult64((code.first - x + mod), b1I);
		code.second = mult64((code.second - x + mod), b2I);
		size--;
	}
	void clear()
	{
		code = {}, size = 0;
	}
	Hash operator+(const Hash &o)
	{
		Hash ans;
		ans.code = {plus(mult64(code.first, Pb1[o.size]), o.code.first),
					plus(mult64(code.second, Pb2[o.size]), o.code.second)};
		ans.size = size + o.size;
		return ans;
	}
	friend Hash operator+(const Hash &f, const Hash &o)
	{
		return Hash({((mult64(f.code.first, Pb1[o.size]) + o.code.first) % mod),
					 ((mult64(f.code.second, Pb2[o.size]) + o.code.second) % mod)},
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

// Rabin-Karp Algorithm
struct HashRange
{
	vector<Hash> p, s;
	HashRange(const string &t) : p(t.size()), s(t.size())
	{
		if (t.empty())
			return;
		p.front() = t.front();
		for (int i = 1; i < t.size(); i++)
			p[i] = p[i - 1] + t[i];
		s.back() = t.back();
		for (int i = int(t.size()) - 2; i >= 0; i--)
			s[i] = s[i + 1] + t[i];
	}
	Hash get(int l, int r) const // 0-based indices
	{
		if (l > r)
			return Hash();
		if (!l)
			return p[r];
		return Hash({(p[r].code.first - mult64(p[l - 1].code.first, Pb1[r - l + 1]) + mod) % mod,
					 (p[r].code.second - mult64(p[l - 1].code.second, Pb2[r - l + 1]) + mod) % mod},
					r - l + 1);
	}
	Hash inv(int l, int r) const // 0-based indices
	{
		if (l > r)
			return Hash();
		if (r + 1 == s.size())
			return s[l];
		return Hash({(s[l].code.first - mult64(s[r + 1].code.first, Pb1[r - l + 1]) + mod) % mod,
					 (s[l].code.second - mult64(s[r + 1].code.second, Pb2[r - l + 1]) + mod) % mod},
					r - l + 1);
	}
	void concatenate(const string &t)
	{
		if (t.empty())
			return;
		bool chk = false;
		if (chk = p.empty())
			p.push_back(t[0]);
		for (int i = 0 + chk; i < t.size(); i++)
			p.push_back(p.back() + t[i]);
	}
	void pop_back()
	{
		if (!p.empty())
			p.pop_back();
	}
};
////////////////////////////////////////////////////////////////////////////////////

struct segmentTree
{
#define L (2 * node + 1)
#define R (2 * node + 2)
#define mid ((left + right) >> 1)
private:
	struct Node
	{
		Hash forwardHash;
		Hash backwardHash;
		// Constructors
		Node() {}
		Node(const ll &val) : forwardHash(val), backwardHash(val) {}
	};
	int size;
	vector<Node> seg;
	Node merge(Node &leftNode, Node &rightNode)
	{
		Node res;
		res.forwardHash = (leftNode.forwardHash + rightNode.forwardHash);
		res.backwardHash = (rightNode.backwardHash + leftNode.backwardHash);
		return res;
	}
	void build(int left, int right, int node, const string &arr)
	{
		if (left == right) // Leaf Node (single element)
		{
			if (left < arr.size()) // Making sure we are inside the boundaries of the array
				seg[node] = arr[left] - 'a';
			return;
		}
		// Building left node
		build(left, mid, L, arr);

		// Building right node
		build(mid + 1, right, R, arr);

		// Returning to parent nodes
		seg[node] = merge(seg[L], seg[R]);
	}
	void update(int left, int right, int node, int idx, const ll &val)
	{
		if (left == right)
		{
			seg[node] = val - 'a';
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
			return Node(); // A value that doesn't affect the query

		// The whole range is the answer
		if (left >= leftQuery && right <= rightQuery)
			return seg[node];

		// ONLY a part of this segment belongs to the query
		Node leftSegment = query(left, mid, L, leftQuery, rightQuery);
		Node rightSegment = query(mid + 1, right, R, leftQuery, rightQuery);
		return merge(leftSegment, rightSegment);
	}

public:
	segmentTree(const string &arr)
	{
		size = 1;
		int n = arr.size();
		while (size < n)
			size <<= 1;
		seg = vector<Node>(2 * size, 0);
		build(0, size - 1, 0, arr);
	}
	void update(int idx, const ll &val)
	{
		update(0, size - 1, 0, idx, val);
	}
	Node query(int left, int right)
	{
		return query(0, size - 1, 0, left, right);
	}

#undef L
#undef R
#undef mid
};

bool canBePalindrome(segmentTree &segTree, int st, int end)
{
	if (segTree.query(st, end).forwardHash == segTree.query(st, end).backwardHash) // Already a palindrome
		return true;

	if (segTree.query(st + 1, end - 1).forwardHash == segTree.query(st + 1, end - 1).backwardHash) // If mis-match is on first character
		return true;

	int len = end - st + 1;
	int i = st, j = i + len / 2 - 1, k = end, l = end - len / 2 + 1;
	int L = 0, R = min(j - i, k - l);
	int idx = -1;
	while (L <= R)
	{
		int mid = ((L + R) >> 1);
		if (segTree.query(i + L, i + mid).forwardHash == segTree.query(k - mid, k - L).backwardHash)
			L = mid + 1;
		else
			idx = mid, R = mid - 1;
	}

	// (impossible case because we only check if it's not a palindrome, so there must be a mis-match)
	if (idx == -1) // If there is NO any mis-match
		return true;
	return (segTree.query(i + idx + 1, j).forwardHash == segTree.query(l, k - idx - 1).backwardHash);
}

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
	cin >> t;
	pre(1e6);
	while (t--)
	{
		cin >> N;
		string str;
		cin >> str;
		segmentTree segTree(str);
		cin >> Q;
		while (Q--)
		{
			ll query, i, L, R;
			char c;
			cin >> query;
			if (query == 1)
			{
				cin >> i >> c;
				i--;
				segTree.update(i, c);
			}
			else
			{
				cin >> L >> R;
				L--, R--;
				if (canBePalindrome(segTree, L, R))
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}
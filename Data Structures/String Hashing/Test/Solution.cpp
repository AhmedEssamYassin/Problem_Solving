#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
std::mt19937 rnd(time(nullptr));
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
ll b1 = rng(100, 1000), b2 = rng(100, 1000);
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
};
////////////////////////////////////////////////////////////////////////////////////

ll tryPermutation(string S[], ll ans)
{
	HashRange hashS[3] = {S[0], S[1], S[2]};
	int L = 0, R = S[0].length() - 1, cnt{}, len = S[0].length() + S[1].length();
	while (L < S[1].length() && R >= 0)
	{
		if (hashS[0].get(R, S[0].length() - 1) == hashS[1].get(0, L))
			cnt = L + 1;
		L++, R--;
	}
	ans -= cnt;
	len -= cnt;
	HashRange overLapHash(S[0].substr(0, S[0].length() - cnt) + S[1]);
	/////////////////////////////////////////////////////////////////////////////////
	L = 0, R = len - 1, cnt = 0;
	while (L < S[2].length() && R >= 0)
	{
		if (overLapHash.get(R, len - 1) == hashS[2].get(0, L))
			cnt = L + 1;
		L++, R--;
	}
	ans -= cnt;
	return ans;
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
	// cin >> t;
	while (t--)
	{
		string S[3];
		cin >> S[0] >> S[1] >> S[2];
		pre(1e5);

		// S1 S2 S3
		// S1 S3 S2
		// S2 S1 S3
		// S2 S3 S1
		// S3 S1 S2
		// S3 S2 S1
		// Try all permutations and choose the minimum answer
		// If a string is totally contained in another one, just delete it
		if (S[0].find(S[1]) != -1)
			S[1] = "";
		if (S[0].find(S[2]) != -1)
			S[2] = "";
		if (S[1].find(S[0]) != -1)
			S[0] = "";
		if (S[1].find(S[2]) != -1)
			S[2] = "";
		if (S[2].find(S[0]) != -1)
			S[0] = "";
		if (S[2].find(S[1]) != -1)
			S[1] = "";
		ll ans = S[0].length() + S[1].length() + S[2].length();
		ll originalAns = ans;
		sort(S, S + 3); // To get All permutations
		do
			ans = min(tryPermutation(S, originalAns), ans);
		while (next_permutation(S, S + 3));

		cout << ans;
	}
	return 0;
}
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
For all coming primes use __int128_t in mult64()
10000000019
100000000003
1000000000039
10000000000037
100000000000031
1000000000000037
10000000000000061
2305843009213693951 = (1LL << 61) - 1
*/

// constexpr ll mod = (1LL << 61) - 1; // Large prime,
// Takes more time, choose a smaller prime and omit mult64() for faster code but higher probability of collision
constexpr ll mod = 1e9 + 7; // Is usually sufficient for most of the hashing problems

inline ll mult64(const ll &a, const ll &b)
{
	return (a)*b % mod; // Cast to __int128_t if mod > 1e9
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
ll b1 = rng(100, 1000000000), b2 = rng(1000, 1000000000);
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
		for (int i = 0; i < t.size(); i++)
			p.push_back(p.back() + t[i]);
	}
};
////////////////////////////////////////////////////////////////////////////////////

// Function to check if we can have K divisions with LCP = x
// abadzababad fails the previous solution, we shouldn't skip the whole wrong segment
// We just skip the valid LCP, but skip ONLY the start of an invalid LCP

ll memo[200005];
inline ll calc(const HashRange &hash, const string &str, int x)
{
	if (x == 0)
		return 1e9; // Any number >= K that validates the case

	int N = str.length(), cnt{0};
	for (int i = 0; i < N - x + 1; i++)
	{
		if (hash.get(i, i + x - 1) == hash.get(0, x - 1))
			i += (x - 1), cnt++;
	}
	return cnt;
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
	ll N, L, R;
	string str;
	pre(2e5);
	cin >> t;
	while (t--)
	{
		cin >> N >> L >> R >> str;
		memset(memo, -1, (N + 5) * 8);
		HashRange hash = str;

		for (int K = L; K <= R; K++)
		{
			ll L{1}, R = N, ans{};
			while (L <= R)
			{
				ll mid = ((L + R) >> 1);
				ll cnt{};
				if (~memo[mid]) // If this value is already calculated
					cnt = memo[mid];
				else // If not, calculate it and memoize it
					cnt = memo[mid] = calc(hash, str, mid);

				if (cnt >= K)
				{
					ans = mid;
					L = mid + 1;
				}
				else
					R = mid - 1;
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
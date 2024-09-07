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

struct HashRange
{
    vector<Hash> p, s;
    HashRange(const string &t) : p(t.size()), s(t.size())
    {
        p.front() = t.front();
        for (int i = 1; i < t.size(); i++)
            p[i] = p[i - 1] + t[i];
        s.back() = t.back();
        for (int i = int(t.size()) - 2; i >= 0; i--)
            s[i] = s[i + 1] + t[i];
    }
    Hash get(int l, int r) // 0-based indices
    {
        if (l > r)
            return Hash();
        if (!l)
            return p[r];
        return Hash({(p[r].code.first - p[l - 1].code.first * Pb1[r - l + 1] % mod + mod) % mod,
                     (p[r].code.second - p[l - 1].code.second * Pb2[r - l + 1] % mod + mod) % mod},
                    r - l + 1);
    }
    Hash inv(int l, int r) // 0-based indices
    {
        if (l > r)
            return Hash();
        if (r + 1 == s.size())
            return s[l];
        return Hash({(s[l].code.first - s[r + 1].code.first * Pb1[r - l + 1] % mod + mod) % mod,
                     (s[l].code.second - s[r + 1].code.second * Pb2[r - l + 1] % mod + mod) % mod},
                    r - l + 1);
    }
};
////////////////////////////////////////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N;
    // cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        pre(4e5);
        HashRange HashString(str);
        bool flag = false;
        string ans;
        for (int i = str.length() - 2, len = 2; i > 0; i--, len++)
        {
            Hash pref = HashString.get(0, len - 1);
            Hash suf = HashString.get(i, str.length() - 1);
            if (pref == suf && len + len > str.length())
            {
                ans = str.substr(0, len);
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "YES\n"
                 << ans;
        else
            cout << "NO";
    }
    return 0;
}

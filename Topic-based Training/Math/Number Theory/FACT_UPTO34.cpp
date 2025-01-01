// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define u128 __uint128_t
#define endl "\n"

namespace bigNumber
{
    using u128 = __uint128_t;

    u128 mult128(u128 a, u128 b, u128 mod)
    {
        u128 result = 0;
        for (a %= mod; b > 0; a <<= 1, b >>= 1)
        {
            a >= mod ? a -= mod : 0;
            if (b & 1)
            {
                result += a, result >= mod ? result -= mod : 0;
            }
        }
        return result;
    }

    static u128 mult(u128 x, u128 y, u128 &high)
    {
        const size_t shift = sizeof(x) * 4;
        u128 a = x >> shift, b = (x << shift) >> shift;
        u128 c = y >> shift, d = (y << shift) >> shift;
        u128 ac = a * c;
        u128 ad = a * d;
        u128 bc = b * c;
        u128 bd = b * d;
        u128 carry = ((ad << shift) >> shift) + ((bc << shift) >> shift) + (bd >> shift);
        high = ac + (ad >> shift) + (bc >> shift) + (carry >> shift);
        return (ad << shift) + (bc << shift) + bd;
    }
    u128 montMult(u128 a, u128 b, u128 N, u128 N_neg_inv)
    {
        u128 Th, Tl, m, mNh, mNl;

        Tl = mult(a, b, Th);

        m = Tl * N_neg_inv;

        mNl = mult(m, N, mNh);

        bool lc = Tl + mNl < Tl;
        u128 th = Th + mNh + lc;
        bool hc = (th < Th) || (th == Th && lc);

        if (hc > 0 || th >= N)
            th = th - N;

        return th;
    }

    inline pair<u128, u128> montModInv(u128 m)
    {
        const size_t shift = sizeof(m) * 8 - 1;
        u128 a = u128(1) << shift;
        u128 u = 1;
        u128 v = 0;

        while (a)
        {
            a >>= 1;
            if (u & 1)
            {
                u = ((u ^ m) >> 1) + (u & m);
                v = (v >> 1) + (u128(1) << shift);
            }
            else
            {
                u >>= 1;
                v >>= 1;
            }
        }

        return {u, v};
    }
}
using namespace bigNumber;

int bigMod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + num[i] - '0') % a;

    return res;
}

template <typename T>
T modInv(T N, T mod)
{
    return N <= 1 ? N : mod - (mod / N) * modInv(mod % N) % mod;
}

template <typename T>
inline T F(T x, T c, T mod, T inv) // Pollard-rho function
{
    x = montMult(x, x, mod, inv);
    x = x >= mod - c ? x - mod + c : x + c;
    return x;
}

template <typename T>
inline T __abs(T N)
{
    if (N < 0)
        return -N;

    return N;
}

template <typename T>
T Pollard_Brent(T N)
{
    if (!(N & 1))
        return 2;

    // Random Number Linear Congruential Generator MMIX from D.E. Knuth
    static u128 rng = 0xdeafbeefff;
    uint64_t a = rng * 6364136223846793005ull + 1442695040888963407ull;
    uint64_t b = a * 6364136223846793005ull + 1442695040888963407ull;
    rng = (a + b) ^ (a * b);

    T X0 = 1 + a % (N - 1);
    T C = 1 + b % (N - 1);
    T X = X0; // X1
    T gcd_val = 1;
    T q = 1;
    T Xs, Xt;
    T m = 128;
    u128 inv = montModInv(N).second;
    T L = 1;
    while (gcd_val == 1)
    {
        Xt = X;
        for (size_t i = 1; i < L; i++)
            X = F(X, C, N, inv);

        int k = 0;
        while (k < L && gcd_val == 1)
        {
            Xs = X;
            for (size_t i = 0; i < m && i < L - k; i++)
            {
                X = F(X, C, N, inv);
                q = montMult(q, Xt > X ? Xt - X : X - Xt, N, inv);
            }
            gcd_val = __gcd(q, N);
            k += m;
        }
        L += L;
    }
    if (gcd_val == N) // Failure
    {
        do
        {
            Xs = F(Xs, C, N, inv);
            gcd_val = __gcd(Xs > Xt ? Xs - Xt : Xt - Xs, N);
        } while (gcd_val == 1);
    }
    return gcd_val;
}

template <typename T>
T modPow(T N, T power, T mod) //(N^power) % mod
{
    if (N % mod == 0 || N == 0)
        return 0;
    if (N == 1 || power == 0)
        return 1;

    if (N >= mod)
        N -= mod;

    T res{1};
    while (power)
    {
        if (power & 1) // ODD
            res = mult128(res, N, mod);

        N = mult128(N, N, mod);
        power >>= 1;
    }
    return res;
}

template <typename T>
bool Check_Composite(T N, T a, T d, int s)
{
    T X = modPow(a, d, N);
    if (X == 1 || X == N - 1)
        return false; // Not composite

    for (int r = 1; r < s; r++)
    {
        X = mult128(X, X, N);
        if (X == 1 || X == N - 1)
            return false; // Not composite
    }
    return true; // Composite
}

template <typename T>
bool Miller_Rabin(T N, int K = 5) // k is the number of trials (bases). If k increases the accuracy increases
{
    T d = N - 1;
    int s{};
    while (~s & 1)
        d >>= 1, ++s;

    for (const T &a : {11, 13, 17})
    {
        if (N == a)
            return true;
        if (Check_Composite(N, a, d, s))
            return false;
    }
    return true;
}

template <typename T>
bool Is_Prime(T N)
{
    if (N < 2)
        return false;

    if (N <= 3)
        return true;
    if (N == 5 || N == 7)
        return true;

    if (!(N & 1) || N % 3 == 0 || N % 5 == 0 || N % 7 == 0)
        return false;

    return Miller_Rabin(N);
}

template <typename T>
void Factor(T N, vector<T> &Prime_factors)
{
    if (N == 1)
        return;

    if (!Is_Prime(N))
    {
        T Y = Pollard_Brent(N);
        Factor(Y, Prime_factors);
        Factor(N / Y, Prime_factors);
    }
    else
    {
        Prime_factors.push_back(N);
        return;
    }
}

template <typename T>
void primeFactorize(T N, vector<T> &Prime_factors) // Use a vector if generating ALL factors
{
    Factor(N, Prime_factors);
    sort(Prime_factors.begin(), Prime_factors.end());
}

template <typename T>
T countDivisors(T N)
{
    vector<T> Prime_factors;
    primeFactorize(N, Prime_factors);
    T cnt{1}, ans{1};
    int len = Prime_factors.size();
    for (int i{1}; i < len; i++)
    {
        // 2 2 3
        if (Prime_factors[i] != Prime_factors[i - 1])
        {
            ans *= (cnt + 1);
            cnt = 1;
        }
        else
            cnt++;
    }
    if (len > 0)
        ans *= (cnt + 1);
    return ans;
}

template <typename T>
vector<T> ALL_factors(T N)
{
    // To get ALL factors from prime factorization, we must multiply each prime factor by all preceding factors
    // Pay attention to duplicates! factors must be distinct
    // 1 2 2 3
    // 1 2
    // 2 4
    // 3 6 12
    // 1 2 3 4 6 12
    vector<T> primeFactors;
    primeFactorize(N, primeFactors);
    vector<T> allDivisors = {1};
    for (const T &p : primeFactors)
    {
        int len = allDivisors.size();
        for (int i{}; i < len; i++)
            allDivisors.push_back(p * allDivisors[i]);

        set<T> distinctDivisors(allDivisors.begin(), allDivisors.end());
        allDivisors.clear();
        for (const T &it : distinctDivisors)
            allDivisors.push_back(it);
    }
    return allDivisors;
}
/////////////////////////////////////////////////////////////////////////
// σ function (Sum of divisors)
template <typename T>
u128 sumDivisors(T N)
{
    if (N == 1)
        return 1;
    T sigma{1};
    map<T, int> primeFactors = primeFactorize(N); // See the function parameters
    for (auto &P : primeFactors)
        sigma *= (powl(P.first, P.second + 1) - 1) / (P.first - 1);
    return sigma;
}
/////////////////////////////////////////////////////////////////////////
// Euler Totient Function
template <typename T>
T Phi(T N)
{
    if (Is_Prime(N))
        return (N - 1);
    map<T, int> pf = primeFactorize(N);
    long double ans = N;
    for (auto &p : pf)
        ans = (ans / p.first) * (p.first - 1);
    return ans;
}

const int N = 10000007;
int lp[N + 1];
int phi[N + 1];
vector<int> pr;

void precompute_Phi()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            // Calculating phi
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}
/////////////////////////////////////////////////////////////////////////
// Inverse Euler Totient Function
vector<int> divP;
template <typename T>
T solve(T phi, T Num, T pos)
{
    if (phi == 1)
        return Num;
    else if (pos == divP.size())
        return 20000000001LL;
    else
    {
        T P = divP[pos];
        T res = solve(phi, Num, pos + 1);
        if (phi % (P - 1) == 0)
        {
            T remPhi = phi / (P - 1);
            T curNum = Num * P;
            res = min(res, solve(remPhi, curNum, pos + 1));
            while (remPhi % P == 0)
            {
                remPhi /= P, curNum *= P;
                res = min(res, solve(remPhi, curNum, pos + 1));
            }
        }
        return res;
    }
}
template <typename T>
void findMinInvPhi(T phi)
{
    divP.clear();
    vector<T> allFactors = ALL_factors(phi);
    for (T &factor : allFactors)
    {
        if (Is_Prime(factor + 1))
            divP.push_back(factor + 1);
    }
    T minPhi = solve(phi, T(1), T(1));
    if (minPhi == 20000000001LL)
        cout << -1 << endl;
    else
        cout << minPhi << endl;
}
/////////////////////////////////////////////////////////////////////////
// GCC's implementation for I/O of 128-bit integers
template <class integer>
inline integer to_int(const string &s, size_t *idx = 0, int base = 10)
{
    size_t n = s.size(), i = idx ? *idx : 0;
    bool sign = false;
    integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c)
    {
		static const int d[] = {'a'-10,'0'}; 
		return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i;
    return sign ? -x : x;
}

template <class integer>
inline string to_string(integer x, int base = 10)
{
    bool sign = false;
    string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d)
    {
		static const char c[] = {'a'-10,'0'};
		return c[d < 10]+d; };
    do
        s += digit_to_char(x % base), x /= base;
    while (x > 0);
    if (sign)
        s += '-';
    reverse(s.begin(), s.end());
    return s;
}

template <class integer>
inline istream &read_128(istream &is, integer &x)
{
    string s;
    is >> s, x = to_int<integer>(s);
    return is;
}

template <class integer>
inline ostream &print_128(ostream &os, integer x) { return os << to_string(x); }

inline istream &operator>>(istream &is, u128 &x) { return read_128(is, x); }
inline ostream &operator<<(ostream &os, u128 x) { return print_128(os, x); }
/////////////////////////////////////////////////////////////////////////
bool isPerm(int X, int Y)
{
    int digitsX[10] = {0};
    int digitsY[10] = {0};
    while (X)
        digitsX[X % 10]++, X /= 10;

    while (Y)
        digitsY[Y % 10]++, Y /= 10;

    for (int i{}; i < 10; i++)
    {
        if (digitsX[i] != digitsY[i])
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    /*int t = 1;
    i128 N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        cout << countDivisors(N) << endl;
    }*/
    /*i128 N;
    cin >> N;
    while (N)
    {
        map<i128, int> Prime_factors = primeFactorize(N);
        for (const auto &P : Prime_factors)
            cout << P.first << '^' << P.second << ' ';

        cout << endl;
        cin >> N;
    }*/
    /*
    precompute_Phi();
    ll *res = new ll[10000001];
    // ll *cum = new ll[10000001];

    //Computing Σ gcd(i, N)
    for (int i = 1; i < 10000001; i++)
    {
        for (int j = i; j < 10000001; j += i)
        {
            res[j] = res[j] + 1LL * i * phi[j/i]; // phi[i] if computing Σ (N / gcd(i, N))
        }
    }

    // Computing Σ Σ gcd(i ,N)
    // for (int i = 1; i < 10000001; i++)
    // res[i] -= i;

    // cum[0] = 0;
    // for (int i = 1; i < 10000001; i++)
    // cum[i] = cum[i - 1] + res[i];
    */

    /*precompute_Phi();
    int *dp{new int[2000'007]{0}};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i{3}; i < 2000'007; i++)
        dp[i] += dp[phi[i]] + 1;

    for (int i{1}; i < 2000'007; i++)
        dp[i] += dp[i - 1];

    int t = 1, L, R;
    cin >> t;
    while (t--)
    {
        cin >> L >> R;
        cout << dp[R] - dp[L - 1] << endl;
    }*/
    /*precompute_Phi();
    int arr[1000'07] = {0};
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    for (int i{4}; i < 1000'07; i++)
        arr[i] = arr[i - 1] + i - phi[i];
    int t, N;
    cin >> t;
    for (int i{1}; i <= t; i++)
    {
        cin >> N;
        cout << "Case " << i << ": " << arr[N] << endl;
    }*/

    /*
    precompute_Phi();
    int firstNum = 21, firstPerm = 12;
    arr[21] = 21;
    for (int i{22}; i < 1000'000'7; i++)
    {
        if (isPerm(i, phi[i]))
        {
            if (1LL * i * firstPerm <= 1LL * phi[i] * firstNum)
            {
                firstNum = i;
                firstPerm = phi[i];
            }
        }
        arr[i] = firstNum;
    }
    int t, N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        if (--N < 21)
            cout << "No solution.\n"; // Be careful with the dot
        else
            cout << arr[N] << endl;
    }
    */
    /*int t = 1;
    ll N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        findMinInvPhi(N);
    }*/
    int t = 1;
    ll N;
    // cin >> t;
    while (t--)
    {
        cin >> N;
        cout << sumDivisors(N);
    }
    return 0;
}
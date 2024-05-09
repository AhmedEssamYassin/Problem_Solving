#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define i128 __int128_t
#define endl "\n"

template <typename T>
T mult64(T a, T b, T mod)
{
    return (__int128_t)a * b % mod;
}

template <typename T>
T mult128(T a, T b, T mod)
{
    int largestBit = 127 - __countl_zero(b); // Position of MSB
    // int largestBit{};
    // while ((b >> largestBit))
    //   largestBit++;

    T result = 0;
    for (int currentBit = largestBit - 1; currentBit >= 0; currentBit--)
    {
        result = (result + result); // result *= 2;

        if (result >= mod)
            result -= mod; // result %= mod;

        // check whether current bit is set in b
        if ((b >> currentBit) & 1)
        {
            result += a;
            if (result >= mod)
                result -= mod; // result %= mod;
        }
    }
    return result;
}

template <typename T>
inline T F(T x, T c, T mod) // Pollard-rho function
{
    return (mult128(x, x, mod) + c) % mod;
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
    static T rng = 0xdeafbeefff;
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
    T L = 1;
    while (gcd_val == 1)
    {
        Xt = X;
        for (size_t i = 1; i < L; i++)
            X = F(X, C, N);

        int k = 0;
        while (k < L && gcd_val == 1)
        {
            Xs = X;
            for (size_t i = 0; i < m && i < L - k; i++)
            {
                X = F(X, C, N);
                q = mult128(q, __abs(Xt - X), N);
            }
            gcd_val = __gcd(q, N);
            k += m;
        }
        L *= 2;
    }
    if (gcd_val == N) // Failure
    {
        do
        {
            Xs = F(Xs, C, N);
            gcd_val = __gcd(__abs(Xs - Xt), N);
        } while (gcd_val == 1);
    }
    return gcd_val;
}

template <typename T>
T Mod_Bin_Exp(T N, T power, T mod) //(N^power) % mod
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
    T X = Mod_Bin_Exp(a, d, N);
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
    while (!(d & 1))
        d >>= 1, ++s;

    for (const T &a : {11, 13, 17, 19, 23, 29, 31, 37, 73})
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
void Factor(T N, map<T, int> &Prime_factors)
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
        Prime_factors[N]++; // Use push_back() if using a vector
        return;
    }
}

template <typename T>
map<T, int> Prime_factorize(T N)
{
    map<T, int> Prime_factors; // Use a vector if generating ALL factors
    Factor(N, Prime_factors);
    return Prime_factors;
}

template <typename T>
T countDivisors(T N)
{
    map<T, int> Prime_factors = Prime_factorize(N);
    T cnt{1};
    for (const auto &P : Prime_factors)
        cnt *= (P.second + 1);
    return cnt;
}

template <typename T>
vector<T> ALL_factors(T N)
{
    // Change the return type of Prime_factorize
    vector<T> primeFactors = Prime_factorize(N);
    vector<T> All_factors = {1};
    // To get ALL factors from prime factorization, we must multiply each prime factor by all preceding factors
    // Pay attention to duplicates! factors must be distinct
    // 1 2 2 3
    // 1 2
    // 2 4
    // 3 6 12
    for (size_t i = 0; i < primeFactors.size(); i++)
    {
        ll currentSize = All_factors.size();
        for (size_t j = 0; j < currentSize; j++)
        {
            All_factors.push_back(All_factors[j] * primeFactors[i]);
        }
        set<T> st;
        for (auto v : All_factors)
            st.insert(v);

        All_factors.clear();
        for (auto v : st)
            All_factors.push_back(v);
    }
    return All_factors;
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

inline istream &operator>>(istream &is, i128 &x) { return read_128(is, x); }
inline ostream &operator<<(ostream &os, i128 x) { return print_128(os, x); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    i128 N;
    cin >> t;
    while (t--)
    {
        cin >> N;
        cout << countDivisors(N) << endl;
    }
    return 0;
}
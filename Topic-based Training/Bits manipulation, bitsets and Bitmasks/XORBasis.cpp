#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct XORBasis
{
    int sz = 0;
    array<ll, 64> basis{};

    void insertVector(ll x)
    {
        if (sz == 64)
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
        if (sz == 64)
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
        ll maxXor = 0;
        for (int i = 63; i >= 0; i--)
        {
            if ((maxXor ^ basis[i]) > maxXor)
                maxXor ^= basis[i];
        }
        return maxXor;
    }
    XORBasis &operator+=(const XORBasis &other)
    {
        if (sz == 64)
            return *this;
        if (other.sz == 64)
        {
            return (*this = other);
        }
        for (int i = 0; i < 64; i++)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
    int t = 1;
    ll N, Q;
    cin >> t;
    XORBasis xb;
    while (t--)
    {
        cin >> N;
        xb.insertVector(N);
    }
    cout << xb.getMaxXor();
    return 0;
}
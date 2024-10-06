#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const int BITS = 64;
struct XORBasis
{
    int sz = 0;
    array<ll, BITS> basis{}; // Better to avoid SHALLOW COPYING

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
    XORBasis xb;
    while (t--)
    {
        cin >> N;
        xb.insertVector(N);
    }
    cout << xb.getMaxXor();
    return 0;
}
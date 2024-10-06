#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

const int BITS = 20;
struct XORBasis
{
	int sz = 0;
	int basis[BITS]{};
	XORBasis() {}
	XORBasis(const ll &x)
	{
		insertVector(x);
	}
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
		memset(basis, 0, sizeof(basis));
		sz = 0;
	}
};

const int mod = 1e9 + 7;
ll modPow(ll N, ll power)
{
	ll res{1};
	while (power)
	{
		if (power & 1)
			res = (res % mod * N % mod) % mod;
		N = (N % mod * N % mod) % mod;
		power >>= 1;
	}
	return res;
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
		cin >> N >> Q;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		vector<XORBasis> acc(N);
		acc[0] = vc[0];
		for (int i = 1; i < N; i++)
			acc[i] = acc[i - 1] + vc[i];

		ll ans{}, l, x;
		while (Q--)
		{
			ans = 0;
			cin >> l >> x;
			if (acc[l - 1].canRepresent(x))
				ans = (modPow(2, l - acc[l - 1].sz));
			cout << ans << endl;
		}
	}
	return 0;
}
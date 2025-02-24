#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll bitCeil(const ll &N)
{
	ll res{1};
	while (res < N)
		res <<= 1;
	return res;
}

struct sparseTable
{
	int size, LOG;
	vector<vector<ll>> m;
	ll (*Process)(ll, ll);
	ll merge(const ll &a, const ll &b)
	{
		return Process(a, b);
	}
	void build(const vector<ll> &arr)
	{
		int N = arr.size();
		for (int i{}; i < N; i++)
			m[i][0] = arr[i];
		for (int k = 1; k < LOG; k++)
		{
			for (int i{}; i + (1 << k) - 1 < N; i++)
				m[i][k] = merge(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
		}
	}
	sparseTable(const vector<ll> &arr, ll (*func)(ll, ll))
	{
		int n = arr.size();
		LOG = (ll)(log2l(bitCeil(n)) + 1) + 1;
		Process = func;
		m.resize(n, vector<ll>(LOG, 0));
		build(arr);
	}

	ll query(int L, int R) // 0-based
	{
		int len = R - L + 1;
		int k = 31 - __builtin_clz(len);
		return merge(m[L][k], m[R - (1 << k) + 1][k]);
	}
};

ll GCD(ll a, ll b)
{
	return std::gcd(a, b);
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];

		sparseTable SPT(vc, GCD);
		int minLen = 0x7fffffff, L{}, R{};
		ll g{};
		while (R < N)
		{
			g = gcd(g, vc[R]); // Expand
			if (g == 1)
				minLen = min(minLen, R - L + 1);

			while (g == 1 && L < R) // Shrink
			{
				minLen = min(minLen, R - L + 1);
				L++;
				g = SPT.query(L, R);
			}
			if (g == 1)
				minLen = min(minLen, R - L + 1);
			R++;
		}
		if (minLen != INT_MAX)
			cout << minLen;
		else
			cout << -1;
	}
	return 0;
}
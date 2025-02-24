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

ll AND(ll a, ll b)
{
	return a & b;
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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<ll> arr(N, 0);
		vector<tuple<int, int, int>> queries(M);
		for (auto &[l, r, q] : queries)
		{
			cin >> l >> r >> q;
			l--, r--;
		}

		for (int k = 0; k < 31; k++)
		{
			vector<ll> range(N + 1, 0);
			for (const auto &[l, r, q] : queries)
			{
				if (q & (1LL << k))
					range[l]++, range[r + 1]--;
			}
			for (int i{}; i < N; i++)
			{
				if (i)
					range[i] += range[i - 1];
				if (range[i] > 0)
					arr[i] |= (1LL << k);
			}
		}
		sparseTable ST(arr, AND);
		for (auto &[l, r, q] : queries)
			if (ST.query(l, r) != q)
				return cout << "NO", 0;
		cout << "YES\n";
		for (ll &x : arr)
			cout << x << " ";
	}
	return 0;
}
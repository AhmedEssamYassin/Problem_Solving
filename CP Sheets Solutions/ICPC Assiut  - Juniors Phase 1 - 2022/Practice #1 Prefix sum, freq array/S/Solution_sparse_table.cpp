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

// Can be used for GCD, LCM, Maximum, Minimum, OR, AND queries, this code is for Range Minimum Query AKA RMQ
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

ll Min(ll a, ll b)
{
	return std::min(a, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	freopen("mex.in", "r", stdin);
	int t = 1;
	ll N, Q;
	cin >> t;
	while (t--)
	{
		/*
		Since the given array is guaranteed to be a permutation, i.e. it includes all numbers [1, N]
		The MEX in any range is obviously the minimum of the remaining of the array
		Example:
		2 6 1 5 3 4
		The MEX in range L = 2, R = 4 --> 2
		The MEX in range L = 4, R = 6 --> 1
		The MEX in range L = 1, R = 6 --> 7 (Special Case)
		*/
		cin >> N;
		cin >> Q;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];

		sparseTable ST(a, Min);
		while (Q--)
		{
			ll L, R;
			cin >> L >> R;
			if (R - L + 1 == N)
			{
				cout << N + 1 << endl;
				continue;
			}
			L--, R--;
			int leftQ = (L > 0 ? ST.query(0, L - 1) : INT_MAX);
			int rightQ = (R + 1 < N ? ST.query(R + 1, N - 1) : INT_MAX);
			int val = min(leftQ, rightQ);
			cout << (val ? val : 1) << endl;
		}
	}
	return 0;
}

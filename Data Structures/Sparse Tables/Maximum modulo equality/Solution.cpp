#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// Can be used for GCD, LCM, Maximum, Minimum, OR, AND queries, this code is for Range Minimum Query AKA RMQ
struct sparseTable
{
	int size, LOG;
	vector<vector<ll>> m;

	sparseTable() {}
	sparseTable(const vector<ll> &arr, int lg)
	{
		build(arr, lg);
	}

	ll merge(const ll &a, const ll &b)
	{
		return gcd(a, b);
	}
	void build(const vector<ll> &arr, int lg)
	{
		int n = arr.size();
		LOG = lg;
		m.resize(n, vector<ll>(LOG, 0));
		int N = arr.size();
		for (int i{}; i < N; i++)
			m[i][0] = arr[i];
		for (int k = 1; k < LOG; k++)
		{
			for (int i{}; i + (1 << k) - 1 < N; i++)
				m[i][k] = merge(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
		}
	}

	ll query(int L, int R) // 0-based
	{
		if (L > R)
			return 0;
		int len = R - L + 1;
		int k = 31 - __builtin_clz(len);
		return merge(m[L][k], m[R - (1 << k) + 1][k]);
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
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> vc(N), diff;
		for (int i{}; i < N; i++)
			cin >> vc[i];
		for (int i{1}; i < N; i++)
			diff.push_back(abs(vc[i] - vc[i - 1]));
		sparseTable SPT(diff, 20);
		while (Q--)
		{
			int L, R;
			cin >> L >> R;
			--L, --R;
			cout << SPT.query(L, R - 1) << " ";
		}
		cout << endl;
	}
	return 0;
}
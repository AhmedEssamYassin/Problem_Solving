#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct sparseTable
{
	int size, LOG;
	vector<vector<ll>> m;

	ll merge(const ll &a, const ll &b)
	{
		return gcd(a, b);
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
	sparseTable(const vector<ll> &arr, int lg)
	{
		int n = arr.size();
		LOG = lg;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, L, R;
	cin >> N;
	vector<ll> S(N);
	map<ll, vector<int>> idx;
	for (int i{}; i < N; i++)
		cin >> S[i], idx[S[i]].push_back(i + 1); // Map elements to their indices (1-based)

	sparseTable ST(S, 20);
	cin >> t;
	while (t--)
	{
		cin >> L >> R;
		ll GCD = ST.query(L - 1, R - 1); // Because Sparse Table is 0-based
		auto &vec = idx[GCD];
		ll endPos = upper_bound(vec.begin(), vec.end(), R) - vec.begin();
		ll startPos = lower_bound(vec.begin(), vec.end(), L) - vec.begin() + 1;
		ll cnt = endPos - startPos + 1;
		cout << (R - L + 1) - cnt << endl;
	}
	return 0;
}
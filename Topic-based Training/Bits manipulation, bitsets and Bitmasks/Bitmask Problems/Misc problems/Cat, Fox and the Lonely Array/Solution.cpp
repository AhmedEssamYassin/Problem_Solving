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
		return (a | b);
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

	ll query(int L, int R)
	{
		int len = R - L + 1;
		int k = 31 - __builtin_clz(len);
		return merge(m[L][k], m[R - (1 << k) + 1][k]);
	}
};

bool isOk(const vector<ll> &vc, sparseTable &ST, ll K)
{
	bool isSame = true;
	ll OR = ST.query(0, K - 1);
	ll cur{};
	for (int i = 1; i < vc.size(); i++)
	{
		if (i + K - 1 >= vc.size())
			break;
		cur = ST.query(i, i + K - 1);
		isSame &= (cur == OR);
	}
	return isSame;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	If we have a valid K for which, each sub-array of length K has the same OR
	then we always can have also that condition held at (K + 1)
	That means this function is monotonic, and we can binary search on K
	But for every candidate K, to check the OR value of each consecutive K elements, we need to do it fast
	We can use a sparse table to do that in O(1)
	*/
	int t = 1;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		sparseTable ST(vc, 21);
		ll L{1}, R = N, ans = N;
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (isOk(vc, ST, mid))
			{
				ans = mid;
				R = mid - 1;
			}
			else
				L = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
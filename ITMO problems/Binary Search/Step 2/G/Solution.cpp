#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

// 1 2 3 4 5 6
bool isOk(vector<int> a, ll K, ll mid)
{
	ll councils = mid;
	ll totalStudents = mid * K;
	for (ll elem : a)
		totalStudents -= min(councils, elem);
	return (totalStudents <= 0);
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
	ll N, K;
	// cin >> t;
	while (t--)
	{
		cin >> K >> N;
		vector<int> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];

		ll ans{};
		ll L{}, R{1LL << 40};
		while (L <= R)
		{
			ll mid = ((L + R) >> 1);
			if (isOk(a, K, mid))
			{
				ans = mid; // A candidate solution
				// Search for a better (larger) answer
				L = mid + 1;
			}
			else
				R = mid - 1;
		}
		cout << ans;
	}
	return 0;
}
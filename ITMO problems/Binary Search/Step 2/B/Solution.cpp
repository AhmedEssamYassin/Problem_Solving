#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Ok(vector<ll> &vc, ll K, long double val)
{
	int cnt{};
	for (int i{}; i < vc.size(); i++)
		cnt += (vc[i] / val);
	return cnt >= K;
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
		cin >> N >> K;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];
		long double L{}, R{1e8}, ans;
		int rounds = 100;
		while (rounds--)
		{
			long double mid = ((L + R) / 2);
			if (Ok(vc, K, mid))
				ans = mid, L = mid; // Search larger cut (larger candidate answer)
			else
				R = mid;
		}
		cout << fixed << setprecision(9) << ans << endl;
	}
	return 0;
}
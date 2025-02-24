#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool isOk(const vector<pair<ll, ll>> &vc, const long double &mid)
{
	long double maxStart{-1e12}, minEnd{1e12};
	for (int i{}; i < vc.size(); i++)
	{
		maxStart = max(maxStart, vc[i].first - vc[i].second * mid);
		minEnd = min(minEnd, vc[i].first + vc[i].second * mid);
	}
	return (maxStart <= minEnd);
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
		cin >> N;
		vector<pair<ll, ll>> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i].first >> vc[i].second;
		long double L{}, R{2e9}, ans;
		for (int i{}; i < 70; i++) // 70 iterations are good for precision
		{
			long double mid = (L + R) / 2;
			if (isOk(vc, mid))
			{
				ans = mid; // A candidate solution
				R = mid;   // Search for a better (smaller) answer
			}
			else
				L = mid;
		}
		cout << fixed << setprecision(9) << ans;
	}
	return 0;
}
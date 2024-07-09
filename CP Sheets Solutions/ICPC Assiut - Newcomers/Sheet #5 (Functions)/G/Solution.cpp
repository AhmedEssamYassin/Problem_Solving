#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll minElement(const vector<ll> &vc)
{
	ll mn = LLONG_MAX;
	for (int i{}; i < vc.size(); i++)
		mn = min(mn, vc[i]);
	return mn;
}

ll maxElement(const vector<ll> &vc)
{
	ll mx = LLONG_MIN;
	for (int i{}; i < vc.size(); i++)
		mx = max(mx, vc[i]);
	return mx;
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
	ll N, X;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];
		cout << minElement(a) << " " << maxElement(a);
	}
	return 0;
}
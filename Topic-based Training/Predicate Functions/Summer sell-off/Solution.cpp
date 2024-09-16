#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool pred(const pair<ll, ll> &P1, const pair<ll, ll> &P2)
{
	ll init1 = min(P1.second, P1.first);
	ll fin1 = min(P1.second, P1.first * 2);
	ll init2 = min(P2.second, P2.first);
	ll fin2 = min(P2.second, P2.first * 2);
	if (P1.first * P2.first)
		return (fin1 - init1 > fin2 - init2);
	else
	{
		if (P1.first)
			return true;
		return false;
	}
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
	ll N, f;
	// cin >> t;
	while (t--)
	{
		cin >> N >> f;
		vector<pair<ll, ll>> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i].first >> vc[i].second;
		sort(vc.begin(), vc.end(), pred);
		ll ans{};
		for (int i{}; i < N; i++)
		{
			if (i < f)
				ans += min(vc[i].first * 2, vc[i].second);
			else
				ans += min(vc[i].first, vc[i].second);
		}
		cout << ans;
	}
	return 0;
}
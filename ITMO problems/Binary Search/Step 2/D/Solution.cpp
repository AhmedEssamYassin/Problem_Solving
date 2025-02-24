#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Assistant
{
	ll time;
	ll limit;
	ll rest;
};

tuple<bool, vector<ll>> Ok(const ll &balloons, const vector<Assistant> &vc, const ll &mid)
{
	ll res{};
	vector<ll> ans;
	for (int i{}; i < vc.size(); i++)
	{
		const auto &[t, z, y] = vc[i];
		ll countBalloon = mid / (t * z + y) * z + min((mid % (t * z + y) / t), z);
		res += countBalloon;
		ans.push_back(countBalloon);
	}
	return {res >= balloons, ans};
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
		cin >> M >> N;
		vector<Assistant> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i].time >> vc[i].limit >> vc[i].rest;

		ll L{}, R{(1LL << 33)};
		tuple<ll, vector<ll>> ans;
		while (L <= R) // Binary search on time needed
		{
			ll mid = (L + ((R - L) >> 1));
			auto current = Ok(M, vc, mid);
			if (get<0>(current))
				ans = {mid, get<1>(current)}, R = mid - 1; // Search smaller answer (Less time)
			else
				L = mid + 1;
		}
		ll time = get<0>(ans);
		cout << time << endl;
		ll remaining = M;
		auto ballonNum = [&vc](int i, int time)
		{
			const auto &[t, z, y] = vc[i];
			ll period = t * z + y;
			return time / period * z + min((time % period) / t, z);
		};
		for (int i = 0; i < N; i++)
		{
			ll num = ballonNum(i, time);
			if (num > remaining)
				num = remaining; // He can make more than the required, MAKE him inflate less (He also can!)
			remaining -= num;
			cout << num << " ";
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

auto random_address = []
{ char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
std::mt19937 rnd(SEED);
#define rng(l, r) uniform_int_distribution<int64_t>(l, r)(rnd)

typedef array<int, 30> number; // Max number is 5e5 < (1 << 30)

ll toInt(const number &x)
{
	return accumulate(x.begin(), x.end(), 0LL);
}

number operator^(const number &LHS, const number &RHS)
{
	number C;
	for (int i{}; i < 30; i++)
	{
		C[i] = LHS[i] + RHS[i];
		C[i] -= 3 * (C[i] >= 3);
	}
	return C;
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
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];

		vector<number> vc(N + 1);
		// setting random values to all numbers
		for (int i{1}; i <= N; i++)
			for (int j{}; j < 30; j++)
				vc[i][j] = rnd() % 3;

		vector<number> pref(1);
		vector<vector<int>> pos(N + 1);
		map<number, int> cnt;
		cnt[array<int, 30>{0}] = 1;
		int cur = 0;
		ll ans = 0;
		for (int i{}; i < N; i++)
		{
			pref.push_back((pref.back() ^ vc[a[i]]));
			pos[a[i]].push_back(i);
			// 1 2 2 2 1 1 2 2 2
			if (pos[a[i]].size() >= 4)
			{
				while (cur <= pos[a[i]][pos[a[i]].size() - 4])
				{
					cnt[pref[cur]]--;
					++cur;
				}
			}
			ans += cnt[pref.back()];
			cnt[pref.back()]++;
		}
		cout << ans;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

auto random_address = []
{ char *p = new char; delete p; return uint64_t(p); };
const uint64_t SEED = chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1);
std::mt19937 rnd(SEED);
#define rng(l, r) uniform_int_distribution<int64_t>(l, r)(rnd)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, Q;
	cin >> t;
	vector<ll> XOR(1e6 + 1);
	for (ll &hash : XOR)
		hash = rng(1LL << 40, 1LL << 63);
	while (t--)
	{
		cin >> N >> Q;
		vector<ll> a(N);
		for (int i{}; i < N; i++)
			cin >> a[i];

		vector<ll> pref(N, 0);
		pref[0] = XOR[a[0]];
		for (int i{1}; i < N; i++)
			pref[i] = (pref[i - 1] ^ XOR[a[i]]);
		while (Q--)
		{
			ll L, R;
			cin >> L >> R;
			L--, R--;
			ll Round = pref[R] ^ (L ? pref[L - 1] : 0);
			if (Round == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}
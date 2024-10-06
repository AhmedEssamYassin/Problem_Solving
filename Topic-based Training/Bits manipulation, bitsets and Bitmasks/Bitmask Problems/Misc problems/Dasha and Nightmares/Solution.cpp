#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

inline bool isCleared(int x, int i)
{
	return !(x & (1 << i));
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
	ll N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		map<int, int> mp;
		map<int, array<int, 26>> mh;
		ll cnt{};
		ll val = (1 << 26) - 1; // 26 characters `on`

		for (int i{}; i < N; i++)
		{
			string str;
			cin >> str;
			int bitmask{}, h{};
			for (const char &C : str)
				bitmask ^= (1 << (C - 'a')), h |= (1 << (C - 'a'));

			// abccd --> 1011
			// aaabd --> 1011
			// Same hash but one is valid for 'c' off and one is not!
			for (ll k = 0; k < 26; k++)
			{
				ll cur = (val & ~(1 << k)); // 1 character `off`
				ll x = (bitmask ^ cur);		// The required string bitmask to be concatenated
				if (isCleared(h, k) && mp.find(x) != mp.end())
					cnt += mp[x] - mh[x][k];
			}
			mp[bitmask]++;
			for (int k{}; k < 26; k++)
			{
				int bit = (bitmask & (1 << k));
				if (bit == 0 && (h & (1 << k))) // even occurrence
					mh[bitmask][k]++;
			}
		}
		cout << cnt;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	/*
	Formally, for any two numbers x and y in the same group, they MUST have all 32 bits different
	That means for a number x we add a new group iff there isn't a group already containing a number will all bits different
	i.e., we add a new group for x iff there is NOT a group containing ((1LL << 31) - 1) ^ x
	Otherwise, we don't add a new group, and also close this group because a group cannot contain more than 2 numbers
	because it's impossible for any number to have all bits different w.r.t to other two numbers with same property
	*/
	int t = 1;
	ll N, K;
	cin >> t;
	while (t--)
	{
		cin >> N;
		map<ll, ll> cnt;
		ll ans{};
		for (int i{}; i < N; i++)
		{
			ll x;
			cin >> x;
			if (cnt[x] == 0) // First time to show, or a closed group
				ans++, cnt[((1LL << 31) - 1) ^ x]++;
			else
				cnt[x]--; // So that the next time it appears we put it in a separate set
		}
		cout << ans << endl;
	}
	return 0;
}
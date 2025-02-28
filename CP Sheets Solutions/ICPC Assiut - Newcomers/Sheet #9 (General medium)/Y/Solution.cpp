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
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		ll k, L, R;
		cin >> N >> k;
		ll cnt{};
		while (N--)
		{
			cin >> L >> R;
			cnt += (R - L + 1);
		}
		/*
		First number N to be:
		1. A multiple of k : N % k == 0
		2. Greater than or equal cnt: N >= cnt
		*/
		cout << (cnt + k - 1) / k * k - cnt;
	}
	return 0;
}

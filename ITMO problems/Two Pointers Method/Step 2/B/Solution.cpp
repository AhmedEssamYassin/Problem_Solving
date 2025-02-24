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
	ll N, S;
	// cin >> t;
	while (t--)
	{
		cin >> N >> S;
		vector<ll> vc(N);
		for (int i{}; i < N; i++)
			cin >> vc[i];

		int L{}, R{}, maxLen{INT_MAX};
		ll sum{};
		while (R < N)
		{
			sum += vc[R];
			while (sum - vc[L] >= S && L <= R)
				sum -= vc[L++];
			if (sum >= S)
				maxLen = min(maxLen, R - L + 1);
			R++;
		}
		if (maxLen == INT_MAX)
			cout << -1;
		else
			cout << maxLen;
	}
	return 0;
}
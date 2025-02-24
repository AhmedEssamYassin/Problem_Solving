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
		int L{}, R{}, maxLen{};
		ll sum{};
		while (R < N)
		{
			sum += vc[R];
			while (sum > S && L <= R)
				sum -= vc[L++];
			maxLen = max(maxLen, R - L + 1);
			R++;
		}
		cout << maxLen;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll numberOfWays(ll S, ll E)
{
	if (S >= E)
		return (S == E);
	ll try1 = numberOfWays(S + 1, E);
	ll try2 = numberOfWays(S + 2, E);
	ll try3 = numberOfWays(S + 3, E);
	return (try1 + try2 + try3);
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
	ll N, S, E;
	// cin >> t;
	while (t--)
	{
		cin >> S >> E;
		cout << numberOfWays(S, E);
	}
	return 0;
}
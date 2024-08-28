#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool reachValue(ll val, ll N)
{
	if (val >= N)
		return (val == N);

	return (reachValue(val * 10, N) || reachValue(val * 20, N));
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
	ll N, X;
	cin >> t;
	while (t--)
	{
		cin >> N;
		if (reachValue(1, N))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
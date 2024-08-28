#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll nCr(ll n, ll r)
{
	if (n == r || r == 0)
		return 1;
	return (n * nCr(n - 1, r - 1) / r);
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
	ll N, R;
	// cin >> t;
	while (t--)
	{
		cin >> N >> R;
		cout << nCr(N, R);
	}
	return 0;
}
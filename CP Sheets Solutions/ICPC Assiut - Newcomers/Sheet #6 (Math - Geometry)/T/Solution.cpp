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
		int x, y, r, n, xi, yi;
		cin >> x >> y >> r >> n;
		while (n--)
		{
			cin >> xi >> yi;
			long double dist;
			dist = sqrtl(pow(abs(xi - x), 2) + pow(abs(yi - y), 2));
			if (dist <= r)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
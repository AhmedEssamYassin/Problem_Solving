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
		long double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		long double c1x, c1y, c2x, c2y, r1, r2, dist;
		c1x = (x1 + x2) / 2;
		c1y = (y1 + y2) / 2;
		c2x = (x3 + x4) / 2;
		c2y = (y3 + y4) / 2;
		dist = sqrtl(powl(abs(c1x - c2x), 2) + powl(abs(c1y - c2y), 2));
		r1 = sqrtl(powl(abs(x1 - x2), 2) + powl(abs(y1 - y2), 2)) / 2;
		r2 = sqrtl(powl(abs(x3 - x4), 2) + powl(abs(y3 - y4), 2)) / 2;
		if (dist <= r1 + r2)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}
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
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> N;
		ll x1, y1, x2, y2;
		ll max_x1 = INT_MIN, max_y1 = INT_MIN, min_x2 = INT_MAX, min_y2 = INT_MAX;
		while (N--)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			max_x1 = max(x1, max_x1);
			max_y1 = max(y1, max_y1);
			min_x2 = min(x2, min_x2);
			min_y2 = min(y2, min_y2);
		}
		if (min_x2 > max_x1 and min_y2 > max_y1)
			cout << "Case #" << i << ": " << (min_x2 - max_x1) * (min_y2 - max_y1) << "\n";
		else
			cout << "Case #" << i << ": " << 0 << "\n";
	}
	return 0;
}
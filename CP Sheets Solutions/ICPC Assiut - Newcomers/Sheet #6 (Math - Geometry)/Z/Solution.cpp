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
		ll r, s;
		cin >> r >> s;
		if (2 * r >= s && sqrtl(2 * powl(s, 2)) <= 2 * r)
			cout << "Circle";
		else if (s >= 2 * r && sqrtl(2 * powl(s, 2)) >= 2 * r)
			cout << "Square";
		else
			cout << "Complex";
	}
	return 0;
}
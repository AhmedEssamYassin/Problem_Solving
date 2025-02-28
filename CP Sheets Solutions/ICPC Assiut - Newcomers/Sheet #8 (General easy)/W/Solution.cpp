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
		string a, b;
		cin >> a >> b;

		if (a == b)
			return cout << -1, 0;
		// The longest of them will be, by definition, an uncommon subsequence (ans it's the longest)
		cout << max(a.size(), b.size());
	}
	return 0;
}

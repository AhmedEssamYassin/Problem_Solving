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
		cin >> N;
		// (EVEN + EVEN) must be EVEN except for 2 = 1 + 1
		if (N > 2 and N % 2 == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}

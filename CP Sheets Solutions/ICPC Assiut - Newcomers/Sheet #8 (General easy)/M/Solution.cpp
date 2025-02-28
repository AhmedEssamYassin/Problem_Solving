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
		int arr[3];
		for (int i = 0; i < 3; i++)
			cin >> arr[i];

		// Supposing x1 < x2 < x3
		// Optimal case occurs when adding (x2 - x1) + (x3 - x2) which is eventually equal to (-x1 + x3)

		sort(arr, arr + 3);
		cout << -1 * arr[0] + arr[2];
	}
	return 0;
}

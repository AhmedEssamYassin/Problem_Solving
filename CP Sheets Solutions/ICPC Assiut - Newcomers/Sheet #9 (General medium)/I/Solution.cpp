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
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		for (int i = 0; i < N; i++)
		{
			// First position
			if (i == 0)
				cout << arr[i + 1] - arr[i] << " " << arr[N - 1] - arr[i] << endl; // Minimum is going to the following (nearest) point and maximum is going to the last (farthest) point

			// Last position
			else if (i == N - 1)
				cout << arr[i] - arr[i - 1] << " " << arr[i] - arr[0]; // Minimum is going to the previous (nearest) point and maximum is going to the first (farthest) point

			// Any intermediate points
			else
				cout << min(arr[i] - arr[i - 1], arr[i + 1] - arr[i]) << " " << max(arr[N - 1] - arr[i], arr[i] - arr[0]) << endl;
			// Minimum between going to the following or the previous point (which is nearer?)
			// Maximum between going to the first or the last point (which is farer?)
		}
		delete arr;
	}
	return 0;
}

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
	ll N, m, q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> q; // 5 3
		vector<ll> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i]; // 5 2 4 1 3

		sort(arr.begin(), arr.end()); // 1 2 3 4 5

		vector<ll> ScanLine(N, 0);
		while (q--)
		{
			ll L, R;
			cin >> L >> R;
			L--, R--; // To be 0-based
			ScanLine[L]++;
			if (R < N - 1)
				ScanLine[R + 1]--;
		}
		// 0 0 0 0  0
		// 1 0 0 0  0
		// 1 1 0 -1 0
		// 1 2 0 -2 0
		for (int i = 1; i < N; i++)
			ScanLine[i] += ScanLine[i - 1];
		// 1 3 3 1 1

		sort(ScanLine.begin(), ScanLine.end());
		// 1 1 1 3 3

		// Since we are free to reorder the elements, we should know the occurrences of every number in all queries
		// and then reorder the occurrences and the numbers in ascending order
		// So that bigger occurrences are taken of the bigger number
		ll sum{};
		for (int i = 0; i < N; i++)
			sum += (arr[i] * ScanLine[i]);
		// 1 * 1 + 1 * 2 + 1 * 3 + 3 * 4 + 3 * 5 = 33
		cout << sum;
	}
	return 0;
}
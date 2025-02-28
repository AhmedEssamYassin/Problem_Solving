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
	ll N, K;
	// cin >> t;
	while (t--)
	{
		cin >> N >> K;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N);
		// 3 7 5 1 10 3 20
		// 1 3 3 5 7 10 20
		int ans;
		int cnt{};
		if (K) // K > 0
			ans = arr[K - 1];

		else // K = 0
			ans = arr[0] - 1;
		// Less than the smallest number

		if (ans < 1 || ans == arr[K]) // Making sure that NO numbers after the position (K - 1) are also less or equal to ans
			cout << -1;
		else
			cout << ans;

		delete[] arr;
	}
	return 0;
}

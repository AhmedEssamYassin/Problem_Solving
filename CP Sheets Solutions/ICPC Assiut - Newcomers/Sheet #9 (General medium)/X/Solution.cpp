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
	ll N, k;
	// cin >> t;
	while (t--)
	{
		cin >> N >> k;
		vector<ll> arr(2 * N + 1);
		for (int i{}; i < 2 * N + 1; i++)
			cin >> arr[i];

		for (int i{1}; i < 2 * N && k > 0; i += 2) // Starting i from zero (0-indexed) makes EVEN i's be: 1, 3, 5.....
		{
			if (arr[i] - 1 > arr[i - 1] and arr[i] - 1 > arr[i + 1]) // If 1 is subtracted, Does the condition STILL hold?
				arr[i]--, k--;
		}
		for (int i{}; i < 2 * N + 1; i++)
			cout << arr[i] << " ";
	}
	return 0;
}

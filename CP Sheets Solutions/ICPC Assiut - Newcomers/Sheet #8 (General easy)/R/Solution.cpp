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
		vector<ll> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int pos_max, pos_min, max = INT_MIN, min = INT_MAX;

		for (int i = 0; i < N; i++)
		{
			if (arr[i] > max)
			{
				pos_max = i + 1; // 1-based
				max = arr[i];
			}
			if (arr[i] <= min)
			{
				pos_min = i + 1; // 1-based
				min = arr[i];
			}
		}
		cout << (pos_max - 1) + (N - pos_min - (pos_max > pos_min));
	}
	return 0;
}

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

		// If number of elements is just one or two, it's always a valid arithmetic sequence
		if (N <= 2)
			return cout << "0\n", 0; // No operations needed

		/*
		The first two terms of a sequence are enough to determine the constant arithmetic difference.
		Let's try ALL possible cases of the first two terms and choose the case where number of changes is minimum
		but how to know the changes in other terms?
		each element should be equal to Xi = (arr[0] + (pos - 1) * d)
		Then if abs(arr[i] - Xi) > 1, this progression is impossible (because we can only add or subtract 1 or leave it unchanged)
		*/
		int h[3] = {-1, 0, 1};
		int ans{INT_MAX};
		// 24 21 14 10
		for (int i{}; i < 3; i++)
		{
			for (int j{}; j < 3; j++)
			{
				bool validProgression = true;
				int numberOfChanges = 0;
				int d = arr[2] + h[i] - arr[1] - h[j]; // The constant difference = new_arr[1] - new_arr[0]

				int f = arr[1] + h[j] - d; // new_arr[1] - new_arr[0] = d
				// Reordering: new_arr[1] - d = new_arr[0]
				for (int t{}; t < N; t++)
				{
					if (abs(f + d * t - arr[t]) > 1)
					{
						validProgression = false;
						break;
					}
					if (abs(f + d * t - arr[t]) == 1)
						numberOfChanges++;
				}
				if (validProgression)
					ans = min(ans, numberOfChanges);
			}
		}
		cout << (ans == INT_MAX ? -1 : ans);
		delete[] arr;
	}
	return 0;
}

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
	freopen("mex.in", "r", stdin);
	int t = 1;
	int N, Q, L, R;
	cin >> t;
	while (t--)
	{
		/*
		Since the given array is guaranteed to be a permutation, i.e. it includes all numbers [1, N]
		The MEX in any range is obviously the minimum of the remaining of the array
		Example:
		2 6 1 5 3 4
		The MEX in range L = 2, R = 4 --> 2
		The MEX in range L = 4, R = 6 --> 1
		The MEX in range L = 1, R = 6 --> 7 (Special Case)
		*/
		cin >> N;
		cin >> Q;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		vector<int> minPref(N), minSuf(N);

		minPref[0] = arr[0];
		for (int i{1}; i < N; i++)
			minPref[i] = min(minPref[i - 1], arr[i]);

		minSuf[N - 1] = arr[N - 1];
		for (int i{N - 2}; i >= 0; i--)
			minSuf[i] = min(minSuf[i + 1], arr[i]);

		while (Q--)
		{
			cin >> L >> R;
			if (R - L + 1 == N)
			{
				cout << N + 1 << endl;
				continue;
			}
			L--, R--; // To be 0-based
			cout << min(L > 0 ? minPref[L - 1] : INT_MAX, R < N - 1 ? minSuf[R + 1] : INT_MAX) << endl;
		}
		delete[] arr;
	}
	return 0;
}
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
#endif // !ONLINE_JUDGE
	int t = 1, N;
	cin >> t;
	while (t--)
	{
		/*
		NON-decreasing means that Every arr[i] >= arr[i - 1]
		The idea is based on fact that a sorted sub_array of length N adds (N * (N - 1)/2) to result.
		For example, {10, 10, 30, 40} adds 6 to the result. Why??
		because the sub_arrays:
		{10, 10}, {10, 10, 30}, {10, 10, 30, 40}, {10, 30}, {10, 30, 40} and {30, 40} are ALL NON-decreasing.

		That means, if we have a NON-decreasing sub_array of length N
		We will also have ((N - 1) + (N - 2) + (N - 3) ... + (1)) NON-decreasing sub_arrays
		That means it adds ((N - 1) * (N - 1 + 1) / 2) = N * (N - 1)/2 to the result

		Time complexity: O(N)
		*/
		cin >> N;
		int *arr = new int[N];

		for (int i{}; i < N; i++)
			cin >> arr[i];

		ll cnt{}, len = 1;
		for (int i{1}; i < N; i++)
		{
			if (arr[i] >= arr[i - 1]) // Increase the length of this NON-decreasing sub_array
				len++;
			else // A NON-decreasing sub_array ended
			{
				cnt += (len * (len + 1) / 2);
				len = 1; // Resetting the length
			}

			if (i == N - 1)
				cnt += (len * (len + 1) / 2);
		}
		cout << (N == 1 ? N : cnt) << endl;
		delete[] arr;
	}

	return 0;
}
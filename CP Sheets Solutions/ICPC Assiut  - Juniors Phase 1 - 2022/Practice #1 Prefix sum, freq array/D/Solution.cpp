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
		/*
		Let instability of the array be the following value: maximum element − minimum element
		You have to remove exactly one element from this array to minimize instability of the resulting (n−1)-elements array.
		Your task is to calculate the minimum possible instability.

		After sorting the array in ascending order, We have 3 possibilities:
		1. Remove the last (the maximum) element: It will ONLY matter if the last element was NOT repeated
		2. Remove the first (the minimum) element: It will ONLY matter if the first element was NOT repeated
		If both of them is repeated, under these constrains (ONLY one removal is allowed),
		3. The original instability is the minimum possible value we can acquire
		*/
		cin >> N;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];
		sort(arr, arr + N);

		cout << min({arr[N - 2] - arr[0], arr[N - 1] - arr[1], arr[N - 1] - arr[0]});
		delete[] arr;
	}
	return 0;
}

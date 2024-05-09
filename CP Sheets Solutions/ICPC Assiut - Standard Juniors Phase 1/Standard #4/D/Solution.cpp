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

	int N, Given_sum;
	cin >> N >> Given_sum;
	int *arr = new int[N];
	for (size_t i{}; i < N; i++)
		cin >> arr[i];

	/*
	Please note:
	- The problem specifically targets sub_arrays that are contiguous (i.e., occupy consecutive positions) and inherently maintains the order of elements.
	  Also note that we don’t have to print the sub_array but print its length.

	- We can solve this problem by using the sliding window technique.
	  The idea is to maintain a window that ends at the current element, and the sum of its elements is less than or equal to the given sum.
	  If the current window’s sum becomes more than or equal to the given sum at any point of time,
	  then the window is unstable and continue removing elements from the window’s left till it becomes stable again.
	  Also update the result if the unstable window’s length is less than the minimum length found so far
	*/

	int L{}, R{}; // Two-pointers (Sliding window) technique
	ll Window_sum{};
	int Min_length = INT_MAX;

	for (NULL; R < N; R++)
	{
		Window_sum += arr[R]; // Expand

		while (Window_sum >= Given_sum && L <= R)
		{
			Min_length = min(Min_length, R - L + 1);
			Window_sum -= arr[L++];
		}
	}
	if (Min_length == INT_MAX) // If NO valid sub_array found
		cout << -1;
	else
		cout << Min_length;

	delete[] arr;
	return 0;
}
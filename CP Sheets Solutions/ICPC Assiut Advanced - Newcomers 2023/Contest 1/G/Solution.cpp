#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i{}; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	/*
	If current element is NOT greater than previous element by 1 (i.e., they are NOT consecutive)
	Then, an interval is needed to represent the previous Sub_array and a new interval starts
	*/
	int cnt{};
	for (int i{1}; i < N; i++)
	{
		if (arr[i] - 1 != arr[i - 1])
			cnt++;
	}
	cnt++; // To count the interval representing the last Sub_array (because NO element after the end will cause the condition to hold)
	cout << cnt;
	delete[] arr;
	return 0;
}
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
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int min = INT_MAX;
	int pos;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < min) // We use the operator < NOT <= so that all numbers that share the minimum value but have greater index are excluded
		{
			min = arr[i];
			pos = i + 1; // To store the index 1-based
		}
	}
	cout << min << " " << pos;
	delete[] arr;
	return 0;
}
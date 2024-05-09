#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Binary_Search(int *arr, int N, int Val)
{
	int L = 0, R = N;
	int mid;
	while (L <= R)
	{
		mid = L + (R - L) / 2;
		if (arr[mid] == Val)
			return true;
		if (arr[mid] > Val) // Exclude ALL rightmost elements
			R = mid - 1;
		else // Exclude ALL leftmost elements
			L = mid + 1;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int t = 1, N, Q;
	// cin >> t;
	while (t--)
	{
		cin >> N >> Q;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N); // To apply Binary search, the array must be sorted

		int Val;
		while (Q--)
		{
			cin >> Val;
			if (Binary_Search(arr, N, Val))
				cout << "found" << endl;
			else
				cout << "not found" << endl;
		}
		delete[] arr;
	}

	return 0;
}
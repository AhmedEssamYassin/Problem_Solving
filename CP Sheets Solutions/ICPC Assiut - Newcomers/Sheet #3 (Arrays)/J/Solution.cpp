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
	// cin >> t;
	while (t--)
	{
		cin >> N;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		int Min_element{INT_MAX};
		for (int i{}; i < N; i++)
			Min_element = min(Min_element, arr[i]);
		if (count(arr, arr + N, Min_element) & 1) // ODD frequency
			cout << "Lucky";
		else
			cout << "Unlucky";
		delete[] arr;
	}

	return 0;
}
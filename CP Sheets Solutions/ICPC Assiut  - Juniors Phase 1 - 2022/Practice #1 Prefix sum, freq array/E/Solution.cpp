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
		int N, M, L;
		cin >> N >> M;
		int *arr = new int[N];
		int freqArr[100001] = {0};
		int *suffSum = new int[N + 1];
		// 1 2 3 4 1 2 3 4 100000 99999
		for (int i{}; i < N; i++)
			cin >> arr[i];

		for (int i{N - 1}; i >= 0; i--)
		{
			freqArr[arr[i]]++;
			if (i == N - 1)
				suffSum[i] = 1; // At Last element, number of distinct elements is always 1
			else
				suffSum[i] = suffSum[i + 1] + (freqArr[arr[i]] == 1);
		}
		// For each number L he wants to know how many distinct numbers are staying on the positions Li, Li + 1, ..., N.
		// Formally, he want to find the number of distinct numbers among arr[Li], arr[Li + 1], ..., arr[N]
		while (M--)
		{
			cin >> L;
			cout << suffSum[--L] << endl;
		}

		delete[] arr, suffSum;
	}
	return 0;
}

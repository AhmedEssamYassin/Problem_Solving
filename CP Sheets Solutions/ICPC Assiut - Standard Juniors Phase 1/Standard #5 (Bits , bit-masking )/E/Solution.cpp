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

	short int N;
	cin >> N;
	int *arr = new int[N];
	for (int i{}; i < N; i++)
		cin >> arr[i];

	// Given an array of size N, Count all subsets that have EVEN numbers greater than odd numbers
	int Subsets_cnt{};
	for (int i = 0; i < (1 << N); i++)
	{
		// Loop through all elements of the input array
		int EVEN_cnt{}, ODD_cnt{};
		for (int j = 0; j < N; j++)
		{
			// Check if the jth bit is set in the current subset
			if (i & (1 << j))
			{
				// If the jth bit is set, add the jth element to the subset
				if (arr[j] & 1) // ODD
					ODD_cnt++;
				else
					EVEN_cnt++;
			}
		}
		if (EVEN_cnt > ODD_cnt)
			Subsets_cnt++;
	}
	cout << Subsets_cnt;
	delete[] arr;
	return 0;
}
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
		cin >> N;
		int *arr = new int[N];
		for (int i{}; i < N; i++)
			cin >> arr[i];

		/*
		ALL sub_arrays are:
		[0], [0, 1], [0, 1, 2],...,[0, 1, 2, 3, ..., N-1]
		[1], [1, 2], [1, 2, 3],...,[1, 2, 3, 4, ..., N-1]
		[2], [2, 3], [2, 3, 4],...,[2, 3, 4, 5, ..., N-1]
		..
		..
		..
		So, at each index i, Sub_arrays can be formed by building ALL ranges [i, j] where (i =< j < N)
		*/
		for (int i{}; i < N; i++)
		{
			for (int j{i}; j < N; j++)
				cout << *max_element(arr + i, arr + j + 1) << " ";
		}
		cout << endl;
		delete[] arr;
	}

	return 0;
}
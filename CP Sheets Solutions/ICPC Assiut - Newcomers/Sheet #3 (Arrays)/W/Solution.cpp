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
	int t = 1, N, M, X;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		int **arr = new int *[N]; // Assigning a pointer to the address of a memory block of size N in heap (Array of N pointers)
		for (int i{}; i < N; i++)
		{
			// Assigning each pointer to the address of a memory block of size M in heap (Each is an array of M integers)
			arr[i] = new int[M];
		}

		for (int i{}; i < N; i++)
		{
			for (int j{}; j < M; j++)
				cin >> arr[i][j];
		}

		for (int i{}; i < N; i++)
			reverse(arr[i], arr[i] + M); // Reversing each row

		for (int i{}; i < N; i++)
		{
			for (int j{}; j < M; j++)
				cout << arr[i][j] << " \n"[j == M - 1];
		}

		// Freeing memory
		for (int i{}; i < N; i++)
			delete[] arr[i]; // Freeing each memory block of size M in heap

		delete[] arr; // Freeing the memory block of size N (The array of pointers)
	}

	return 0;
}
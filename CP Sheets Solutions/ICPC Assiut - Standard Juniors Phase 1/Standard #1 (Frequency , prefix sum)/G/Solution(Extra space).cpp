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

	int N, M, Q;
	cin >> N >> M >> Q;

	int **arr = new int *[N]; // Array of N pointers
	for (int i{}; i < N; i++)
		arr[i] = new int[M]; // Assigning each pointer to a block of size M

	uint64_t **Prefix_sum_2D = new uint64_t *[N]; // Prefix sum array of N pointers
	for (int i{}; i < N; i++)
		Prefix_sum_2D[i] = new uint64_t[M]; // Assigning each pointer to a block of size M

	// Inputting
	for (size_t i{}; i < N; i++)
	{
		for (size_t j{}; j < M; j++)
			cin >> arr[i][j];
	}

	// Simultaneously accumulating rows and columns
	for (size_t i{}; i < N; i++)
	{
		for (size_t j{}; j < M; j++)
			Prefix_sum_2D[i][j] = (i > 0 ? Prefix_sum_2D[i - 1][j] : 0) + (j > 0 ? Prefix_sum_2D[i][j - 1] : 0) - (i && j ? Prefix_sum_2D[i - 1][j - 1] : 0) + arr[i][j];
	}

	int x1, x2, y1, y2;
	while (Q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		cout << Prefix_sum_2D[x2][y2] - (y1 > 0 ? Prefix_sum_2D[x2][y1 - 1] : 0) - (x1 > 0 ? Prefix_sum_2D[x1 - 1][y2] : 0) + (x1 && y1 ? Prefix_sum_2D[x1 - 1][y1 - 1] : 0) << endl;
	}
	// Freeing Memory
	for (int i{}; i < N; i++)
		delete[] Prefix_sum_2D[i]; // Deleting each block of size M

	delete[] Prefix_sum_2D; // Deleting the N pointers

	for (int i{}; i < N; i++)
		delete[] arr[i]; // Deleting each block of size M

	delete[] arr; // Deleting the N pointers

	return 0;
}
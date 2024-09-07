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
	uint64_t **arr = new uint64_t *[N]; // Array of N pointers
	for (int i{}; i < N; i++)
		arr[i] = new uint64_t[M]; // Assigning each pointer to a block of size M

	// Inputting
	for (size_t i{}; i < N; i++)
	{
		for (size_t j{}; j < M; j++)
			cin >> arr[i][j];
	}

	// Accumulate Rows
	for (size_t i = 0; i < N; i++)	 // To traverse rows
		for (size_t j{}; j < M; j++) // To reverse Columns
			arr[i][j] += (j > 0 ? arr[i][j - 1] : 0);

	// Accumulate Columns
	for (size_t i = 0; i < M; i++)	 // To traverse columns
		for (size_t j{}; j < N; j++) // To traverse rows
			arr[j][i] += (j > 0 ? arr[j - 1][i] : 0);

	int x1, x2, y1, y2;
	while (Q--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		cout << arr[x2][y2] - (y1 > 0 ? arr[x2][y1 - 1] : 0) - (x1 > 0 ? arr[x1 - 1][y2] : 0) + (x1 && y1 ? arr[x1 - 1][y1 - 1] : 0) << endl;
	}
	// Freeing Memory
	for (int i{}; i < N; i++)
		delete[] arr[i]; // Deleting each block of size M

	delete[] arr; // Deleting the N pointers

	return 0;
}
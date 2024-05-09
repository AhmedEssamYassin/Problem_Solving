#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

enum dir
{
	DOWN = 0, // By default is 0
	RIGHT,
	UP,
	LEFT,
	UP_LEFT,
	DOWN_RIGHT,
	UP_RIGHT,
	DOWN_LEFT
};
int dir_row[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dir_col[] = {0, 1, 0, -1, -1, 1, 1, -1};

ll Sum_with_direction(int r, int c, int N, int M, int dir, int **board)
{
	ll Sum{};
	while (r >= 0 && r < N && c >= 0 && c < M)
	{
		Sum += board[r][c];
		r += dir_row[dir];
		c += dir_col[dir];
	}
	return Sum;
}

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
		int **arr = new int *[N]; // Assigning a pointer to the address of a memory block of size N in heap (Array of N pointers)
		for (int i{}; i < N; i++)
		{
			// Assigning each pointer to the address of a memory block of size N in heap (Each is an array of M integers)
			arr[i] = new int[N];
		}

		for (int i{}; i < N; i++)
		{
			for (int j{}; j < N; j++)
				cin >> arr[i][j];
		}

		ll Main_diagonal = Sum_with_direction(0, 0, N, N, DOWN_RIGHT, arr); // Moving on main diagonal

		ll Secondary_diagonal = Sum_with_direction(0, N - 1, N, N, DOWN_LEFT, arr); // Moving on secondary diagonal

		cout << abs(Main_diagonal - Secondary_diagonal);

		// Freeing memory
		for (int i{}; i < N; i++)
			delete[] arr[i]; // Freeing each memory block of size M in heap

		delete[] arr; // Freeing the memory block of size N (The array of pointers)
	}

	return 0;
}
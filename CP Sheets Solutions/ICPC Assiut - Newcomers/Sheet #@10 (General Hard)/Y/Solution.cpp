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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<vector<ll>> arr(N, vector<ll>(M));
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < M; j++)
				cin >> arr[i][j];
		}
		/*
		Spiral Order of a matrix
		------------------------
		Add (0, 1) to move RIGHT
		Add (1, 0) to move DOWN
		Add (0,-1) to move LEFT
		Add (-1,0) to move UP
		*/
		int Row_Transition[] = {0, 1, 0, -1};
		int Col_Transition[] = {1, 0, -1, 0};

		int x = 0, y = 0; // To traverse the cells
		int dir = 0;	  // To traverse (0, 1), (1, 0), (0,-1) and (-1,0)

		vector<ll> Spiral_Order;							 // To store elements in a spiral order
		vector<vector<bool>> Vis(N, vector<bool>(M, false)); // To mark visited elements in order NOT to print them again

		// Iterate from 0 to N * M - 1
		for (int i = 0; i < N * M; i++)
		{
			Spiral_Order.push_back(arr[x][y]);
			Vis[x][y] = true; // Mark as visited

			int new_x = x + Row_Transition[dir];
			int new_y = y + Col_Transition[dir];

			// Check if new_x is in range [0, N - 1] and new_y is in range [0, M - 1]
			// Also check that this cell, [new_x][new_y], wasn't visited before
			if ((new_x >= 0 && new_x < N) && (new_y >= 0 && new_y < M) && !Vis[new_x][new_y])
			{
				x = new_x;
				y = new_y;
			}
			else
			{
				dir = (dir + 1) % 4; // To have a cyclic value in range [0, 3]
				x += Row_Transition[dir];
				y += Col_Transition[dir];
			}
		}
		for (ll number : Spiral_Order)
			cout << number << " ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int N, M;
struct Star
{
	int Center_X, Center_Y, Length;
};

char arr[101][101];
bool Visited[101][101];

void Mark(int center_x, int center_y, int moves)
{
	int colMove = center_y + moves;
	int col = center_y;
	while (col <= colMove) // Marking right cells
		Visited[center_x][col++] = 1;

	colMove = center_y - moves;
	col = center_y;
	while (col >= colMove) // Marking left cells
		Visited[center_x][col--] = 1;

	int rowMove = center_x + moves;
	int row = center_x;
	while (row <= rowMove) // Marking downward cells
		Visited[row++][center_y] = 1;

	rowMove = center_x - moves;
	row = center_x;
	while (row >= rowMove) // Marking upward cells
		Visited[row--][center_y] = 1;
}

int Check_star(int center_x, int center_y)
{
	int right = 0, left = 0, upward = 0, downward = 0;

	int col = center_y;
	while (col < M && arr[center_x][col] == '*') // Expanding to the right
	{
		right++;
		col++;
	}

	col = center_y;
	while (col >= 0 && arr[center_x][col] == '*') // Expanding to the left
	{
		left++;
		col--;
	}

	int row = center_x;
	while (row >= 0 && arr[row][center_y] == '*') // Expanding upward
	{
		upward++;
		row--;
	}
	row = center_x;
	while (row < N && arr[row][center_y] == '*') // Expanding downward
	{
		downward++;
		row++;
	}
	return min({right - 1, left - 1, upward - 1, downward - 1}); // We subtract 1 to exclude the star at the center
}

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
		vector<Star> Ans;
		cin >> ::N >> ::M;

		for (int i{}; i < ::N; i++)
		{
			for (int j{}; j < ::M; j++)
				cin >> arr[i][j];
		}

		for (int i{}; i < ::N; i++)
		{
			for (int j{}; j < ::M; j++)
			{
				if (arr[i][j] == '*')
				{
					int Number_of_stars = Check_star(i, j);
					if (Number_of_stars > 0)
					{
						Ans.push_back({i + 1, j + 1, Number_of_stars});
						Mark(i, j, Number_of_stars);
					}
				}
			}
		}

		for (int i{}; i < ::N; i++)
		{
			for (int j{}; j < ::M; j++)
			{
				if (arr[i][j] == '*')
				{
					if (!Visited[i][j])
						return cout << -1, 0;
				}
			}
		}
		cout << Ans.size() << endl;
		for (int i{}; i < Ans.size(); i++)
			cout << Ans[i].Center_X << " " << Ans[i].Center_Y << " " << Ans[i].Length << endl;
	}
	return 0;
}

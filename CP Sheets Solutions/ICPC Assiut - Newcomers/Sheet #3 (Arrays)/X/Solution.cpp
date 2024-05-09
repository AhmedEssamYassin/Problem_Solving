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

char Grid[101][101];
int N, M;
bool Is_OK(int r, int c, int dir)
{
	r += dir_row[dir];
	c += dir_col[dir];
	if (r >= 0 && r < N && c >= 0 && c < M) // If still inside the Grid
		return (Grid[r][c] == 'x');

	return true; // If NO neighboring cell exists, it doesn't negate the state
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	int t = 1, X, Y;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < M; j++)
				cin >> Grid[i][j];
		}

		cin >> X >> Y;
		X--, Y--;
		if (Is_OK(X, Y, UP) &&
			Is_OK(X, Y, UP_RIGHT) &&
			Is_OK(X, Y, RIGHT) &&
			Is_OK(X, Y, DOWN_RIGHT) &&
			Is_OK(X, Y, DOWN) &&
			Is_OK(X, Y, DOWN_LEFT) &&
			Is_OK(X, Y, LEFT) &&
			Is_OK(X, Y, UP_LEFT))
			cout << "yes";
		else
			cout << "no";
	}

	return 0;
}
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
#endif //! ONLINE_JUDGE

    // Current problem: https://codeforces.com/contest/1692/problem/C
    int t, N, M;
    cin >> t;
    while (t--)
    {
        cin >> N >> M;
        int **Chess_board = new int *[N]; // N pointers
        for (int i{}; i < N; i++)
            Chess_board[i] = new int[M]; // Each pointer holds the address of a block of size M

        for (int i{}; i < N; i++)
        {
            for (int j{}; j < M; j++)
                cin >> Chess_board[i][j];
        }

        ll Max_diagonal_sum{INT_MIN};
        // UP RIGHT, UP LEFT, DOWN RIGHT, DOWN LEFT

        ll Cur_sum;
        for (int i{}; i < N; i++)
        {
            for (int j{}; j < M; j++)
            {
                Cur_sum = 0;
                Cur_sum += Sum_with_direction(i, j, N, M, UP_RIGHT, Chess_board);
                Cur_sum += Sum_with_direction(i, j, N, M, UP_LEFT, Chess_board);
                Cur_sum += Sum_with_direction(i, j, N, M, DOWN_RIGHT, Chess_board);
                Cur_sum += Sum_with_direction(i, j, N, M, DOWN_LEFT, Chess_board);
                Cur_sum -= (3 * Chess_board[i][j]);
                Max_diagonal_sum = max(Max_diagonal_sum, Cur_sum);
            }
        }
        cout << Max_diagonal_sum << endl;

        // Freeing memory
        for (int i{}; i < N; i++)
            delete[] Chess_board[i];
        delete[] Chess_board;
    }
    return 0;
}
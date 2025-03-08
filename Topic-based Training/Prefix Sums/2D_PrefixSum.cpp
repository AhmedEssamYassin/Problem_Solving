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
    ll N, M, Q;
    // cin >> t;
    while (t--)
    {
        cin >> N >> M;

        vector<vector<ll>> arr(N + 1, vector<ll>(M + 1, 0));
        vector<vector<ll>> PrefixSum2D(N + 1, vector<ll>(M + 1, 0));
        // Inputting
        for (size_t i{1}; i < N + 1; i++)
        {
            for (size_t j{1}; j < M + 1; j++)
                cin >> arr[i][j];
        }

        // Simultaneously accumulating rows and columns
        for (size_t i{1}; i < N + 1; i++)
        {
            for (size_t j{1}; j < M + 1; j++)
                PrefixSum2D[i][j] = PrefixSum2D[i - 1][j] + PrefixSum2D[i][j - 1] - PrefixSum2D[i - 1][j - 1] + arr[i][j];
        }

        int x1, x2, y1, y2;
        cin >> Q;
        while (Q--)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << PrefixSum2D[x2][y2] - PrefixSum2D[x2][y1 - 1] - PrefixSum2D[x1 - 1][y2] + PrefixSum2D[x1 - 1][y1 - 1] << endl;
        }
    }
    return 0;
}
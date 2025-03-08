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
	int N, M, Q, X1, Y1, X2, Y2, X, Y, S;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;

		vector<vector<int>> arr(N + 2, vector<int>(M + 2, 0));
		vector<vector<ll>> PrefixSum2D(N + 2, vector<ll>(M + 2, 0));

		// Queries
		cin >> Q;
		while (Q--)
		{
			cin >> X >> Y >> S;

			// Get the top-left and bottom-right corners
			X1 = max(X - S, 1);
			Y1 = max(Y - S, 1);
			X2 = min(X + S, N);
			Y2 = min(Y + S, M);

			arr[X1][Y1] += 1;
			arr[X2 + 1][Y2 + 1] += 1;
			// Stopping scanLine
			arr[X1][Y2 + 1] += -1;
			arr[X2 + 1][Y1] += -1;
		}

		// Simultaneously accumulating rows and columns
		for (size_t i{1}; i <= N; i++)
		{
			for (size_t j{1}; j <= M; j++)
				PrefixSum2D[i][j] = (PrefixSum2D[i - 1][j]) + (PrefixSum2D[i][j - 1]) - (PrefixSum2D[i - 1][j - 1]) + arr[i][j];
		}

		ll ans{};
		for (int i{}; i <= N + 1; i++)
		{
			for (int j{}; j <= M + 1; j++)
				ans += (PrefixSum2D[i][j] > 0);
		}

		cout << ans << endl;
	}
	return 0;
}
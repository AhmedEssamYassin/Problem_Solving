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
	ll N, X, Y;
	// cin >> t;
	while (t--)
	{
		cin >> N >> X >> Y;
		vector<vector<ll>> arr(N, vector<ll>(N));
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < N; j++)
				cin >> arr[i][j];
		}
		X--, Y--; // To be 0-based

		vector<int> row(N), col(N); // Two arrays for indices of rows and columns
		for (int i{}; i < N; i++)
			row[i] = i; // 0 1 2 3 ... N

		for (int i{}; i < N; i++)
			col[i] = i; // 0 1 2 3 ... N

		swap(row[X], row[Y]);
		swap(col[X], col[Y]);
		for (int i{}; i < N; i++)
		{
			for (int j{}; j < N; j++)
				cout << arr[row[i]][col[j]] << " ";
			cout << endl;
		}
	}
	return 0;
}
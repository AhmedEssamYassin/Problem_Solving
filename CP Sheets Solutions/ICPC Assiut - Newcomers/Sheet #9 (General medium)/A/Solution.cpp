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
		cin >> N >> M >> Q;
		vector<vector<char>> arr(N, vector<char>(M));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				arr[i][j] = '.';
		}

		int r1, r2, c1, c2;
		char c;
		while (Q--)
		{
			cin >> r1 >> c1 >> r2 >> c2 >> c; // The given r1 is not necessarily smaller than the given r2 so we should make sure to use r1 and r2 where r1<=r2
			// 2-D arrays are 0-indexed while given r and c are 1-indexed so we should subtract 1 from both r and c
			for (int i = min(r1, r2) - 1; i < max(r1, r2); i++)
			{
				for (int j = min(c1, c2) - 1; j < max(c1, c2); j++)
					arr[i][j] = c;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << arr[i][j];
			cout << endl;
		}
	}
	return 0;
}

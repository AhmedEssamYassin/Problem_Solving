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
	ll N;
	// cin >> t;
	while (t--)
	{
		int rows, cols, ans{};
		cin >> rows >> cols;
		char cell;
		int r[11] = {0}, c[11] = {0};
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> cell;
				if (cell == 'S')
					r[i] = c[j] = 1; // Mark uneaten rows and columns by 1 and all others by default will be zeros
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (r[i] == 0 or c[j] == 0)
					ans++;
			}
		}
		cout << ans;
	}
	return 0;
}

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
		string dir;
		cin >> N >> dir;
		int *pos = new int[N];
		for (int i = 0; i < N; i++)
			cin >> pos[i];
		int ans = INT_MAX;
		for (int i = 1; i < N; i++)
		{
			if (dir[i] == 'L' and dir[i - 1] == 'R')
				ans = min(ans, pos[i] - pos[i - 1]);
		}
		if (ans == INT_MAX)
			cout << -1;
		else
			cout << ans / 2;
		delete pos;
	}
	return 0;
}

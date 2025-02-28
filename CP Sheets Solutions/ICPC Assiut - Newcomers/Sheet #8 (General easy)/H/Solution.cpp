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
		cin >> N;
		vector<ll> ans(N);
		for (int i = 1; i <= N; i++)
		{
			int x;
			cin >> x;
			ans[x - 1] = i;
		}
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
	}
	return 0;
}

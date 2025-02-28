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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<ll> arr(M);
		for (int i{}; i < M; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());

		int L{}, R = N - 1;
		int minAns = INT_MAX;
		while (R < M)
		{
			int cur = arr[R] - arr[L];
			if (cur < minAns)
				minAns = cur;
			L++, R++;
		}
		cout << minAns;
	}
	return 0;
}

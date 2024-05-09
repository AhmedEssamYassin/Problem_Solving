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
#endif // !ONLINE_JUDGE

	int t;
	ll N, S;
	cin >> t;
	while (t--)
	{
		cin >> N >> S;
		if ((N * (N + 1) / 2) < S) // There CANNOT be a sum that is equal to S even if we include all positive DISTINCT numbers from 1 to N
		{
			cout << -1 << endl;
			continue;
		}

		if (S <= N)
		{
			cout << S << endl;
			continue;
		}

		ll sum{};
		for (int i = N; i >= 1; i--)
		{
			if (sum + i <= S)
			{
				sum += i;
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
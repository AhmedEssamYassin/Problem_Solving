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
		ll sumOfDivisors{};
		for (ll d{1}; d * d <= N; d++)
		{
			if (N % d == 0)
			{
				if (N / d == d)
					sumOfDivisors += d;
				else
					sumOfDivisors += (d + (N / d));
			}
		}
		cout << sumOfDivisors;
	}
	return 0;
}
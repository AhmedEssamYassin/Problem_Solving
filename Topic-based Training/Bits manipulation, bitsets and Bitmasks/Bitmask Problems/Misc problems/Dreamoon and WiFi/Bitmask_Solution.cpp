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
	ll N, x;
	// cin >> t;
	while (t--)
	{
		string original, received;
		cin >> original >> received;
		ll finalRes = 0;
		for (const char &c : original)
		{
			if (c == '+')
				finalRes++;
			else
				finalRes--;
		}
		ll res{}, qMark{};
		for (const char &c : received)
		{
			if (c == '+')
				res++;
			else if (c == '-')
				res--;
			else
				qMark++;
		}
		long double Q = (1LL << qMark);
		// Since the length is <= 10, so small, we can brute force all possibilities
		// Mark 0 as +, 1 as -
		long double P{};
		for (ll bitmask = 0; bitmask < (1LL << qMark); bitmask++)
		{
			ll temp = res;
			for (int j{}; j < qMark; j++)
			{
				if (bitmask & (1LL << j))
					temp--;
				else
					temp++;
			}
			P += (temp == finalRes);
		}
		cout << fixed << setprecision(9) << P / Q;
	}
	return 0;
}
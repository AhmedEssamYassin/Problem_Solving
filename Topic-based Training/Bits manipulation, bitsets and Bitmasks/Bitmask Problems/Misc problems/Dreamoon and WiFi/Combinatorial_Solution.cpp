#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll nCr(ll n, ll r)
{
	if (r > n || r < 0)
		return 0;
	if (r == 0 || n == r)
		return 1;
	return n * nCr(n - 1, r - 1) / r;
}

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
		ll finalRes = 0, ones1{}, ones2;
		for (const char &c : original)
		{
			if (c == '+')
				finalRes++, ones1++;
			else
				finalRes--;
		}
		ll res{}, qMark{};
		for (const char &c : received)
		{
			if (c == '+')
				res++, ones2++;
			else if (c == '-')
				res--;
			else
				qMark++;
		}
		// We can also have a linear combinatorial solution
		// See how many combinations of the question marks can be our difference in positives
		if (qMark == 0 && res != finalRes)
			return cout << fixed << setprecision(9) << 0.0, 0;
		long double Q = (1LL << qMark);
		ll P = nCr(qMark, ones1 - ones2);
		cout << fixed << setprecision(9) << P / Q;
	}
	return 0;
}
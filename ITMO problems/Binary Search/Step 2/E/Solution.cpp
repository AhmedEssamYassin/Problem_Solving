#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

constexpr long double EPS1 = 1e-9;
constexpr long double EPS2 = 1e-15;

int compute_status(long double C, long double val)
{
	long double term = val * val + sqrt(val);
	if (abs(term - C) < EPS1)
		return 0;
	if (term > C)
		return -1;
	return 1;
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
	ll N, M;
	long double C;
	// cin >> t;
	while (t--)
	{
		cin >> C;

		long double L = 0, R = 1e10, ans = -1;
		while (R - L > EPS2)
		{
			long double mid = (L + ((R - L) / 2));
			int status = compute_status(C, mid);
			if (!status)
			{
				ans = mid;
				break;
			}
			else if (status == 1)
				L = mid;
			else
				R = mid;
		}
		cout << fixed << setprecision(12) << ans;
	}
	return 0;
}
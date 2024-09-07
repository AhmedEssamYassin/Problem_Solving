#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Check(long double &N, int &C, int &Time)
{
	return (C * N * log2(N) <= Time);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int C, Time;
	cin >> C >> Time;
	long double ans;
	long double L = 0.0, R = 2e9;
	while (L <= R)
	{
		long double mid = L + (R - L) / 2;
		if (Check(mid, C, Time))
		{
			ans = mid; // A candidate answer

			L = mid + 0.000001; // Search for a better (greater) answer
		}
		else
			R = mid - 0.000001; // Search for a valid greatest minimum distance
	}
	cout << fixed << setprecision(6) << ans;

	return 0;
}
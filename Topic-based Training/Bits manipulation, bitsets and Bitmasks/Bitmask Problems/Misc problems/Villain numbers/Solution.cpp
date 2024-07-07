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
	/*
	0 1 2 3	4 5 6 7		8 9 10 11		12 13 14 15 ...
	0 01 10 11	 0100 0101 0110 0111 	1000 1001 1010 1011 	1100 1101 1110 1111
	In each group of 4 consecutive numbers, there is a 1 valid number (1 very evil number)
	*/
	int t = 1;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		ll ans = (N - 4) / 4;
		for (ll i = N / 4 * 4; i <= N; i++)
		{
			if (!(i & 1) && !(__builtin_popcount(i) & 1))
				ans++;
		}

		cout << ans - (N <= 3) << endl;
	}
	return 0;
}
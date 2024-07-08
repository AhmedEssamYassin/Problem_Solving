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
	To make (x & y) > 0, there should be at least one set bit in both of them
	Since we want to minimize y, lets choose the first set bit in x, and set it also in y

	To make (x ^ y) > 0, there should be at least one set bit in one of them but NOT the other
	Iff there weren't any set bits greater than ffs(x), we need to set one more bit in y
	Since we want to minimize y, lets choose the first cleared bit in x and set in y
	*/
	int t = 1;
	ll x;
	cin >> t;
	while (t--)
	{
		cin >> x;
		int k = __builtin_ffs(x); // find first set bit (1-based)
		ll y = (1LL << (k - 1));
		if (__countl_zero(x) == 63 - k)
		{
			for (int i{}; i < 31; i++)
			{
				if ((x & (1 << i)) == 0)
				{
					y |= (1 << i);
					break;
				}
			}
		}
		cout << y << endl;
	}
	return 0;
}
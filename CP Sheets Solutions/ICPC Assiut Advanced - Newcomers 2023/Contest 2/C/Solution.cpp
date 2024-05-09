#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif

	/*
	Note that we always can make fractions equal in two operations:
	1. Multiply first fraction's numerator by bc, the first fraction is equal to (a * b * c) / b = (a * c)
	2. Multiply second fraction's numerator by ad, the second fraction is equal to (a * c * d) / d = (a * c)

	That means that the answer does not exceed 2

	If fractions are equal from input, the answer is 0.
	Otherwise, it CANNOT be 0

	Now we have to check if the answer is 1.
	Let's assume that for making fractions equal in 1 operation we have to multiply first fraction's numerator by x
	Then (a * x) / b = (c * d) must be true. From this we can see that x = (b * c) / (a * d), x must be integer, so (b * c) MUST be divisible by (a * d)
	If we assume that we multiplied first fraction's denominator by x, we can do the same calculations and see that (a * d) MUST be divisible by (b * c)
	So, for checking if the answer is 1 we need to check if one of ad and bc is divisible by the other.
	If we multiply second fraction's numerator or denominator by x we will get the same conditions for answer being equal to 1

	If the answer is NOT 0 or 1, then, it's 2

	Time Complexity: O(1)
	*/
	int t;
	cin >> t;
	ll a, b, c, d;
	while (t--)
	{
		cin >> a >> b >> c >> d;
		if ((a * d) == (b * c)) // if((a / b) == (c / d))
			cout << 0 << endl;
		else
		{
			// b and d CANNOT be 0 (It's a constraint, denominators CANNOT be 0)
			// We MUST make sure that (a != 0) and (c != 0) when calculating mod to avoid dividing by 0
			if ((a != 0) && ((b * c) % (a * d) == 0) || (c != 0) && ((a * d) % (b * c) == 0))
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
	}

	return 0;
}
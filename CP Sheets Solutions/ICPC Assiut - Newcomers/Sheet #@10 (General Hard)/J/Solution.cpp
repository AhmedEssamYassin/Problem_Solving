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
		/*
		Assume the 4 gems are x,y,z and w
		d1	c1	c2	d2
		r1	x	y
		r2	z	w
		We See that :
		1| x + y = r1
		2| z + w = r2
		3| x + z = c1
		4| y + w = c2
		5| x + w = d1
		6| y + z = d2
		Since we have only 4 unknowns and 6 equations, We Can solve the equations to get either a specific ONLY solution or NO solution at all
		eqn.1 - eqn.4 ==> 		x - w = r1 - c2
		==> Solve with eqn.5:	x + w = d1
		We get: x = (r1-c2+d1)/2
		thus,	y = r1 - x
		and		z = d2 - y
		also	w = d1 - x
		*/
		int r1, r2, c1, c2, d1, d2;
		cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
		int x = (r1 - c2 + d1) / 2;
		int y = r1 - x;
		int z = d2 - y;
		int w = d1 - x;
		// x, y, z and w can't have the same answer because Vasilisa only has one gem with each number from 1 to 9
		if (x + y != r1 || z + w != r2 || x + z != c1 || y + w != c2 || x + w != d1 || y + z != d2 || (x < 1 || x > 9 || y < 1 || y > 9 || z < 1 || z > 9 || w < 1 || w > 9) || (x == y || x == z || x == w || y == z || y == w || z == w))
			cout << -1;
		else
			cout << x << " " << y << "\n"
				 << z << " " << w;
	}
	return 0;
}

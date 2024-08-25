#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct point
{
	long double x, y;
};

point Solve2Lines(string line1, string line2)
{
	// y = 4x + 3
	// y = x - 5
	// y = 4x
	long double x1 = 1, x2 = 1, c1 = 0, c2 = 0;
	int posX = line1.find('x');
	if (posX == 5 && line1[posX - 1] == '-')
		x1 *= -1;
	else if (posX > 4)
		x1 = stold(line1.substr(4, posX - 3));

	int pos = line1.find('+', posX + 1);
	if (pos != -1)
		c1 = stold(line1.substr(pos + 2));
	else
	{
		pos = line1.find('-', posX + 1);
		if (pos != -1)
			c1 = -stold(line1.substr(pos + 2));
	}

	posX = line2.find('x');
	if (posX == 5 && line2[posX - 1] == '-')
		x2 *= -1;

	else if (posX > 4)
		x2 = stold(line2.substr(4, posX - 3));
	pos = line2.find('+', posX + 1);
	if (pos != -1)
		c2 = stold(line2.substr(pos + 2));
	else
	{
		pos = line2.find('-', posX + 1);
		if (pos != -1)
			c2 = -stold(line2.substr(pos + 2));
	}
	long double x = (c2 - c1) / (x1 - x2);
	long double y = x1 * x + c1;
	return {x, y};
}

long double areaOfTriangle(const point &P1, const point &P2, const point &P3)
{
	return 0.5 * abs(P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y - P2.y));
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
	ll N, A, B, C;
	// cin >> t;
	while (t--)
	{
		string line1, line2, line3;
		getline(cin, line1);
		getline(cin, line2);
		getline(cin, line3);
		point P1, P2, P3;
		// Solving lines
		P1 = Solve2Lines(line1, line2);
		P2 = Solve2Lines(line1, line3);
		P3 = Solve2Lines(line2, line3);

		cout << fixed << setprecision(14) << areaOfTriangle(P1, P2, P3);
	}
	return 0;
}
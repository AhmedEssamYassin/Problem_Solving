#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

struct Point
{
	int X, Y;
};

bool isRight(Point &P1, Point &P2, Point &P3)
{
	int P1P2_Squared, P2P3_Squared, P1P3_Squared; // To store the distance² between every two points
	P1P2_Squared = pow(P1.X - P2.X, 2) + pow(P1.Y - P2.Y, 2);
	P2P3_Squared = pow(P2.X - P3.X, 2) + pow(P2.Y - P3.Y, 2);
	P1P3_Squared = pow(P1.X - P3.X, 2) + pow(P1.Y - P3.Y, 2);
	int d[3] = {P1P2_Squared, P2P3_Squared, P1P3_Squared};
	sort(d, d + 3);
	if (d[0] + d[1] == d[2] && d[0] && d[1] && d[2]) // If(a² + b² = c² and a², b², c² > 0, they CANNOT be 0 because, for a triangle to exist, points can't COINCIDE )
		return true;
	else
		return false;
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
	ll N;
	// cin >> t;
	while (t--)
	{
		Point vertex[3];
		for (auto &[X, Y] : vertex)
			cin >> X >> Y;

		if (isRight(vertex[0], vertex[1], vertex[2]))
			return cout << "RIGHT", 0;

		/*
		We will try ALL possible moves (brute-force solution)
		At each point, we will try moving X by {+1, -1} while Y is kept unchanged (because we are allowed to move a point ONLY by distance 1 at a time)
		Then, we will try moving Y by {+1, -1} while X is kept unchanged for the same reason
		Finally, we return X and Y to their initial positions (in order NOT to affect the following trials)
		*/
		for (int i{}; i < 3; i++)
		{
			// Trials on X
			vertex[i].X++; // Moving X by +1
			if (isRight(vertex[0], vertex[1], vertex[2]))
				return cout << "ALMOST", 0;

			vertex[i].X -= 2; // Moving X by -1 (-1 to return it to its initial position and -1 for moving)
			if (isRight(vertex[0], vertex[1], vertex[2]))
				return cout << "ALMOST", 0;

			vertex[i].X++; // Returning X to its initial position
			//------------------------------------------
			// Trials on Y
			vertex[i].Y++; // Moving Y by +1
			if (isRight(vertex[0], vertex[1], vertex[2]))
				return cout << "ALMOST", 0;

			vertex[i].Y -= 2; // Moving Y by -1 (-1 to return it to its initial position and -1 for moving)
			if (isRight(vertex[0], vertex[1], vertex[2]))
				return cout << "ALMOST", 0;

			vertex[i].Y++; // Returning Y to its initial position
		}
		cout << "NEITHER";
	}
	return 0;
}

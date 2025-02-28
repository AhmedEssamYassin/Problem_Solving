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
		ll L, S1, S2, Q, Qi;
		cin >> L >> S1 >> S2 >> Q;
		/*
		The bottom left corner of each square is (0, 0)
		Square_1 moves with S1 diagonally,i.e. the distance d1 between the position of the bottom left corner of square_1 after time t becomes (t * S1)
		d1 = (t * S1)
		Similarly, d2 = (t * S2)
		The diagonal of a square = sqrt(2) * L, where L is the side length
		The diagonal of the common square with area Qi = sqrt(2) * sqrt(Qi)
		after some time t (which is required), Assuming S2 > S1
		(d2 - d1) = sqrt(2) * L - sqrt(2) * sqrt(Qi) = sqrt(2) * (L - sqrt(Qi))
		t * S2 - t * S1 = t * (S2 - S1) = sqrt(2) * (L - sqrt(Qi))
		therefore, t = sqrt(2) * (L - sqrt(Qi)) / (S2 - S1)
		*/
		cout << fixed << setprecision(6);
		while (Q--)
		{
			cin >> Qi;
			if (S1 < S2)
				cout << sqrt(2) * (L - sqrt(Qi)) / (S2 - S1) << endl;
			else
				cout << sqrt(2) * (L - sqrt(Qi)) / (S1 - S2) << endl;
		}
	}
	return 0;
}

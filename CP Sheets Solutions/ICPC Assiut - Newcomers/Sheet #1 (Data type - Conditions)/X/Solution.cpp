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
#endif // !ONLINE_JUDGE

	/*
	This algorithm can be generalized to get the mutual interval between several given intervals (more than two)

	Example:
	If intervals are: [1, 7], [3, 8], [2, 14] and [5, 6]

	get L = the maximum of all beginnings (because it's guaranteed to have the possibility to be included in all intervals)
	in our example: 5 is guaranteed to have the possibility to be included in all intervals

	get R = the minimum of all ends (because it's guaranteed to have the possibility to be included in all intervals)
	in our example: 6 is guaranteed to have the possibility to be included in all intervals

	check if L <= R
	then, A mutual interval exists and is [L, R]
	Otherwise, There CANNOT be a mutual interval
	*/
	int L1, R1, L2, R2;
	cin >> L1 >> R1 >> L2 >> R2;
	int L = max(L1, L2);
	int R = min(R1, R2);
	if (L <= R)
		cout << L << " " << R;
	else
		cout << -1;

	return 0;
}
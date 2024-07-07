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
	In the minimum element, we want to make every bit 0 when possible, it won't be possible to set a particular bit to 0
	when that bit is set in all the elements of a.
	Therefore, the minimum value we can achieve after performing the operations is the bitwise AND of all the elements of a

	In the maximum element, we want to make every bit 1 when possible, it won’t be possible to set a particular bit to 1
	when that bit is NOT set in any of the elements of a.
	Therefore, the maximum value we can achieve after performing the operations is the bitwise OR of all the elements of a
	*/
	int t = 1;
	int N, X;
	cin >> t;
	while (t--)
	{
		cin >> N;
		int Max{}, Min{0b1111111111};
		while (N--)
		{
			cin >> X;
			Max |= X;
			Min &= X;
		}
		cout << Max - Min << endl;
	}

	return 0;
}
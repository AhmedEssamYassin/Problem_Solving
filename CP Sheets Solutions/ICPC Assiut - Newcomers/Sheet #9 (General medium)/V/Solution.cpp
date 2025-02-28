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
		Let B[i] = (A[i] / 2) + δ[i]
		It follows that if A[i] is even, then δ[i] = 0,
		and if A[i] is odd, then either δ[i] = 0.5 or δ[i] = −0.5

		At the same time, the sum of all B[i] is equal to the sum of δ[i], as the sum of A[i] is 0
		Thus, as the sum of B[i] must be equal to 0, we need to have an equal number of δ[i] equal to 0.5 and −0.5 to CANCEL each other

		In simple words, we have to divide all numbers by 2
		, and out of all NON-integers, exactly half of them must be rounded up and the other half must be rounded down.
		*/
		int rate;
		cin >> N;
		int gate = 1;
		while (N--)
		{
			cin >> rate;
			if (rate & 1) // ODD
			{
				cout << ((rate + gate) / 2) << endl;
				gate *= -1;
			}
			else // EVEN
				cout << rate / 2 << endl;
		}
	}
	return 0;
}

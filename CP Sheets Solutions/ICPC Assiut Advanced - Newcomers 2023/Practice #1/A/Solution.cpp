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
	Let B[i] = (A[i] / 2) + δ[i]
	It follows that if A[i] is even, then δ[i] = 0,
	and if A[i] is odd, then either δ[i] = 0.5 or δ[i] = −0.5

	At the same time, the sum of all B[i] is equal to the sum of δ[i], as the sum of A[i] is 0
	Thus, as the sum of B[i] must be equal to 0, we need to have an equal number of δ[i] equal to 0.5 and −0.5 to CANCEL each other

	In simple words, we have to divide all numbers by 2
	, and out of all NON-integers, exactly half of them must be rounded up ( ⌈x⌉ ) and the other half must be rounded down ( ⌊x⌋ )
	*/
	int N, rate;
	cin >> N;
	int flag = 1;
	while (N--)
	{
		cin >> rate;
		if (rate & 1) // ODD
		{
			cout << ((rate + flag) / 2) << endl;
			/*
			For ODD rates:
			(rate + 1)/2 evaluates to ⌈rate / 2⌉
			(rate - 1)/2 evaluates to ⌊rate / 2⌋
			*/
			flag *= -1;
		}
		else // EVEN
			cout << rate / 2 << endl;
	}

	return 0;
}
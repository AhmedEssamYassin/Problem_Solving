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
	If the Kth bit is set in XOR means there is an ODD number of 1's in that Kth bit
	It can be cleared iff: The Kth bit in any B[j] is set && A's length is EVEN
	Because ORing ALL A[i]'s with that B[j] sets the Kth bit in ALL A[i]'s,
	so for Kth bit to be cleared in XOR, A's length must be EVEN

	Similarly, If the Kth bit is cleared in XOR means there is an EVEN number (possibly 0) of 1's in that Kth bit
	It can be set iff: The Kth bit in any B[j] is set && A's length is ODD
	Because ORing ALL A[i]'s with that B[j] sets the Kth bit in ALL A[i]'s,
	so for Kth bit to be set in XOR, A's length must be ODD

	To know whether the Kth bit is set in any B[j] or not, we can just check if the Kth bit is set in the OR of ALL B[j]'s
	*/
	int t = 1;
	int N, M;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		vector<ll> A(N), B(M);
		ll XOR{}, OR{};
		for (int i{}; i < N; i++)
		{
			cin >> A[i];
			XOR ^= A[i];
		}

		for (int i{}; i < M; i++)
		{
			cin >> B[i];
			OR |= B[i];
		}

		ll min_XOR = XOR;
		ll max_XOR = XOR;
		for (int K{}; K < 31; K++)
		{
			if (XOR & (1 << K)) // If Kth bit set
			{
				if (!(N & 1)) // If A's length is EVEN
				{
					if (OR & (1LL << K))
						min_XOR &= (~(1 << K));
				}
			}
			else // If Kth bit cleared
			{
				if (N & 1) // If A's length is ODD
				{
					if (OR & (1LL << K))
						max_XOR |= (1 << K);
				}
			}
		}
		cout << min_XOR << " " << max_XOR << endl;
	}

	return 0;
}
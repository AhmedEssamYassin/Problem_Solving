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
	when Q = 1, F(Q) = A
	when Q = 2, F(Q) = B
	when Q = 3, F(Q) = (F(Q - 1) ^ F(Q - 2)) = (B ^ A)
	when Q = 4, F(Q) = (F(Q - 1) ^ F(Q - 2)) = ((B ^ A) ^ B) = A
	when Q = 5, F(Q) = (F(Q - 1) ^ F(Q - 2)) = (A ^ (B ^ A)) = B
	when Q = 6, F(Q) = (F(Q - 1) ^ F(Q - 2)) = (B ^ A) = (B ^ A)
	.
	.
	.
	The values are cyclic, i.e., they repeat each 3 calls
	*/
	int t = 1;
	ll N, A, B, Q;
	while (t--)
	{
		cin >> A >> B >> Q;
		if (Q % 3 == 1)
			cout << A;
		else if (Q % 3 == 2)
			cout << B;
		else
			cout << (B ^ A);
	}

	return 0;
}
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
	For NOT longer than N-digit numbers, and in every digits there are two possibilities: 7 or 8
	we consider all ith-digit numbers where (1 <= i <= N)
	for numbers with 1 digit, we have 2 possibilities
	for numbers with 2 digit, we have 2² possibilities
	for numbers with 3 digit, we have 2³ possibilities
	.
	.
	.
	We can see that the total sum of possibilities = 2 + 2² + 2³ + ... and so on
	This is equivalent to (1 << (N + 1)) - 1 - 1
	-1 to make it N set bits and the other -1 to exclude the 1 (NO 0-digit numbers)
	*/
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		cout << (1LL << (N + 1)) - 2;
	}
	return 0;
}
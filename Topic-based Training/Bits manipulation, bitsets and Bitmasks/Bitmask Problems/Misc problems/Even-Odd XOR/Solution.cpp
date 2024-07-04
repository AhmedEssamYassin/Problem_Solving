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
	Let's call the XOR at odd positions oddXOR, and the XOR at even positions evenXOR
	Let's also call the XOR of the whole generated range just XOR
	Making oddXOR = evenXOR, means that the XOR = 0 must hold, because XOR = (oddXOR ^ evenXOR)
	(x ^ x) = 0
	Trying (1, 2, 3, 4, ... N - 1, XOR)  --> XOR may be NOT distinct
	Trying (1, 2, 3, 4, ... N - 2, X, (X ^ XOR)) --> XOR of all numbers from 1 to (N - 2) can be 0 which leads to Y = X (NOT distinct)
	The good construction is turns to be
	(1, 2, 3, 4, ... N - 3, X, Y, (XOR ^ X ^ Y)), where X and Y are some big unique integers
	X = (1 << 29)
	Y = (1 << 30)
	Z = (XOR ^ (X ^ Y))

	But, is really oddXOR = evenXOR this way? - YES, let's prove it
	let evenXOR = A, and oddXOR = B
	XOR of all numbers from 1 to N - 3 = XOR = (A ^ B)
	The last three terms: X, Y, (XOR ^ X ^ Y)
	assume X is at even position, so Y is at odd position, and (XOR ^ X ^ Y) is at even position
	evenXOR = A ^ X ^ (XOR ^ X ^ Y) = A ^ XOR ^ Y = A ^ (A ^ B) ^ Y = B ^ Y
	oddXOR = B ^ Y
	So, they are equal.
	similarly, we can prove it for X when at odd position
	*/
	int t = 1;
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		ll XOR{};
		for (int i{1}; i <= N - 3; i++)
			cout << i << " ", XOR ^= i;
		cout << (1LL << 29) << " " << (1LL << 30) << " " << (XOR ^ (1LL << 29) ^ (1LL << 30)) << endl;
	}
	return 0;
}
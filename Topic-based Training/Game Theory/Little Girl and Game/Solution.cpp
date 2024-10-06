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
	ll N, x;
	// cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		ll occ{}; // 0 for even number of occurrences and 1 for odd
		for (const char &C : str)
			occ ^= (1LL << (C - 97));
		// To be re-arranged as a palindrome, it must be 0 or power of two with odd length
		if (occ == 0 || __popcount(occ) & 1) // XOR != 0
			cout << "First";
		else
			cout << "Second";
	}
	return 0;
}
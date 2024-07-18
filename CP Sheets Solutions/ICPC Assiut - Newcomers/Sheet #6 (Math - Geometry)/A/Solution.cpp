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
	To be a power of two, a number must have EXACTLY 1 set bit
	we can check that using __has_single_bit()
	Or we can observe something:
	If we subtract 1 from any number, that flips all the bits until the first set bit inclusive
	  00001000
	- 00000001
	----------
	  00000111
	Thus, the AND of a power of two with its precedent number always yields a 0
	(The 0 deceives this condition, because the 0 is NOT a power of two, although it satisfies the condition)
	*/
	int t = 1;
	ll N;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		// if (__has_single_bit(N))
		if ((N & (N - 1)) == 0 && N != 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
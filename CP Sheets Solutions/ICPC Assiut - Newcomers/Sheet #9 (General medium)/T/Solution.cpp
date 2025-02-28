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
	ll N, M;
	// cin >> t;
	while (t--)
	{
		/*
		Since N <= 100 and there cannot be such a number in C++, a string-processing solution is needed.
		A number X is divisible by T iff X is a multiple of T --> X = C * T
		We choose the constant C to be 10^p because this is the easiest way to control the number of digits of X
		Since 10^p * T = "T" + "00000...(p zeros)"
		Example: 12 * 10*3 = "12" + "000" ="12000"
		Number of digits of X (Supposed to be N) = Number of digits of (T) + p

		*/
		int N, T;
		cin >> N >> T;
		int c = floor(log10(T) + 1); // Number of digits of T

		if (N < c)
			cout << -1;
		else
			cout << T << string(N - c, '0'); // Prints (N - c) zeros
	}
	return 0;
}

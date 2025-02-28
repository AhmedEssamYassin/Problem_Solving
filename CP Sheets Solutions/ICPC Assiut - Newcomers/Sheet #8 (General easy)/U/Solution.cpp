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
		cin >> N;
		if (N > 0)
			return cout << N, 0;
		int last_digit = N % 10;
		ll removingLastDigit = N / 10;
		ll removingSecondToLastDigit = N / 100 * 10 + last_digit;
		cout << max(removingLastDigit, removingSecondToLastDigit);
	}
	return 0;
}
